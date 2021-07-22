#include "include/1_DataAccess/PayeeDatabase.h"

PayeeDatabase::PayeeDatabase(DatabaseManager* database_manager)
{
  database_manager_ = database_manager;
}

void PayeeDatabase::CreateTablePayeesInDatabase()
{
  database_manager_->CreateTableInDatabase("Payees");
}

void PayeeDatabase::ClearTablePayeesInDatabase()
{
  database_manager_->ClearTableInDatabase("Payees");
}

void PayeeDatabase::InsertPayeeToTablePayeesInDatabase(Payee&& model)
{
  int counter_start = 1;
  bool model_in_database;
  int model_id;
  int model_counter;
  std::tie(model_in_database, model_id, std::ignore, model_counter) = FindPayeeInTablePayeesInDatabase(model.GetName());
  if (model_in_database)
  {
    std::string sql_request = std::string("UPDATE Payees SET counter = ") + std::to_string(model_counter + 1) +
      " WHERE id = " + std::to_string(model_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Append counter for payee in table 'Payees' in database";
    }
    return;
  }
  else
  {
    std::string sql_request = std::string("INSERT INTO Payees VALUES(null, '") +
      model.GetName() + "', " + std::to_string(counter_start) + ");";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Insert payee to table 'Payees' in database";
    }
    return;
  }
}

void PayeeDatabase::InsertPayeesToTablePayeesInDatabase(PayeeRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertPayeeToTablePayeesInDatabase(std::move(*i->first));
  }
}

std::tuple<bool, int, Payee, int> PayeeDatabase::FindPayeeInTablePayeesInDatabase(const std::string& model_name)
{
  sqlite3_prepare_v2(database_manager_->database_, "SELECT * FROM Payees", -1, &database_manager_->database_stmt_, 0);
  while (sqlite3_step(database_manager_->database_stmt_) != SQLITE_DONE)
  {
    int model_id = (sqlite3_column_int(database_manager_->database_stmt_, 0));
    const unsigned char* model_name_char = (sqlite3_column_text(database_manager_->database_stmt_, 1));
    int model_counter = (sqlite3_column_int(database_manager_->database_stmt_, 2));
    if (reinterpret_cast<const char*>(model_name_char) == model_name)
    {
      Payee model((reinterpret_cast<const char*>(model_name_char)));
      PLOG_INFO << "Payee with name " << model_name << " is found in table 'Payees' in database";
      return std::make_tuple(true, model_id, model, model_counter);
    }
  }
  PLOG_INFO << "Payee with name " << model_name << " isn't found in table 'Payees' in database";
  return std::make_tuple(false, 0, Payee(), 0);
}

void PayeeDatabase::SetPayeeName(const std::string& model_name, const std::string& name)
{
  bool model_is_in_table = false;
  int model_id;
  Payee model;
  int model_counter;
  std::tie(model_is_in_table, model_id, model, model_counter) = FindPayeeInTablePayeesInDatabase(model_name);
  if (model_is_in_table)
  {
    const std::string sql_request = std::string("UPDATE Payees SET name = '") +
      name +
      "' WHERE id = " + std::to_string(model_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Set name ('" << model.GetName() << "' -> '" << name << "') of payee '" << model_name << "' in table 'Payees' in database";
    }
  }
}

std::string PayeeDatabase::GetPayeeName(const std::string& model_name)
{
  bool model_is_in_table = false;
  Payee model;
  std::tie(model_is_in_table, std::ignore, model, std::ignore) = FindPayeeInTablePayeesInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetName();
  }
}

void PayeeDatabase::RemovePayeeFromTablePayeesInDatabase(const std::string& payee_name)
{
  bool payee_is_in_table = false;
  int payee_id;
  std::tie(payee_is_in_table, payee_id, std::ignore, std::ignore) = FindPayeeInTablePayeesInDatabase(payee_name);
  if (payee_is_in_table)
  {
    const std::string sql_request = std::string("DELETE FROM Payees WHERE id = ") +
      std::to_string(payee_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Remove row Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Remove payee '" << payee_name << "' from table 'Payees' in database";
    }
  }
}
