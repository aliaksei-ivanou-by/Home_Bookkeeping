#include "include/1_DataAccess/CurrencyDatabase.h"

CurrencyDatabase::CurrencyDatabase(DatabaseManager* database_manager)
{
  database_manager_ = database_manager;
}

void CurrencyDatabase::CreateTableCurrenciesInDatabase()
{
  database_manager_->CreateTableInDatabase("Currencies");
}

void CurrencyDatabase::ClearTableCurrenciesInDatabase()
{
  database_manager_->ClearTableInDatabase("Currencies");
}

void CurrencyDatabase::InsertCurrencyToTableCurrenciesInDatabase(Currency&& model)
{
  int counter_start = 1;
  bool model_in_database;
  std::tie(model_in_database, std::ignore, std::ignore) = FindCurrencyInTableCurrenciesInDatabase(model.GetName());
  if (model_in_database)
  {
    PLOG_ERROR << "Table 'Currencies' has this currency";
    return;
  }
  else
  {
    std::string sql_request = std::string("INSERT INTO Currencies VALUES(null, '") +
      model.GetName() + "', '" + model.GetCode() + "', " + std::to_string(model.GetActivity()) + ");";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Insert currency " << model.GetName() << " to table 'Currencies' in database";
    }
    return;
  }
}

void CurrencyDatabase::InsertCurrenciesToTableCurrenciesInDatabase(CurrencyRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertCurrencyToTableCurrenciesInDatabase(std::move(**i));
  }
}

std::tuple<bool, int, Currency> CurrencyDatabase::FindCurrencyInTableCurrenciesInDatabase(const std::string& model_name)
{
  sqlite3_prepare_v2(database_manager_->database_, "SELECT * FROM Currencies", -1, &database_manager_->database_stmt_, 0);
  while (sqlite3_step(database_manager_->database_stmt_) != SQLITE_DONE)
  {
    int model_id = (sqlite3_column_int(database_manager_->database_stmt_, 0));
    const unsigned char* model_name_char = (sqlite3_column_text(database_manager_->database_stmt_, 1));
    const unsigned char* model_code_char = (sqlite3_column_text(database_manager_->database_stmt_, 2));
    int model_activity = (sqlite3_column_int(database_manager_->database_stmt_, 3));
    if (reinterpret_cast<const char*>(model_name_char) == model_name)
    {
      Currency model((reinterpret_cast<const char*>(model_name_char)), (reinterpret_cast<const char*>(model_name_char)), model_activity);
      PLOG_INFO << "Currency with name " << model_name << " is found in table 'Currencies' in database";
      return std::make_tuple(true, model_id, model);
    }
  }
  PLOG_INFO << "Currency with name " << model_name << " isn't found in table 'Currencies' in database";
  return std::make_tuple(false, 0, Currency());
}

std::tuple<bool, int, Currency> CurrencyDatabase::FindCurrencyByCodeInTableCurrenciesInDatabase(const std::string& model_code)
{
  sqlite3_prepare_v2(database_manager_->database_, "SELECT * FROM Currencies", -1, &database_manager_->database_stmt_, 0);
  while (sqlite3_step(database_manager_->database_stmt_) != SQLITE_DONE)
  {
    int model_id = (sqlite3_column_int(database_manager_->database_stmt_, 0));
    const unsigned char* model_name_char = (sqlite3_column_text(database_manager_->database_stmt_, 1));
    const unsigned char* model_code_char = (sqlite3_column_text(database_manager_->database_stmt_, 2));
    int model_activity = (sqlite3_column_int(database_manager_->database_stmt_, 3));
    if (reinterpret_cast<const char*>(model_code_char) == model_code)
    {
      Currency model((reinterpret_cast<const char*>(model_name_char)), (reinterpret_cast<const char*>(model_code_char)), model_activity);
      PLOG_INFO << "Currency with code " << model_code << " is found in table 'Currencies' in database";
      return std::make_tuple(true, model_id, model);
    }
  }
  PLOG_INFO << "Currency with code " << model_code << " isn't found in table 'Currencies' in database";
  return std::make_tuple(false, 0, Currency());
}

void CurrencyDatabase::SetCurrencyName(const std::string& model_name, const std::string& name)
{
  bool model_is_in_table = false;
  int model_id;
  Currency model;
  std::tie(model_is_in_table, model_id, model) = FindCurrencyInTableCurrenciesInDatabase(model_name);
  if (model_is_in_table)
  {
    const std::string sql_request = std::string("UPDATE Currencies SET name = '") +
      name +
      "' WHERE id = " + std::to_string(model_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Set name (old name - '" << model_name << "') of currency '" << name << "' in table 'Currencies' in database";
    }
  }
}

void CurrencyDatabase::SetCurrencyCode(const std::string& model_name, const std::string& code)
{
  bool model_is_in_table = false;
  int model_id;
  Currency model;
  std::tie(model_is_in_table, model_id, model) = FindCurrencyInTableCurrenciesInDatabase(model_name);
  if (model_is_in_table)
  {
    const std::string sql_request = std::string("UPDATE Currencies SET code = '") +
      code +
      "' WHERE id = " + std::to_string(model_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Set code (old code - '" << model.GetCode() << "') of account '" << code << "' in table 'Currencies' in database";
    }
  }
}

void CurrencyDatabase::SetCurrencyActivity(const std::string& model_name, const bool activity)
{
  bool model_is_in_table = false;
  int model_id;
  Currency model;
  std::tie(model_is_in_table, model_id, model) = FindCurrencyInTableCurrenciesInDatabase(model_name);
  if (model_is_in_table)
  {
    const std::string sql_request = std::string("UPDATE Currencies SET activity = '") +
      std::to_string(activity) +
      "' WHERE id = " + std::to_string(model_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Set activity (old activity - '" << model.GetActivity() << "') of currency '" << activity << "' in table 'Currencies' in database";
    }
  }
}

std::string CurrencyDatabase::GetCurrencyName(const std::string& model_name)
{
  bool model_is_in_table = false;
  Currency model;
  std::tie(model_is_in_table, std::ignore, model) = FindCurrencyInTableCurrenciesInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetName();
  }
}

std::string CurrencyDatabase::GetCurrencyCode(const std::string& model_name)
{
  bool model_is_in_table = false;
  Currency model;
  std::tie(model_is_in_table, std::ignore, model) = FindCurrencyInTableCurrenciesInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetCode();
  }
}

bool CurrencyDatabase::GetCurrencyActivity(const std::string& model_name)
{
  bool model_is_in_table = false;
  Currency model;
  std::tie(model_is_in_table, std::ignore, model) = FindCurrencyInTableCurrenciesInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetActivity();
  }
}

void CurrencyDatabase::SwitchCurrencyActivity(const std::string& model_name)
{
  bool model_activity = GetCurrencyActivity(model_name);
  SetCurrencyActivity(model_name, !model_activity);
}

void CurrencyDatabase::SwitchOnCurrencyActivity(const std::string& model_name)
{
  SetCurrencyActivity(model_name, true);
}

void CurrencyDatabase::SwitchOffCurrencyActivity(const std::string& model_name)
{
  SetCurrencyActivity(model_name, false);
}

void CurrencyDatabase::RemoveCurrencyFromTableCurrenciesInDatabase(const std::string& currency_name)
{
  bool currency_is_in_table = false;
  int currency_id;
  std::tie(currency_is_in_table, currency_id, std::ignore) = FindCurrencyInTableCurrenciesInDatabase(currency_name);
  if (currency_is_in_table)
  {
    const std::string sql_request = std::string("DELETE FROM Currencies WHERE id = ") +
      std::to_string(currency_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Remove row Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Remove currency '" << currency_name << "' from table 'Currencies' in database";
    }
  }
}
