#include "include/1_DataAccess/CategoryDatabase.h"

CategoryDatabase::CategoryDatabase(DatabaseManager* database_manager)
{
  database_manager_ = database_manager;
}

void CategoryDatabase::CreateTableCategoriesInDatabase()
{
  database_manager_->CreateTableInDatabase("Categories");
}

void CategoryDatabase::ClearTableCategoriesInDatabase()
{
  database_manager_->ClearTableInDatabase("Categories");
}

void CategoryDatabase::InsertCategoryToTableCategoriesInDatabase(Category&& model)
{
  int counter_start = 1;
  bool model_in_database;
  int model_id;
  int model_counter;
  std::tie(model_in_database, model_id, std::ignore, model_counter) = FindCategoryInTableCategoriesInDatabase(model.GetName());
  if (model_in_database)
  {
    std::string sql_request = std::string("UPDATE Categories SET counter = ") + std::to_string(model_counter + 1) +
      " WHERE id = " + std::to_string(model_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Append counter for category in table 'Categories' in database";
    }
    return;
  }
  else
  {
    std::string sql_request = std::string("INSERT INTO Categories VALUES(null, '") +
      model.GetName() + "', " + std::to_string(counter_start) + ");";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Insert category to table 'Categories' in database";
    }
    return;
  }
}

void CategoryDatabase::InsertCategoriesToTableCategoriesInDatabase(CategoryRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertCategoryToTableCategoriesInDatabase(std::move(*i->first));
  }
}

std::tuple<bool, int, Category, int> CategoryDatabase::FindCategoryInTableCategoriesInDatabase(const std::string& model_name)
{
  sqlite3_prepare_v2(database_manager_->database_, "SELECT * FROM Categories", -1, &database_manager_->database_stmt_, 0);
  while (sqlite3_step(database_manager_->database_stmt_) != SQLITE_DONE)
  {
    int model_id = (sqlite3_column_int(database_manager_->database_stmt_, 0));
    const unsigned char* model_name_char = (sqlite3_column_text(database_manager_->database_stmt_, 1));
    int model_counter = (sqlite3_column_int(database_manager_->database_stmt_, 2));
    if (reinterpret_cast<const char*>(model_name_char) == model_name)
    {
      Category model((reinterpret_cast<const char*>(model_name_char)));
      PLOG_INFO << "Category with name " << model_name << " is found in table 'Categories' in database";
      return std::make_tuple(true, model_id, model, model_counter);
    }
  }
  PLOG_INFO << "Category with name " << model_name << " isn't found in table 'Categories' in database";
  return std::make_tuple(false, 0, Category(), 0);
}

void CategoryDatabase::SetCategoryName(const std::string& model_name, const std::string& name)
{
  bool model_is_in_table = false;
  int model_id;
  Category model;
  int model_counter;
  std::tie(model_is_in_table, model_id, model, model_counter) = FindCategoryInTableCategoriesInDatabase(model_name);
  if (model_is_in_table)
  {
    const std::string sql_request = std::string("UPDATE Categories SET name = '") +
      name +
      "' WHERE id = " + std::to_string(model_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Set name (old name - '" << model_name << "') of category '" << name << "' in table 'Categories' in database";
    }
  }
}

std::string CategoryDatabase::GetCategoryName(const std::string& model_name)
{
  bool model_is_in_table = false;
  Category model;
  std::tie(model_is_in_table, std::ignore, model, std::ignore) = FindCategoryInTableCategoriesInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetName();
  }
}

void CategoryDatabase::RemoveCategoryFromTableCategoriesInDatabase(const std::string& category_name)
{
  bool category_is_in_table = false;
  int category_id;
  std::tie(category_is_in_table, category_id, std::ignore, std::ignore) = FindCategoryInTableCategoriesInDatabase(category_name);
  if (category_is_in_table)
  {
    const std::string sql_request = std::string("DELETE FROM Categories WHERE id = ") +
      std::to_string(category_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Remove row Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Remove category '" << category_name << "' from table 'Categories' in database";
    }
  }
}
