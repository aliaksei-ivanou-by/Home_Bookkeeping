#include "include/1_DataAccess/AccountDatabase.h"

AccountDatabase::AccountDatabase(DatabaseManager* database_manager, CurrencyDatabase* currency_database)
{
  database_manager_ = database_manager;
  currency_database_ = currency_database;
}

void AccountDatabase::CreateTableAccountsInDatabase()
{
  database_manager_->CreateTableInDatabase("Accounts");
}

void AccountDatabase::ClearTableAccountsInDatabase()
{
  database_manager_->ClearTableInDatabase("Accounts");
}

void AccountDatabase::InsertAccountToTableAccountsInDatabase(Account&& model)
{
  bool model_currency_in_database = false;
  int model_currency_id;
  std::tie(model_currency_in_database, model_currency_id, std::ignore) = currency_database_->FindCurrencyInTableCurrenciesInDatabase(model.GetCurrency().GetName());
  if (!model_currency_in_database)
  {
    currency_database_->InsertCurrencyToTableCurrenciesInDatabase(model.GetCurrency());
    std::tie(model_currency_in_database, model_currency_id, std::ignore) = currency_database_->FindCurrencyInTableCurrenciesInDatabase(model.GetCurrency().GetName());
  }

  int counter_start = 1;
  bool model_in_database;
  int model_id;
  std::tie(model_in_database, model_id, std::ignore) = FindAccountInTableAccountsInDatabase(model.GetName());
  if (model_in_database)
  {
    PLOG_ERROR << "Table 'Account' has this account";
    return;
  }
  else
  {
    std::string sql_request = std::string("INSERT INTO Accounts VALUES(null, '") +
      model.GetName() + "', " +
      std::to_string(model.GetAmount()) + ", " +
      std::to_string(model_currency_id) + ");";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Insert account '" << model.GetName() << "' to table 'Accounts' in database";
    }
    return;
  }
}

void AccountDatabase::InsertAccountsToTableAccountsInDatabase(AccountRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertAccountToTableAccountsInDatabase(std::move(**i));
  }
}

std::tuple<bool, int, Account> AccountDatabase::FindAccountInTableAccountsInDatabase(const std::string& model_name)
{
  sqlite3_prepare_v2(database_manager_->database_, "SELECT * FROM Accounts", -1, &database_manager_->database_stmt_, 0);
  while (sqlite3_step(database_manager_->database_stmt_) != SQLITE_DONE)
  {
    int model_id = (sqlite3_column_int(database_manager_->database_stmt_, 0));
    const unsigned char* model_name_char = (sqlite3_column_text(database_manager_->database_stmt_, 1));
    double model_amount = (sqlite3_column_double(database_manager_->database_stmt_, 2));
    int model_currency = (sqlite3_column_int(database_manager_->database_stmt_, 3));
    if (reinterpret_cast<const char*>(model_name_char) == model_name)
    {
      std::string sql_request = std::string("SELECT * FROM Currencies WHERE id = ") + std::to_string(model_currency) + ";";
      sqlite3_prepare_v2(database_manager_->database_, sql_request.c_str(), -1, &database_manager_->database_stmt_, 0);
      const unsigned char* currency_name = nullptr;
      const unsigned char* currency_code = nullptr;
      int currency_activity;
      while (sqlite3_step(database_manager_->database_stmt_) != SQLITE_DONE)
      {
        currency_name = (sqlite3_column_text(database_manager_->database_stmt_, 1));
        currency_code = (sqlite3_column_text(database_manager_->database_stmt_, 2));
        currency_activity = (sqlite3_column_int(database_manager_->database_stmt_, 3));
        break;
      }
      Currency currency((reinterpret_cast<const char*>(currency_name)), (reinterpret_cast<const char*>(currency_code)), currency_activity);
      Account model((reinterpret_cast<const char*>(model_name_char)), model_amount, currency);
      PLOG_INFO << "Account with name '" << model_name << "' is found in table 'Accounts' in database";
      return std::make_tuple(true, model_id, model);
    }
  }
  PLOG_INFO << "Account with name '" << model_name << "' isn't found in table 'Accounts' in database";
  return std::make_tuple(false, 0, Account());
}

void AccountDatabase::SetAccountName(const std::string& model_name, const std::string& name)
{
  bool model_is_in_table = false;
  int model_id;
  Account model;
  std::tie(model_is_in_table, model_id, model) = FindAccountInTableAccountsInDatabase(model_name);
  if (model_is_in_table)
  {
    const std::string sql_request = std::string("UPDATE Accounts SET name = '") +
      name +
      "' WHERE id = " + std::to_string(model_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Set name (old name - '" << model_name << "') of account '" << name << "' in table 'Accounts' in database";
    }
  }
}

void AccountDatabase::SetAccountAmount(const std::string& model_name, const NUM amount)
{
  bool model_is_in_table = false;
  int model_id;
  Account model;
  std::tie(model_is_in_table, model_id, model) = FindAccountInTableAccountsInDatabase(model_name);
  if (model_is_in_table)
  {
    const std::string sql_request = std::string("UPDATE Accounts SET amount = ") +
      std::to_string(amount) +
      " WHERE id = " + std::to_string(model_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Set amount ('" << model.GetAmount() << "' -> '" << amount << "') of account '" << model_name << "' in table 'Accounts' in database";
    }
  }
}

void AccountDatabase::SetAccountCurrency(const std::string& model_name, Currency&& currency)
{
  bool currency_is_in_table = false;
  int currency_id;
  Currency currency_in_table;
  std::tie(currency_is_in_table, currency_id, currency_in_table) = currency_database_->FindCurrencyInTableCurrenciesInDatabase(currency.GetName());
  if (!currency_is_in_table)
  {
    currency_database_->InsertCurrencyToTableCurrenciesInDatabase(std::move(currency));
    std::tie(currency_is_in_table, currency_id, currency_in_table) = currency_database_->FindCurrencyInTableCurrenciesInDatabase(currency.GetName());
  }
  bool model_is_in_table = false;
  int model_id;
  Account model;
  std::tie(model_is_in_table, model_id, model) = FindAccountInTableAccountsInDatabase(model_name);
  if (model_is_in_table)
  {
    const std::string sql_request = std::string("UPDATE Accounts SET currency = ") +
      std::to_string(currency_id) +
      " WHERE id = " + std::to_string(model_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Set currency ('" << model.GetCurrency() << "' -> '" << currency << "') of account '" << model_name << "' in table 'Accounts' in database";
    }
  }
}

std::string AccountDatabase::GetAccountName(const std::string& model_name)
{
  bool model_is_in_table = false;
  Account model;
  std::tie(model_is_in_table, std::ignore, model) = FindAccountInTableAccountsInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetName();
  }
}

NUM AccountDatabase::GetAccountAmount(const std::string& model_name)
{
  bool model_is_in_table = false;
  Account model;
  std::tie(model_is_in_table, std::ignore, model) = FindAccountInTableAccountsInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetAmount();
  }
}

Currency AccountDatabase::GetAccountCurrency(const std::string& model_name)
{
  bool model_is_in_table = false;
  Account model;
  std::tie(model_is_in_table, std::ignore, model) = FindAccountInTableAccountsInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetCurrency();
  }
}

void AccountDatabase::RemoveAccountFromTableAccountsInDatabase(const std::string& account_name)
{
  bool account_is_in_table = false;
  int account_id;
  Account model;
  std::tie(account_is_in_table, account_id, std::ignore) = FindAccountInTableAccountsInDatabase(account_name);
  if (account_is_in_table)
  {
    const std::string sql_request = std::string("DELETE FROM Accounts WHERE id = ") +
      std::to_string(account_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Remove row Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Remove account '" << account_name << "' from table 'Accounts' in database";
    }
  }
}
