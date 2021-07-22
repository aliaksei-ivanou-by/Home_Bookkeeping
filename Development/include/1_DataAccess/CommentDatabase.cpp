#include "include/1_DataAccess/CommentDatabase.h"

CommentDatabase::CommentDatabase(DatabaseManager* database_manager)
{
  database_manager_ = database_manager;
}

void CommentDatabase::CreateTableCommentsInDatabase()
{
  database_manager_->CreateTableInDatabase("Comments");
}

void CommentDatabase::ClearTableCommentsInDatabase()
{
  database_manager_->ClearTableInDatabase("Comments");
}

void CommentDatabase::InsertCommentToTableCommentsInDatabase(Comment&& model)
{
  int counter_start = 1;
  bool model_in_database;
  int model_id;
  int model_counter;
  std::tie(model_in_database, model_id, std::ignore, model_counter) = FindCommentInTableCommentsInDatabase(model.GetName());
  if (model_in_database)
  {
    std::string sql_request = std::string("UPDATE Comments SET counter = ") + std::to_string(model_counter + 1) +
      " WHERE id = " + std::to_string(model_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Append counter for comment in table 'Comments' in database";
    }
    return;
  }
  else
  {
    std::string sql_request = std::string("INSERT INTO Comments VALUES(null, '") +
      model.GetName() + "', " + std::to_string(counter_start) + ");";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Insert comment to table 'Comments' in database";
    }
    return;
  }
}

void CommentDatabase::InsertCommentsToTableCommentsInDatabase(CommentRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertCommentToTableCommentsInDatabase(std::move(*i->first));
  }
}

std::tuple<bool, int, Comment, int> CommentDatabase::FindCommentInTableCommentsInDatabase(const std::string& model_name)
{
  sqlite3_prepare_v2(database_manager_->database_, "SELECT * FROM Comments", -1, &database_manager_->database_stmt_, 0);
  while (sqlite3_step(database_manager_->database_stmt_) != SQLITE_DONE)
  {
    int model_id = (sqlite3_column_int(database_manager_->database_stmt_, 0));
    const unsigned char* model_name_char = (sqlite3_column_text(database_manager_->database_stmt_, 1));
    int model_counter = (sqlite3_column_int(database_manager_->database_stmt_, 2));
    if (reinterpret_cast<const char*>(model_name_char) == model_name)
    {
      Comment comment((reinterpret_cast<const char*>(model_name_char)));
      PLOG_INFO << "Comment with name " << model_name << " is found in table 'Comments' in database";
      return std::make_tuple(true, model_id, comment, model_counter);
    }
  }
  PLOG_INFO << "Comment with name " << model_name << " isn't found in table 'Comments' in database";
  return std::make_tuple(false, 0, Comment(), 0);
}

void CommentDatabase::SetCommentName(const std::string& model_name, const std::string& name)
{
  bool model_is_in_table = false;
  int model_id;
  Comment model;
  int model_counter;
  std::tie(model_is_in_table, model_id, model, model_counter) = FindCommentInTableCommentsInDatabase(model_name);
  if (model_is_in_table)
  {
    const std::string sql_request = std::string("UPDATE Comments SET name = '") +
      name +
      "' WHERE id = " + std::to_string(model_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Set name ('" << model.GetName() << "' -> '" << name << "') of comment '" << model_name << "' in table 'Comments' in database";
    }
  }
}

std::string CommentDatabase::GetCommentName(const std::string& model_name)
{
  bool model_is_in_table = false;
  Comment model;
  std::tie(model_is_in_table, std::ignore, model, std::ignore) = FindCommentInTableCommentsInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetName();
  }
}

void CommentDatabase::RemoveCommentFromTableCommentsInDatabase(const std::string& comment_name)
{
  bool comment_is_in_table = false;
  int comment_id;
  std::tie(comment_is_in_table, comment_id, std::ignore, std::ignore) = FindCommentInTableCommentsInDatabase(comment_name);
  if (comment_is_in_table)
  {
    const std::string sql_request = std::string("DELETE FROM Comments WHERE id = ") +
      std::to_string(comment_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Remove row Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Remove comment '" << comment_name << "' from table 'Comments' in database";
    }
  }
}
