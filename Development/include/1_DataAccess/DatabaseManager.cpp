#include "include/1_DataAccess/DatabaseManager.h"

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

DatabaseManager::~DatabaseManager()
{
  sqlite3_close(database_);
  PLOG_INFO << "Close database";
}

static int callback(void* count, int argc, char** argv, char** azColName)
{
  int* c = (int*)count;
  *c = atoi(argv[0]);
  return 0;
}

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


void DatabaseManager::CreateAllTablesInDatabase()
{
  CreateTableInDatabase("Accounts");
  CreateTableInDatabase("Categories");
  CreateTableInDatabase("Currencies");
  CreateTableInDatabase("Descriptions");
  CreateTableInDatabase("Payees");
  CreateTableInDatabase("Comments");
  CreateTableInDatabase("Tags");
  CreateTableInDatabase("Transactions");
}

void DatabaseManager::ClearAllTablesInDatabase()
{
  ClearTableInDatabase("Accounts");
  ClearTableInDatabase("Categories");
  ClearTableInDatabase("Currencies");
  ClearTableInDatabase("Descriptions");
  ClearTableInDatabase("Payees");
  ClearTableInDatabase("Comments");
  ClearTableInDatabase("Tags");
  ClearTableInDatabase("Transactions");
}

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
  //std::tie(transaction_category_in_database, transaction_category_id, std::ignore, std::ignore) = FindCategoryInTableCategoriesInDatabase(transaction.GetCategory().GetName());
  if (!transaction_category_in_database)
  {
    //InsertCategoryToTableCategoriesInDatabase(transaction.GetCategory());
    //std::tie(transaction_category_in_database, transaction_category_id, std::ignore, std::ignore) = FindCategoryInTableCategoriesInDatabase(transaction.GetCategory().GetName());
  }
  // Check comment
  bool transaction_comment_in_database;
  int transaction_comment_id;
  //std::tie(transaction_comment_in_database, transaction_comment_id, std::ignore, std::ignore) = FindCommentInTableCommentsInDatabase(transaction.GetComment().GetName());
  if (!transaction_category_in_database)
  {
    //InsertCommentToTableCommentsInDatabase(transaction.GetComment());
    //std::tie(transaction_comment_in_database, transaction_comment_id, std::ignore, std::ignore) = FindCommentInTableCommentsInDatabase(transaction.GetComment().GetName());
  }
  // Check currency
  bool transaction_currency_in_database;
  int transaction_currency_id;
  //std::tie(transaction_currency_in_database, transaction_currency_id, std::ignore) = FindCurrencyInTableCurrenciesInDatabase(transaction.GetCurrency().GetName());
  if (!transaction_category_in_database)
  {
    //InsertCurrencyToTableCurrenciesInDatabase(transaction.GetCurrency());
    //std::tie(transaction_currency_in_database, transaction_currency_id, std::ignore) = FindCurrencyInTableCurrenciesInDatabase(transaction.GetCurrency().GetName());
  }
  // Check description
  bool transaction_description_in_database;
  int transaction_description_id;
  //std::tie(transaction_description_in_database, transaction_description_id, std::ignore, std::ignore) = FindDescriptionInTableDescriptionsInDatabase(transaction.GetDescription().GetName());
  if (!transaction_description_in_database)
  {
    //InsertDescriptionToTableDescriptionsInDatabase(transaction.GetDescription());
    //std::tie(transaction_description_in_database, transaction_description_id, std::ignore, std::ignore) = FindDescriptionInTableDescriptionsInDatabase(transaction.GetDescription().GetName());
  }
  // Check payee
  bool transaction_payee_in_database;
  int transaction_payee_id;
  //std::tie(transaction_payee_in_database, transaction_payee_id, std::ignore, std::ignore) = FindPayeeInTablePayeesInDatabase(transaction.GetPayee().GetName());
  if (!transaction_payee_in_database)
  {
    //InsertPayeeToTablePayeesInDatabase(transaction.GetPayee());
    //std::tie(transaction_payee_in_database, transaction_payee_id, std::ignore, std::ignore) = FindPayeeInTablePayeesInDatabase(transaction.GetPayee().GetName());
  }
  // Check tag
  bool transaction_tag_in_database;
  int transaction_tag_id;
  //std::tie(transaction_tag_in_database, transaction_tag_id, std::ignore, std::ignore) = FindTagInTableTagsInDatabase(transaction.GetTag().GetName());
  if (!transaction_tag_in_database)
  {
    //InsertTagToTableTagsInDatabase(transaction.GetTag());
    //std::tie(transaction_tag_in_database, transaction_tag_id, std::ignore, std::ignore) = FindTagInTableTagsInDatabase(transaction.GetTag().GetName());
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

void DatabaseManager::InsertTransactionsToTableTransactionsInDatabase(TransactionRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertTransactionToTableTransactionsInDatabase(std::move(**i));
  }
}

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

void DatabaseManager::InsertAccountToTableAccountsInDatabase(Account&& model)
{
  bool model_currency_in_database = false;
  int model_currency_id;
 // std::tie(model_currency_in_database, model_currency_id, std::ignore) = FindCurrencyInTableCurrenciesInDatabase(model.GetCurrency().GetName());
  if (!model_currency_in_database)
  {
    //InsertCurrencyToTableCurrenciesInDatabase(model.GetCurrency());
    //std::tie(model_currency_in_database, model_currency_id, std::ignore) = FindCurrencyInTableCurrenciesInDatabase(model.GetCurrency().GetName());
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

void DatabaseManager::InsertAccountsToTableAccountsInDatabase(AccountRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertAccountToTableAccountsInDatabase(std::move(**i));
  }
}

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

void DatabaseManager::SetAccountCurrency(const std::string& model_name, Currency&& currency)
{
  bool currency_is_in_table = false;
  int currency_id;
  Currency currency_in_table;
  //std::tie(currency_is_in_table, currency_id, currency_in_table) = FindCurrencyInTableCurrenciesInDatabase(currency.GetName());
  if (!currency_is_in_table)
  {
    //InsertCurrencyToTableCurrenciesInDatabase(std::move(currency));
    //std::tie(currency_is_in_table, currency_id, currency_in_table) = FindCurrencyInTableCurrenciesInDatabase(currency.GetName());
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
