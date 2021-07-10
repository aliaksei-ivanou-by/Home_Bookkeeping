#include "include/2_BusinessLogic/DatabaseManager.h"

//  Constructor
//  Default
DatabaseManager::DatabaseManager():
  database_error_{ 0 },
  database_status_{ 0 },
  database_{ nullptr },
  database_stmt_{ nullptr }
{
  sqlite3_open("database.db", &database_);
  PLOG_INFO << "Open database";
  CreateAllTablesInDatabase();
}

//  Destructor
//  Default
DatabaseManager::~DatabaseManager()
{
  sqlite3_close(database_);
  PLOG_INFO << "Close database";
}

//  Not class member function
//  Additional function for calculate rows with data in table in database
static int callback(void* count, int argc, char** argv, char** azColName)
{
  int* c = (int*)count;
  *c = atoi(argv[0]);
  return 0;
}

//  Class member function
//  Calculate rows with data in table in database
int DatabaseManager::SizeOfTable(const std::string& table)
{
  int table_rows = 0;
  if (CheckTableForExistenceInDatabase(table))
  {
    const std::string sql_request = "SELECT COUNT(*) FROM " + table;
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), callback, &table_rows, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Error: " << database_error_;
    }
  }
  return table_rows;
}

//  Class member function
//  Check table for existence in database
bool DatabaseManager::CheckTableForExistenceInDatabase(const std::string& table)
{
  std::string sql_request = std::string("SELECT COUNT(*) FROM sqlite_master WHERE type='table' AND name='") + 
    table + "';";
  sqlite3_prepare_v2(database_, sql_request.c_str(), -1, &database_stmt_, 0);
  bool table_availability = false;
  while (sqlite3_step(database_stmt_) != SQLITE_DONE)
  {
    table_availability = (sqlite3_column_int(database_stmt_, 0)) == 0 ? false : true;
  }
  return table_availability;
}

//  Class member function
//  Create table in database
void DatabaseManager::CreateTableInDatabase(const std::string& table)
{
  if (!CheckTableForExistenceInDatabase(table))
  {
    std::string sql_request;
    if (table == "Categories" ||
      table == "Descriptions" ||
      table == "Payees" ||
      table == "Comments" ||
      table == "Tags")
    {
      sql_request = std::string("CREATE TABLE " + table + "(") +
        "id INTEGER PRIMARY KEY AUTOINCREMENT, " + 
        "name TEXT NOT NULL, " +
        "counter INTEGER NOT NULL" +
        ");";
    }
    if (table == "Transactions")
    {
      sql_request = std::string("CREATE TABLE Transactions(") +
        "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
        "time TEXT NOT NULL, " +
        "account_from INTEGER NOT NULL, " +
        "account_to INTEGER NOT NULL, " +
        "category INTEGER NOT NULL, " +
        "amount DOUBLE NOT NULL, " +
        "amount_account_from DOUBLE NOT NULL, " +
        "amount_acount_to DOUBLE NOT NULL, " +
        "comment INTEGER NOT NULL, " +
        "currency INTEGER NOT NULL, " +
        "description INTEGER NOT NULL, " +
        "payee INTEGER NOT NULL, " +
        "tag INTEGER NOT NULL, " +
        "status TEXT NOT NULL, " +
        "type TEXT NOT NULL, " +
        "CONSTRAINT fk_account_from FOREIGN KEY (account_from) REFERENCES Accounts(id), " +
        "CONSTRAINT fk_account_to FOREIGN KEY (account_to) REFERENCES Accounts(id)" +
        "CONSTRAINT fk_category FOREIGN KEY (category) REFERENCES Categories(id)" +
        "CONSTRAINT fk_comment FOREIGN KEY (comment) REFERENCES Comments(id)" +
        "CONSTRAINT fk_currency FOREIGN KEY (currency) REFERENCES Currencies(id)" +
        "CONSTRAINT fk_description FOREIGN KEY (description) REFERENCES Descriptions(id)" +
        "CONSTRAINT fk_payee FOREIGN KEY (payee) REFERENCES Payees(id)" +
        "CONSTRAINT fk_tag FOREIGN KEY (tag) REFERENCES Tags(id)" +
        ");";
    }
    if (table == "Accounts")
    {
      sql_request = std::string("CREATE TABLE Accounts(") +
        "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
        "name TEXT NOT NULL" + ", " +
        "amount DOUBLE NOT NULL" + ", " +
        "currency INTEGER NOT NULL" + ", " +
        "CONSTRAINT fk_currency FOREIGN KEY (currency) REFERENCES Currencies(id)" +
        ");";
    }
    if (table == "Currencies")
    {
      sql_request = std::string("CREATE TABLE Currencies(") +
        "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
        "name TEXT NOT NULL, " +
        "code TEXT NOT NULL, " +
        "activity BOOL NOT NULL" + 
        ");";
    }
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Create table '" << table << "' in database";
    }
  }
}

//  Class member function
//  Clear table in database
void DatabaseManager::ClearTableInDatabase(const std::string& table)
{
  if (CheckTableForExistenceInDatabase(table))
  {
    const std::string sql_request = std::string("DELETE FROM ") + table + ";";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Clear table '" << table << "' in database";
    }
  }
}

//  Class member function
//  Create all tables in database
void DatabaseManager::CreateAllTablesInDatabase()
{
  CreateTableAccountsInDatabase();
  CreateTableCategoriesInDatabase();
  CreateTableCurrenciesInDatabase();
  CreateTableDescriptionsInDatabase();
  CreateTablePayeesInDatabase();
  CreateTableCommentsInDatabase();
  CreateTableTagsInDatabase();
  CreateTableTransactionsInDatabase();
}

//  Class member function
//  Clear all tables in database
void DatabaseManager::ClearAllTablesInDatabase()
{
  ClearTableAccountsInDatabase();
  ClearTableCategoriesInDatabase();
  ClearTableCurrenciesInDatabase();
  ClearTableDescriptionsInDatabase();
  ClearTablePayeesInDatabase();
  ClearTableCommentsInDatabase();
  ClearTableTagsInDatabase();
  ClearTableTransactionsInDatabase();
}

//  Class member function
//  Create table 'Transactions' in database
void DatabaseManager::CreateTableTransactionsInDatabase()
{
  CreateTableInDatabase("Transactions");
}

//  Class member function
//  Clear table 'Transactions' in database
void DatabaseManager::ClearTableTransactionsInDatabase()
{
  ClearTableInDatabase("Transactions");
}

//  Class member function
//  Insert transaction to table 'Transactions' in database
void DatabaseManager::InsertTransactionToTableTransactionsInDatabase(Transaction&& transaction)
{
  // Check account_from
  bool transaction_account_from_in_database;
  int transaction_account_from_id;
  std::tie(transaction_account_from_in_database, transaction_account_from_id, std::ignore) = FindAccountInTableAccountsInDatabase(transaction.GetAccountFrom().GetName());
  if (!transaction_account_from_in_database)
  {
    InsertAccountToTableAccountsInDatabase(transaction.GetAccountFrom());
    std::tie(transaction_account_from_in_database, transaction_account_from_id, std::ignore) = FindAccountInTableAccountsInDatabase(transaction.GetAccountFrom().GetName());
  }
  // Check account_to
  bool transaction_account_to_in_database;
  int transaction_account_to_id;
  std::tie(transaction_account_to_in_database, transaction_account_to_id, std::ignore) = FindAccountInTableAccountsInDatabase(transaction.GetAccountTo().GetName());
  if (!transaction_account_to_in_database)
  {
    InsertAccountToTableAccountsInDatabase(transaction.GetAccountTo());
    std::tie(transaction_account_to_in_database, transaction_account_to_id, std::ignore) = FindAccountInTableAccountsInDatabase(transaction.GetAccountTo().GetName());
  }
  // Check category
  bool transaction_category_in_database;
  int transaction_category_id;
  std::tie(transaction_category_in_database, transaction_category_id, std::ignore, std::ignore) = FindCategoryInTableCategoriesInDatabase(transaction.GetCategory().GetName());
  if (!transaction_category_in_database)
  {
    InsertCategoryToTableCategoriesInDatabase(transaction.GetCategory());
    std::tie(transaction_category_in_database, transaction_category_id, std::ignore, std::ignore) = FindCategoryInTableCategoriesInDatabase(transaction.GetCategory().GetName());
  }
  // Check comment
  bool transaction_comment_in_database;
  int transaction_comment_id;
  std::tie(transaction_comment_in_database, transaction_comment_id, std::ignore, std::ignore) = FindCommentInTableCommentsInDatabase(transaction.GetComment().GetName());
  if (!transaction_category_in_database)
  {
    InsertCommentToTableCommentsInDatabase(transaction.GetComment());
    std::tie(transaction_comment_in_database, transaction_comment_id, std::ignore, std::ignore) = FindCommentInTableCommentsInDatabase(transaction.GetComment().GetName());
  }
  // Check currency
  bool transaction_currency_in_database;
  int transaction_currency_id;
  std::tie(transaction_currency_in_database, transaction_currency_id, std::ignore) = FindCurrencyInTableCurrenciesInDatabase(transaction.GetCurrency().GetName());
  if (!transaction_category_in_database)
  {
    InsertCurrencyToTableCurrenciesInDatabase(transaction.GetCurrency());
    std::tie(transaction_currency_in_database, transaction_currency_id, std::ignore) = FindCurrencyInTableCurrenciesInDatabase(transaction.GetCurrency().GetName());
  }
  // Check description
  bool transaction_description_in_database;
  int transaction_description_id;
  std::tie(transaction_description_in_database, transaction_description_id, std::ignore, std::ignore) = FindDescriptionInTableDescriptionsInDatabase(transaction.GetDescription().GetName());
  if (!transaction_description_in_database)
  {
    InsertDescriptionToTableDescriptionsInDatabase(transaction.GetDescription());
    std::tie(transaction_description_in_database, transaction_description_id, std::ignore, std::ignore) = FindDescriptionInTableDescriptionsInDatabase(transaction.GetDescription().GetName());
  }
  // Check payee
  bool transaction_payee_in_database;
  int transaction_payee_id;
  std::tie(transaction_payee_in_database, transaction_payee_id, std::ignore, std::ignore) = FindPayeeInTablePayeesInDatabase(transaction.GetPayee().GetName());
  if (!transaction_payee_in_database)
  {
    InsertPayeeToTablePayeesInDatabase(transaction.GetPayee());
    std::tie(transaction_payee_in_database, transaction_payee_id, std::ignore, std::ignore) = FindPayeeInTablePayeesInDatabase(transaction.GetPayee().GetName());
  }
  // Check tag
  bool transaction_tag_in_database;
  int transaction_tag_id;
  std::tie(transaction_tag_in_database, transaction_tag_id, std::ignore, std::ignore) = FindTagInTableTagsInDatabase(transaction.GetTag().GetName());
  if (!transaction_tag_in_database)
  {
    InsertTagToTableTagsInDatabase(transaction.GetTag());
    std::tie(transaction_tag_in_database, transaction_tag_id, std::ignore, std::ignore) = FindTagInTableTagsInDatabase(transaction.GetTag().GetName());
  }
  // Check amount_account_from and amount_account_to
  NUM transaction_amount_account_from;
  NUM transaction_amount_account_to;
  if (transaction.GetType() == kEnumType::Expense)
  {
    transaction_amount_account_from = GetAccountAmount(transaction.GetAccountFrom().GetName()) - transaction.GetAmount();
    transaction_amount_account_to = GetAccountAmount(transaction.GetAccountTo().GetName()) - transaction.GetAmount();
    transaction.SetAmountAccountFrom(transaction_amount_account_from);
    transaction.SetAmountAccountTo(transaction_amount_account_to);
    SetAccountAmount(transaction.GetAccountFrom().GetName(), transaction_amount_account_from);
    SetAccountAmount(transaction.GetAccountTo().GetName(), transaction_amount_account_to);
  }
  if (transaction.GetType() == kEnumType::Income)
  {
    transaction_amount_account_from = GetAccountAmount(transaction.GetAccountFrom().GetName()) + transaction.GetAmount();
    transaction_amount_account_to = GetAccountAmount(transaction.GetAccountTo().GetName()) + transaction.GetAmount();
    transaction.SetAmountAccountFrom(transaction_amount_account_from);
    transaction.SetAmountAccountTo(transaction_amount_account_to);
    SetAccountAmount(transaction.GetAccountFrom().GetName(), transaction_amount_account_from);
    SetAccountAmount(transaction.GetAccountTo().GetName(), transaction_amount_account_to);
  }
  if (transaction.GetType() == kEnumType::Transfer)
  {
    transaction_amount_account_from = GetAccountAmount(transaction.GetAccountFrom().GetName()) - transaction.GetAmount();
    transaction_amount_account_to = GetAccountAmount(transaction.GetAccountTo().GetName()) + transaction.GetAmount();
    transaction.SetAmountAccountFrom(transaction_amount_account_from);
    transaction.SetAmountAccountTo(transaction_amount_account_to);
    SetAccountAmount(transaction.GetAccountFrom().GetName(), transaction_amount_account_from);
    SetAccountAmount(transaction.GetAccountTo().GetName(), transaction_amount_account_to);
  }
 
  int transaction_status;
  int transaction_type;

  const std::string sql_request = std::string("INSERT INTO Transactions VALUES(") +
    "null, '" +
    transaction.GetTime().GetStringTime() + "', " +
    std::to_string(transaction_account_from_id) + ", " +
    std::to_string(transaction_account_to_id) + ", " +
    std::to_string(transaction_category_id) + ", " +
    std::to_string(transaction.GetAmount()) + ", " +
    std::to_string(transaction_amount_account_from) + ", " +
    std::to_string(transaction_amount_account_to) + ", " +
    std::to_string(transaction_comment_id) + ", " +
    std::to_string(transaction_currency_id) + ", " +
    std::to_string(transaction_description_id) + ", " +
    std::to_string(transaction_payee_id) + ", " +
    std::to_string(transaction_tag_id) + ", '" +
    std::to_string(0) + "', '" +
    std::to_string(0) + "');";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Insert Error: " << database_error_;
  }
  else
  {
    PLOG_INFO << "Insert transaction to table 'Transactions' in database";
  }
}

//  Class member function
//  Insert transactions to table 'Transactions' in database
void DatabaseManager::InsertTransactionsToTableTransactionsInDatabase(TransactionRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertTransactionToTableTransactionsInDatabase(std::move(**i));
  }
}

//  Class member function
//  Find transaction with definite id in table 'Transactions' in database
std::tuple<bool, int, Transaction> DatabaseManager::FindTransactionInTableTransactionsInDatabase(const int id)
{
  return std::make_tuple(false, 0, Transaction(Account(), Category(), 0));
  /*
  sqlite3_prepare_v2(database_, "SELECT * FROM Transactions", -1, &database_stmt_, 0);
  while (sqlite3_step(database_stmt_) != SQLITE_DONE)
  {
    int transaction_id = (sqlite3_column_int(database_stmt_, 0));
    const unsigned char* account_name = (sqlite3_column_text(database_stmt_, 1));
    double account_amount = (sqlite3_column_double(database_stmt_, 2));
    int account_currency = (sqlite3_column_int(database_stmt_, 3));
    if (reinterpret_cast<const char*>(account_name) == name)
    {
      std::string sql_request = std::string("SELECT * FROM Currencies WHERE id = ") + std::to_string(account_currency) + ";";
      sqlite3_prepare_v2(database_, sql_request.c_str(), -1, &database_stmt_, 0);
      const unsigned char* currency_name = nullptr;
      const unsigned char* currency_code = nullptr;
      int currency_activity;
      while (sqlite3_step(database_stmt_) != SQLITE_DONE)
      {
        currency_name = (sqlite3_column_text(database_stmt_, 1));
        currency_code = (sqlite3_column_text(database_stmt_, 2));
        currency_activity = (sqlite3_column_int(database_stmt_, 3));
        break;
      }
      Currency currency((reinterpret_cast<const char*>(currency_name)), (reinterpret_cast<const char*>(currency_code)), currency_activity);
      Account account((reinterpret_cast<const char*>(account_name)), account_amount, currency);
      PLOG_INFO << "Account with name " << name << " is found in table 'Accounts' in database";
      return std::make_tuple(true, account_id, account);
    }
  }
  PLOG_INFO << "Account with name " << name << " isn't found in table 'Accounts' in database";
  return std::make_tuple(false, 0, Account());
  */
}

//  Class member function
//  Remove transaction with definite id from table 'Transactions' in database
void DatabaseManager::RemoveTransactionFromTableTransactionsInDatabase(const int id)
{
  bool transaction_is_in_table = false;
  int transaction_id = 0;
  //std::tie(transaction_is_in_table, transaction_id, std::ignore) = FindTransactionInTableTransactionsInDatabase(id);
  if (transaction_is_in_table)
  {
    const std::string sql_request = std::string("DELETE FROM Transactions WHERE id = ") +
      std::to_string(transaction_id) + ";";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Remove row Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Remove transaction with id = " << transaction_id << " from table 'Transactions' in database";
    }
  }
}

//  Class member function
//  Create table 'Accounts' in database
void DatabaseManager::CreateTableAccountsInDatabase()
{
  CreateTableInDatabase("Accounts");
}

//  Class member function
//  Clear table 'Accounts' in database
void DatabaseManager::ClearTableAccountsInDatabase()
{
  ClearTableInDatabase("Accounts");
}

//  Class member function
//  Insert account to table 'Accounts' in database
void DatabaseManager::InsertAccountToTableAccountsInDatabase(Account&& model)
{
  bool model_currency_in_database;
  int model_currency_id;
  std::tie(model_currency_in_database, model_currency_id, std::ignore) = FindCurrencyInTableCurrenciesInDatabase(model.GetCurrency().GetName());
  if (!model_currency_in_database)
  {
    InsertCurrencyToTableCurrenciesInDatabase(model.GetCurrency());
    std::tie(model_currency_in_database, model_currency_id, std::ignore) = FindCurrencyInTableCurrenciesInDatabase(model.GetCurrency().GetName());
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Insert account '" << model.GetName() << "' to table 'Accounts' in database";
    }
    return;
  }
}

//  Class member function
//  Insert accounts to table 'Accounts' in database
void DatabaseManager::InsertAccountsToTableAccountsInDatabase(AccountRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertAccountToTableAccountsInDatabase(std::move(**i));
  }
}

//  Class member function
//  Find account with definite name in table 'Accounts' in database
std::tuple<bool, int, Account> DatabaseManager::FindAccountInTableAccountsInDatabase(const std::string& model_name)
{
  sqlite3_prepare_v2(database_, "SELECT * FROM Accounts", -1, &database_stmt_, 0);
  while (sqlite3_step(database_stmt_) != SQLITE_DONE)
  {
    int model_id = (sqlite3_column_int(database_stmt_, 0));
    const unsigned char* model_name_char = (sqlite3_column_text(database_stmt_, 1));
    double model_amount = (sqlite3_column_double(database_stmt_, 2));
    int model_currency = (sqlite3_column_int(database_stmt_, 3));
    if (reinterpret_cast<const char*>(model_name_char) == model_name)
    {
      std::string sql_request = std::string("SELECT * FROM Currencies WHERE id = ") + std::to_string(model_currency) + ";";
      sqlite3_prepare_v2(database_, sql_request.c_str(), -1, &database_stmt_, 0);
      const unsigned char* currency_name = nullptr;
      const unsigned char* currency_code = nullptr;
      int currency_activity;
      while (sqlite3_step(database_stmt_) != SQLITE_DONE)
      {
        currency_name = (sqlite3_column_text(database_stmt_, 1));
        currency_code = (sqlite3_column_text(database_stmt_, 2));
        currency_activity = (sqlite3_column_int(database_stmt_, 3));
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

//  Class member function
//  Set name of account in table 'Accounts' in database
void DatabaseManager::SetAccountName(const std::string & model_name, const std::string & name)
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Set name (old name - '" << model_name << "') of account '" << name << "' in table 'Accounts' in database";
    }
  }
}

//  Class member function
//  Set amount of account in table 'Accounts' in database
void DatabaseManager::SetAccountAmount(const std::string& model_name, const NUM amount)
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Set amount ('" << model.GetAmount() << "' -> '" << amount << "') of account '" << model_name << "' in table 'Accounts' in database";
    }
  }
}

//  Class member function
//  Set currency of account in table 'Accounts' in database
void DatabaseManager::SetAccountCurrency(const std::string& model_name, Currency&& currency)
{
  bool currency_is_in_table = false;
  int currency_id;
  Currency currency_in_table;
  std::tie(currency_is_in_table, currency_id, currency_in_table) = FindCurrencyInTableCurrenciesInDatabase(currency.GetName());
  if (!currency_is_in_table)
  {
    InsertCurrencyToTableCurrenciesInDatabase(std::move(currency));
    std::tie(currency_is_in_table, currency_id, currency_in_table) = FindCurrencyInTableCurrenciesInDatabase(currency.GetName());
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Set currency ('" << model.GetCurrency() << "' -> '" << currency << "') of account '" << model_name << "' in table 'Accounts' in database";
    }
  }
}

//  Class member function
//  Get name of account from table 'Accounts' in database
std::string DatabaseManager::GetAccountName(const std::string& model_name)
{
  bool model_is_in_table = false;
  Account model;
  std::tie(model_is_in_table, std::ignore, model) = FindAccountInTableAccountsInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetName();
  }
}

//  Class member function
//  Get amount of account from table 'Accounts' in database
NUM DatabaseManager::GetAccountAmount(const std::string& model_name)
{
  bool model_is_in_table = false;
  Account model;
  std::tie(model_is_in_table, std::ignore, model) = FindAccountInTableAccountsInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetAmount();
  }
}

//  Class member function
//  Get currency of account from table 'Accounts' in database
Currency DatabaseManager::GetAccountCurrency(const std::string& model_name)
{
  bool model_is_in_table = false;
  Account model;
  std::tie(model_is_in_table, std::ignore, model) = FindAccountInTableAccountsInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetCurrency();
  }
}

//  Class member function
//  Remove one account from table 'Accounts' in database
void DatabaseManager::RemoveAccountFromTableAccountsInDatabase(const std::string& account_name)
{
  bool account_is_in_table = false;
  int account_id;
  Account model;
  std::tie(account_is_in_table, account_id, std::ignore) = FindAccountInTableAccountsInDatabase(account_name);
  if (account_is_in_table)
  {
    const std::string sql_request = std::string("DELETE FROM Accounts WHERE id = ") +
      std::to_string(account_id) + ";";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Remove row Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Remove account '" << account_name << "' from table 'Accounts' in database";
    }
  }
}

//  Class member function
//  Create table 'Categories' in database
void DatabaseManager::CreateTableCategoriesInDatabase()
{
  CreateTableInDatabase("Categories");
}

//  Class member function
//  Remove table 'Categories' from database
void DatabaseManager::ClearTableCategoriesInDatabase()
{
  ClearTableInDatabase("Categories");
}

//  Class member function
//  Insert one category to table 'Categories' in database
void DatabaseManager::InsertCategoryToTableCategoriesInDatabase(Category&& model)
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Insert category to table 'Categories' in database";
    }
    return;
  }
}

//  Class member function
//  Insert categories to table 'Categories' in database
void DatabaseManager::InsertCategoriesToTableCategoriesInDatabase(CategoryRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertCategoryToTableCategoriesInDatabase(std::move(*i->first));
  }
}

//  Class member function
//  Find category with definite name in table 'Categories' in database
std::tuple<bool, int, Category, int> DatabaseManager::FindCategoryInTableCategoriesInDatabase(const std::string& model_name)
{
  sqlite3_prepare_v2(database_, "SELECT * FROM Categories", -1, &database_stmt_, 0);
  while (sqlite3_step(database_stmt_) != SQLITE_DONE)
  {
    int model_id = (sqlite3_column_int(database_stmt_, 0));
    const unsigned char* model_name_char = (sqlite3_column_text(database_stmt_, 1));
    int model_counter = (sqlite3_column_int(database_stmt_, 2));
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

//  Class member function
//  Find category with definite name in table 'Categories' in database and update name
void DatabaseManager::SetCategoryName(const std::string& model_name, const std::string& name)
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Set name (old name - '" << model_name << "') of category '" << name << "' in table 'Categories' in database";
    }
  }
}

//  Class member function
//  Get name of account from table 'Categories' in database
std::string DatabaseManager::GetCategoryName(const std::string& model_name)
{
  bool model_is_in_table = false;
  Category model;
  std::tie(model_is_in_table, std::ignore, model, std::ignore) = FindCategoryInTableCategoriesInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetName();
  }
}

//  Class member function
//  Remove one category from table 'Categories' in database
void DatabaseManager::RemoveCategoryFromTableCategoriesInDatabase(const std::string& category_name)
{
  bool category_is_in_table = false;
  int category_id;
  std::tie(category_is_in_table, category_id, std::ignore, std::ignore) = FindCategoryInTableCategoriesInDatabase(category_name);
  if (category_is_in_table)
  {
    const std::string sql_request = std::string("DELETE FROM Categories WHERE id = ") +
      std::to_string(category_id) + ";";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Remove row Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Remove category '" << category_name << "' from table 'Categories' in database";
    }
  }
}

//  Class member function
//  Create table 'Currencies' in database
void DatabaseManager::CreateTableCurrenciesInDatabase()
{
  CreateTableInDatabase("Currencies");
}

//  Class member function
//  Remove table 'Currencies' from database
void DatabaseManager::ClearTableCurrenciesInDatabase()
{
  ClearTableInDatabase("Currencies");
}

//  Class member function
//  Insert one currency to table 'Currencies' in database
void DatabaseManager::InsertCurrencyToTableCurrenciesInDatabase(Currency&& model)
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Insert currency " << model.GetName() << " to table 'Currencies' in database";
    }
    return;
  }
}

//  Class member function
//  Insert currencies to table 'Currencies' in database
void DatabaseManager::InsertCurrenciesToTableCurrenciesInDatabase(CurrencyRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertCurrencyToTableCurrenciesInDatabase(std::move(**i));
  }
}

//  Class member function
//  Find currency with definite name in table 'Currencies' in database
std::tuple<bool, int, Currency> DatabaseManager::FindCurrencyInTableCurrenciesInDatabase(const std::string& model_name)
{
  sqlite3_prepare_v2(database_, "SELECT * FROM Currencies", -1, &database_stmt_, 0);
  while (sqlite3_step(database_stmt_) != SQLITE_DONE)
  {
    int model_id = (sqlite3_column_int(database_stmt_, 0));
    const unsigned char* model_name_char = (sqlite3_column_text(database_stmt_, 1));
    const unsigned char* model_code_char = (sqlite3_column_text(database_stmt_, 2));
    int model_activity = (sqlite3_column_int(database_stmt_, 3));
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

//  Class member function
//  Find currency with definite code in table 'Currencies' in database
std::tuple<bool, int, Currency> DatabaseManager::FindCurrencyByCodeInTableCurrenciesInDatabase(const std::string& model_code)
{
  sqlite3_prepare_v2(database_, "SELECT * FROM Currencies", -1, &database_stmt_, 0);
  while (sqlite3_step(database_stmt_) != SQLITE_DONE)
  {
    int model_id = (sqlite3_column_int(database_stmt_, 0));
    const unsigned char* model_name_char = (sqlite3_column_text(database_stmt_, 1));
    const unsigned char* model_code_char = (sqlite3_column_text(database_stmt_, 2));
    int model_activity = (sqlite3_column_int(database_stmt_, 3));
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

//  Class member function
//  Find category with definite name in table 'Categories' in database and update name
void DatabaseManager::SetCurrencyName(const std::string& model_name, const std::string& name)
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Set name (old name - '" << model_name << "') of currency '" << name << "' in table 'Currencies' in database";
    }
  }
}

//  Class member function
//  Find category with definite name in table 'Categories' in database and update name
void DatabaseManager::SetCurrencyCode(const std::string& model_name, const std::string& code)
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Set code (old code - '" << model.GetCode() << "') of account '" << code << "' in table 'Currencies' in database";
    }
  }
}

//  Class member function
//  Find category with definite name in table 'Categories' in database and update name
void DatabaseManager::SetCurrencyActivity(const std::string& model_name, const bool activity)
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Set activity (old activity - '" << model.GetActivity() << "') of currency '" << activity << "' in table 'Currencies' in database";
    }
  }
}

//  Class member function
//  Get name of account from table 'Categories' in database
std::string DatabaseManager::GetCurrencyName(const std::string& model_name)
{
  bool model_is_in_table = false;
  Currency model;
  std::tie(model_is_in_table, std::ignore, model) = FindCurrencyInTableCurrenciesInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetName();
  }
}

//  Class member function
//  Get name of account from table 'Categories' in database
std::string DatabaseManager::GetCurrencyCode(const std::string& model_name)
{
  bool model_is_in_table = false;
  Currency model;
  std::tie(model_is_in_table, std::ignore, model) = FindCurrencyInTableCurrenciesInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetCode();
  }
}

//  Class member function
//  Get name of account from table 'Categories' in database
bool DatabaseManager::GetCurrencyActivity(const std::string& model_name)
{
  bool model_is_in_table = false;
  Currency model;
  std::tie(model_is_in_table, std::ignore, model) = FindCurrencyInTableCurrenciesInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetActivity();
  }
}

//  Class member function
//  Switch activity of currency from table 'Currencies' in database
void DatabaseManager::SwitchCurrencyActivity(const std::string& model_name)
{
  bool model_activity = GetCurrencyActivity(model_name);
  SetCurrencyActivity(model_name, !model_activity);
}

//  Class member function
//  Switch on activity of currency from table 'Currencies' in database
void DatabaseManager::SwitchOnCurrencyActivity(const std::string& model_name)
{
  SetCurrencyActivity(model_name, true);
}

//  Class member function
//  Switch off activity of currency from table 'Currencies' in database
void DatabaseManager::SwitchOffCurrencyActivity(const std::string& model_name)
{
  SetCurrencyActivity(model_name, false);
}

//  Class member function
//  Remove currency from table 'Currencies' in database
void DatabaseManager::RemoveCurrencyFromTableCurrenciesInDatabase(const std::string& currency_name)
{
  bool currency_is_in_table = false;
  int currency_id;
  std::tie(currency_is_in_table, currency_id, std::ignore) = FindCurrencyInTableCurrenciesInDatabase(currency_name);
  if (currency_is_in_table)
  {
    const std::string sql_request = std::string("DELETE FROM Currencies WHERE id = ") +
      std::to_string(currency_id) + ";";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Remove row Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Remove currency '" << currency_name << "' from table 'Currencies' in database";
    }
  }
}

//  Class member function
//  Create table 'Descriptions' in database
void DatabaseManager::CreateTableDescriptionsInDatabase()
{
  CreateTableInDatabase("Descriptions");
}

//  Class member function
//  Remove table 'Descriptions' from database
void DatabaseManager::ClearTableDescriptionsInDatabase()
{
  ClearTableInDatabase("Descriptions");
}

//  Class member function
//  Insert one description to table 'Descriptions' in database
void DatabaseManager::InsertDescriptionToTableDescriptionsInDatabase(Description&& model)
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Insert description to table 'Descriptions' in database";
    }
    return;
  }
}

//  Class member function
//  Insert descriptions to table 'Descriptions' in database
void DatabaseManager::InsertDescriptionsToTableDescriptionsInDatabase(DescriptionRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertDescriptionToTableDescriptionsInDatabase(std::move(*i->first));
  }
}

//  Class member function
//  Find description with definite name in table 'Descriptions' in database
std::tuple<bool, int, Description, int> DatabaseManager::FindDescriptionInTableDescriptionsInDatabase(const std::string& model_name)
{
  sqlite3_prepare_v2(database_, "SELECT * FROM Descriptions", -1, &database_stmt_, 0);
  while (sqlite3_step(database_stmt_) != SQLITE_DONE)
  {
    int model_id = (sqlite3_column_int(database_stmt_, 0));
    const unsigned char* model_name_char = (sqlite3_column_text(database_stmt_, 1));
    int model_counter = (sqlite3_column_int(database_stmt_, 2));
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

//  Class member function
//  Find description with definite name in table 'Descriptions' in database and update name
void DatabaseManager::SetDescriptionName(const std::string& model_name, const std::string& name)
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Set name ('" << model_old_name << "' -> '" << name << "') of description '" << model_name << "' in table 'Descriptions' in database";
    }
  }
}

//  Class member function
//  Get name of account from table 'Categories' in database
std::string DatabaseManager::GetDescriptionName(const std::string& model_name)
{
  bool model_is_in_table = false;
  Description model;
  std::tie(model_is_in_table, std::ignore, model, std::ignore) = FindDescriptionInTableDescriptionsInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetName();
  }
}

//  Class member function
//  Remove one description from table 'Descriptions' in database
void DatabaseManager::RemoveDescriptionFromTableDescriptionsInDatabase(const std::string& description_name)
{
  bool description_is_in_table = false;
  int description_id;
  std::tie(description_is_in_table, description_id, std::ignore, std::ignore) = FindDescriptionInTableDescriptionsInDatabase(description_name);
  if (description_is_in_table)
  {
    const std::string sql_request = std::string("DELETE FROM Descriptions WHERE id = ") +
      std::to_string(description_id) + ";";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Remove row Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Remove description '" << description_name << "' from table 'Descriptions' in database";
    }
  }
}

//  Class member function
//  Create table 'Payees' in database
void DatabaseManager::CreateTablePayeesInDatabase()
{
  CreateTableInDatabase("Payees");
}

//  Class member function
//  Remove table 'Payees' from database
void DatabaseManager::ClearTablePayeesInDatabase()
{
  ClearTableInDatabase("Payees");
}

//  Class member function
//  Insert one payee to table 'Payees' in database
void DatabaseManager::InsertPayeeToTablePayeesInDatabase(Payee&& model)
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Insert payee to table 'Payees' in database";
    }
    return;
  }
}

//  Class member function
//  Insert payees to table 'Payees' in database
void DatabaseManager::InsertPayeesToTablePayeesInDatabase(PayeeRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertPayeeToTablePayeesInDatabase(std::move(*i->first));
  }
}

//  Class member function
//  Find payee with definite name in table 'Payees' in database
std::tuple<bool, int, Payee, int> DatabaseManager::FindPayeeInTablePayeesInDatabase(const std::string& model_name)
{
  sqlite3_prepare_v2(database_, "SELECT * FROM Payees", -1, &database_stmt_, 0);
  while (sqlite3_step(database_stmt_) != SQLITE_DONE)
  {
    int model_id = (sqlite3_column_int(database_stmt_, 0));
    const unsigned char* model_name_char = (sqlite3_column_text(database_stmt_, 1));
    int model_counter = (sqlite3_column_int(database_stmt_, 2));
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

//  Class member function
//  Find payee with definite name in table 'Payees' in database and update name
void DatabaseManager::SetPayeeName(const std::string& model_name, const std::string& name)
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Set name ('" << model.GetName() << "' -> '" << name << "') of payee '" << model_name << "' in table 'Payees' in database";
    }
  }
}

//  Class member function
//  Get name of account from table 'Categories' in database
std::string DatabaseManager::GetPayeeName(const std::string& model_name)
{
  bool model_is_in_table = false;
  Payee model;
  std::tie(model_is_in_table, std::ignore, model, std::ignore) = FindPayeeInTablePayeesInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetName();
  }
}

//  Class member function
//  Remove payee from table 'Payees' in database
void DatabaseManager::RemovePayeeFromTablePayeesInDatabase(const std::string& payee_name)
{
  bool payee_is_in_table = false;
  int payee_id;
  std::tie(payee_is_in_table, payee_id, std::ignore, std::ignore) = FindPayeeInTablePayeesInDatabase(payee_name);
  if (payee_is_in_table)
  {
    const std::string sql_request = std::string("DELETE FROM Payees WHERE id = ") +
      std::to_string(payee_id) + ";";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Remove row Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Remove payee '" << payee_name << "' from table 'Payees' in database";
    }
  }
}

//  Class member function
//  Create table 'Comments' in database
void DatabaseManager::CreateTableCommentsInDatabase()
{
  CreateTableInDatabase("Comments");
}

//  Class member function
//  Remove table 'Comments' from database
void DatabaseManager::ClearTableCommentsInDatabase()
{
  ClearTableInDatabase("Comments");
}

//  Class member function
//  Insert one comment to table 'Comments' in database
void DatabaseManager::InsertCommentToTableCommentsInDatabase(Comment&& model)
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Insert comment to table 'Comments' in database";
    }
    return;
  }
}

//  Class member function
//  Insert comments to table 'Comments' in database
void DatabaseManager::InsertCommentsToTableCommentsInDatabase(CommentRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertCommentToTableCommentsInDatabase(std::move(*i->first));
  }
}

//  Class member function
//  Find comment with definite name in table 'Comments' in database
std::tuple<bool, int, Comment, int> DatabaseManager::FindCommentInTableCommentsInDatabase(const std::string& model_name)
{
  sqlite3_prepare_v2(database_, "SELECT * FROM Comments", -1, &database_stmt_, 0);
  while (sqlite3_step(database_stmt_) != SQLITE_DONE)
  {
    int model_id = (sqlite3_column_int(database_stmt_, 0));
    const unsigned char* model_name_char = (sqlite3_column_text(database_stmt_, 1));
    int model_counter = (sqlite3_column_int(database_stmt_, 2));
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

//  Class member function
//  Find comment with definite name in table 'Comments' in database and update name
void DatabaseManager::SetCommentName(const std::string& model_name, const std::string& name)
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
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Set name ('" << model.GetName() << "' -> '" << name << "') of comment '" << model_name << "' in table 'Comments' in database";
    }
  }
}

//  Class member function
//  Get name of account from table 'Categories' in database
std::string DatabaseManager::GetCommentName(const std::string& model_name)
{
  bool model_is_in_table = false;
  Comment model;
  std::tie(model_is_in_table, std::ignore, model, std::ignore) = FindCommentInTableCommentsInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetName();
  }
}

//  Class member function
//  Remove comment from table 'Comments' in database
void DatabaseManager::RemoveCommentFromTableCommentsInDatabase(const std::string& comment_name)
{
  bool comment_is_in_table = false;
  int comment_id;
  std::tie(comment_is_in_table, comment_id, std::ignore, std::ignore) = FindCommentInTableCommentsInDatabase(comment_name);
  if (comment_is_in_table)
  {
    const std::string sql_request = std::string("DELETE FROM Comments WHERE id = ") +
      std::to_string(comment_id) + ";";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Remove row Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Remove comment '" << comment_name << "' from table 'Comments' in database";
    }
  }
}

//  Class member function
//  Create table 'Tags' in database
void DatabaseManager::CreateTableTagsInDatabase()
{
  CreateTableInDatabase("Tags");
}

//  Class member function
//  Remove table 'Tags' from database
void DatabaseManager::ClearTableTagsInDatabase()
{
  ClearTableInDatabase("Tags");
}

//  Class member function
//  Insert one tag to table 'Tags' in database
void DatabaseManager::InsertTagToTableTagsInDatabase(Tag&& model)
{
  int counter_start = 1;
  bool model_in_database;
  int model_id;
  int model_counter;
  std::tie(model_in_database, model_id, std::ignore, model_counter) = FindTagInTableTagsInDatabase(model.GetName());
  if (model_in_database)
  {
    std::string sql_request = std::string("UPDATE Tags SET counter = ") + std::to_string(model_counter + 1) +
      " WHERE id = " + std::to_string(model_id) + ";";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Append counter for tag in table 'Tags' in database";
    }
    return;
  }
  else
  {
    std::string sql_request = std::string("INSERT INTO Tags VALUES(null, '") + 
      model.GetName() + "', " + std::to_string(counter_start) + ");";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Insert tag to table 'Tags' in database";
    }
    return;
  }
}

//  Class member function
//  Insert tags to table 'Tags' in database
void DatabaseManager::InsertTagsToTableTagsInDatabase(TagRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertTagToTableTagsInDatabase(std::move(*i->first));
  }
}

//  Class member function
//  Find tag with definite name in table 'Tags' in database
std::tuple<bool, int, Tag, int> DatabaseManager::FindTagInTableTagsInDatabase(const std::string& model_name)
{
  sqlite3_prepare_v2(database_, "SELECT * FROM Tags", -1, &database_stmt_, 0);
  while (sqlite3_step(database_stmt_) != SQLITE_DONE)
  {
    int model_id = (sqlite3_column_int(database_stmt_, 0));
    const unsigned char* model_name_char = (sqlite3_column_text(database_stmt_, 1));
    int model_counter = (sqlite3_column_int(database_stmt_, 2));
    if (reinterpret_cast<const char*>(model_name_char) == model_name)
    {
      Tag tag((reinterpret_cast<const char*>(model_name_char)));
      PLOG_INFO << "Tag with name " << model_name << " is found in table 'Tags' in database";
      return std::make_tuple(true, model_id, tag, model_counter);
    }
  }
  PLOG_INFO << "Tag with name " << model_name << " isn't found in table 'Tags' in database";
  return std::make_tuple(false, 0, Tag(), 0);
}

//  Class member function
//  Find tag with definite name in table 'Tags' in database and update name
void DatabaseManager::SetTagName(const std::string& model_name, const std::string& name)
{
  bool model_is_in_table = false;
  int model_id;
  Tag model;
  int model_counter;
  std::tie(model_is_in_table, model_id, model, model_counter) = FindTagInTableTagsInDatabase(model_name);
  if (model_is_in_table)
  {
    const std::string sql_request = std::string("UPDATE Tags SET name = '") + name +
      "' WHERE id = " + std::to_string(model_id) + ";";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Set name (old name - '" << model_name << "') of tag '" << name << "' in table 'Tags' in database";
    }
  }
}

//  Class member function
//  Get name of account from table 'Categories' in database
std::string DatabaseManager::GetTagName(const std::string& model_name)
{
  bool model_is_in_table = false;
  Tag model;
  std::tie(model_is_in_table, std::ignore, model, std::ignore) = FindTagInTableTagsInDatabase(model_name);
  if (model_is_in_table)
  {
    return model.GetName();
  }
}

//  Class member function
//  Remove one tag from table 'Tags' in database
void DatabaseManager::RemoveTagFromTableTagsInDatabase(const std::string& tag_name)
{
  bool tag_is_in_table = false;
  int tag_id;
  std::tie(tag_is_in_table, tag_id, std::ignore, std::ignore) = FindTagInTableTagsInDatabase(tag_name);
  if (tag_is_in_table)
  {
    const std::string sql_request = std::string("DELETE FROM Tags WHERE id = ") +
      std::to_string(tag_id) + ";";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Remove row Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Remove tag '" << tag_name << "' from table 'Tags' in database";
    }
  }
}
