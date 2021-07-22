#include "include/1_DataAccess/DescriptionDatabase.h"

DescriptionDatabase::DescriptionDatabase(DatabaseManager* database_manager)
{
  database_manager_ = database_manager;
}

void DescriptionDatabase::CreateTableDescriptionsInDatabase()
{
  database_manager_->CreateTableInDatabase("Descriptions");
}

void DescriptionDatabase::ClearTableDescriptionsInDatabase()
{
  database_manager_->ClearTableInDatabase("Descriptions");
}

void DescriptionDatabase::InsertDescriptionToTableDescriptionsInDatabase(Description&& model)
{
  int counter_start = 1;
  bool model_in_database;
  int model_id;
  int model_counter;
  std::tie(model_in_database, model_id, std::ignore, model_counter) = FindDescriptionInTableDescriptionsInDatabase(model.GetName());
  if (model_in_database)
  {
    std::string sql_request = std::string("UPDATE Descriptions SET counter = ") + std::to_string(model_counter + 1) +
      " WHERE id = " + std::to_string(model_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Append counter for description in table 'Descriptions' in database";
    }
    return;
  }
  else
  {
    std::string sql_request = std::string("INSERT INTO Descriptions VALUES(null, '") +
      model.GetName() + "', " + std::to_string(counter_start) + ");";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Insert description to table 'Descriptions' in database";
    }
    return;
  }
}

void DescriptionDatabase::InsertDescriptionsToTableDescriptionsInDatabase(DescriptionRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertDescriptionToTableDescriptionsInDatabase(std::move(*i->first));
  }
}

std::tuple<bool, int, Description, int> DescriptionDatabase::FindDescriptionInTableDescriptionsInDatabase(const std::string& model_name)
{
  sqlite3_prepare_v2(database_manager_->database_, "SELECT * FROM Descriptions", -1, &database_manager_->database_stmt_, 0);
  while (sqlite3_step(database_manager_->database_stmt_) != SQLITE_DONE)
  {
    int model_id = (sqlite3_column_int(database_manager_->database_stmt_, 0));
    const unsigned char* model_name_char = (sqlite3_column_text(database_manager_->database_stmt_, 1));
    int model_counter = (sqlite3_column_int(database_manager_->database_stmt_, 2));
    if (reinterpret_cast<const char*>(model_name_char) == model_name)
    {
      Description model((reinterpret_cast<const char*>(model_name_char)));
      PLOG_INFO << "Description with name " << model_name << " is found in table 'Descriptions' in database";
      return std::make_tuple(true, model_id, model, model_counter);
    }
  }
  PLOG_INFO << "Description with name " << model_name << " isn't found in table 'Descriptions' in database";
  return std::make_tuple(false, 0, Description(), 0);
}

void DescriptionDatabase::SetDescriptionName(const std::string& model_name, const std::string& name)
{
  bool model_is_in_table = false;
  int model_id;
  Description model;
  int model_counter;
  std::tie(model_is_in_table, model_id, model, model_counter) = FindDescriptionInTableDescriptionsInDatabase(model_name);
  std::string model_old_name = model.GetName();
  if (model_is_in_table)
  {
    const std::string sql_request = std::string("UPDATE Descriptions SET name = '") +
      name +
      "' WHERE id = " + std::to_string(model_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Set name ('" << model_old_name << "' -> '" << name << "') of description '" << model_name << "' in table 'Descriptions' in database";
    }
  }
}

std::string DescriptionDatabase::GetDescriptionName(const std::string& model_name)
{
  bool model_is_in_table = false;
  Description model;
  std::tie(model_is_in_table, std::ignore, model, std::ignore) = FindDescriptionInTableDescriptionsInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetName();
  }
}

void DescriptionDatabase::RemoveDescriptionFromTableDescriptionsInDatabase(const std::string& description_name)
{
  bool description_is_in_table = false;
  int description_id;
  std::tie(description_is_in_table, description_id, std::ignore, std::ignore) = FindDescriptionInTableDescriptionsInDatabase(description_name);
  if (description_is_in_table)
  {
    const std::string sql_request = std::string("DELETE FROM Descriptions WHERE id = ") +
      std::to_string(description_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Remove row Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Remove description '" << description_name << "' from table 'Descriptions' in database";
    }
  }
}
