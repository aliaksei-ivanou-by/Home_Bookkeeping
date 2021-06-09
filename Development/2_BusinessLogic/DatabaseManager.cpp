#include "home_bookkeeping/2_BusinessLogic/DatabaseManager.h"

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

static int callback(void* count, int argc, char** argv, char** azColName)
{
  int* c = (int*)count;
  *c = atoi(argv[0]);
  return 0;
}

//  Class member function
//  Calculate rows with data in table
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
        "counter INTEGER NOT NULL" + ");";
    }
    if (table == "Transactions")
    {
      sql_request = std::string("CREATE TABLE Transactions(") +
        "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
        "time TEXT NOT NULL, " +
        "account_from TEXT NOT NULL, " +
        "account_to TEXT NOT NULL, " +
        "category TEXT NOT NULL, " +
        "amount DOUBLE NOT NULL, " +
        "amount_account_from DOUBLE NOT NULL, " +
        "amount_acount_to DOUBLE NOT NULL, " +
        "comment TEXT NOT NULL, " +
        "currency TEXT NOT NULL, " +
        "description TEXT NOT NULL, " +
        "payee TEXT NOT NULL, " +
        "tag TEXT NOT NULL, " +
        "status TEXT NOT NULL, " +
        "type TEXT NOT NULL" +
        ");";
    }
    if (table == "Accounts")
    {
      sql_request = std::string("CREATE TABLE Accounts(") +
        "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
        "name TEXT NOT NULL" + ", " +
        "amount DOUBLE NOT NULL" + ");";
    }
    if (table == "Currencies")
    {
      std::string sql_request = std::string("CREATE TABLE Currencies(") +
        "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
        "name TEXT NOT NULL, " +
        "code TEXT NOT NULL, " +
        "activity BOOL NOT NULL" + ");";
    }
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Create table '" + table + "' in database";
    }
  }
}

//  Class member function
//  Remove table from database
void DatabaseManager::RemoveTableFromDatabase(const std::string& table)
{
  if (CheckTableForExistenceInDatabase(table))
  {
    const std::string sql_request = std::string("TRUNCATE TABLE ") + table + ";";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Remove table '" << table << "' in database";
    }
  }
}

//  Class member function
//  Create all tables in database
void DatabaseManager::CreateAllTablesInDatabase()
{
  CreateTableTransactionsInDatabase();
  CreateTableAccountsInDatabase();
  CreateTableCategoriesInDatabase();
  CreateTableCurrenciesInDatabase();
  CreateTableDescriptionsInDatabase();
  CreateTablePayeesInDatabase();
  CreateTableCommentsInDatabase();
  CreateTableTagsInDatabase();
}

//  Class member function
//  Create table 'Transactions' in database
void DatabaseManager::CreateTableTransactionsInDatabase()
{
  // CreateTableInDatabase("Transactions");
  const std::string sql_request = std::string("CREATE TABLE Transactions(") + 
    "id INTEGER PRIMARY KEY AUTOINCREMENT, " + 
    "time TEXT NOT NULL, " + 
    "account_from TEXT NOT NULL, " + 
    "account_to TEXT NOT NULL, " + 
    "category TEXT NOT NULL, " + 
    "amount DOUBLE NOT NULL, " + 
    "amount_account_from DOUBLE NOT NULL, " + 
    "amount_acount_to DOUBLE NOT NULL, " + 
    "comment TEXT NOT NULL, " + 
    "currency TEXT NOT NULL, " + 
    "description TEXT NOT NULL, " + 
    "payee TEXT NOT NULL, " + 
    "tag TEXT NOT NULL, " + 
    "status TEXT NOT NULL, " + 
    "type TEXT NOT NULL" + 
    ");";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Create table 'Transactions' in database";
}

//  Class member function
//  Remove table 'Transactions' from database
void DatabaseManager::RemoveTableTransactionsFromDatabase(TransactionRepository&& repository)
{
  RemoveTableFromDatabase("Transactions");
}

//  Class member function
//  Insert transactions to table 'Transactions' in database
void DatabaseManager::InsertTransactionsToTableTransactionsInDatabase(TransactionRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    const std::string sql_request = std::string("INSERT INTO Transactions VALUES(") +
      "null, '" +
      (**i).GetStringTime() + "', '" +
      (**i).GetAccountFrom().GetName() + "', '" +
      (**i).GetAccountTo().GetName() + "', '" +
      (**i).GetCategory().GetName() + "', " +
      std::to_string((**i).GetAmount().getAsDouble()) + ", " +
      std::to_string((**i).GetAmountAccountFrom().getAsDouble()) + ", " +
      std::to_string((**i).GetAmountAccountTo().getAsDouble()) + ", '" +
      (**i).GetComment().GetName() + "', '" +
      (**i).GetCurrency().GetName() + "', '" +
      (**i).GetDescription().GetName() + "', '" +
      (**i).GetPayee().GetName() + "', '" +
      (**i).GetTag().GetName() + "', '" +
      (**i).GetStatus().GetName() + "', '" +
      (**i).GetType().GetName() + "')";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
  }
  PLOG_INFO << "Insert transactions to table 'Transactions' in database";
}

//  Class member function
//  Insert one transaction to table 'Transactions' in database
void DatabaseManager::InsertTransactionToTableTransactionsInDatabase(Transaction&& transaction)
{

}

//  Class member function
//  Create table 'Accounts' in database
void DatabaseManager::CreateTableAccountsInDatabase()
{
  CreateTableInDatabase("Accounts");
}

//  Class member function
//  Remove table 'Accounts' from database
void DatabaseManager::RemoveTableAccountsFromDatabase()
{
  RemoveTableFromDatabase("Accounts");
}

//  Class member function
//  Insert accounts to table 'Accounts' in database
void DatabaseManager::InsertAccountsToTableAccountsInDatabase(AccountRepository&& repository)
{
  int count = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertAccountToTableAccountsInDatabase(std::move(**i));
    ++count;
  }
  PLOG_INFO << "Insert " << count << " accounts to table 'Accounts' in database";
}

//  Class member function
//  Insert account to table 'Accounts' in database
void DatabaseManager::InsertAccountToTableAccountsInDatabase(Account&& account)
{
  int table_rows = SizeOfTable("Accounts");
  if (table_rows == 0)
  {
    const std::string sql_request = std::string("INSERT INTO Accounts VALUES(") +
      "null, '" +
      account.GetName() + "', " +
      std::to_string(account.GetAmount().getAsDouble()) + ");";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Insert account to table 'Accounts' in database";
    }
    return;
  }
  if (table_rows > 0)
  {
    sqlite3_prepare_v2(database_, "SELECT * FROM Accounts", -1, &database_stmt_, 0);
    int account_amount;
    const unsigned char* account_name;
    while (sqlite3_step(database_stmt_) != SQLITE_DONE)
    {
      account_name = (sqlite3_column_text(database_stmt_, 1));
      account_amount = sqlite3_column_int(database_stmt_, 2);
      if (account_name == nullptr)
      {
        const std::string sql_request = std::string("INSERT INTO Accounts VALUES(") +
          "null, '" +
          account.GetName() + "', " +
          std::to_string(account.GetAmount().getAsDouble()) + ");";
        database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
        if (database_status_ != SQLITE_OK)
        {
          PLOG_ERROR << "SQL Insert Error: " << database_error_;
        }
        else
        {
          PLOG_INFO << "Insert account to table 'Accounts' in database";
        }
        return;
      }
      if (reinterpret_cast<const char*>(account_name) == account.GetName())
      {
        PLOG_ERROR << "Table 'Accounts' has this account";
        return;
      }
    }
    const std::string sql_request = std::string("INSERT INTO Accounts VALUES(") +
      "null, '" +
      account.GetName() + "', " +
      std::to_string(account.GetAmount().getAsDouble()) + ");";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Insert account to table 'Accounts' in database";
    }
    return;
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
void DatabaseManager::RemoveTableCategoriesFromDatabase(CategoryRepository&& repository)
{
  RemoveTableFromDatabase("Categories");
}

//  Class member function
//  Insert categories to table 'Categories' in database
void DatabaseManager::InsertCategoriesToTableCategoriesInDatabase(CategoryRepository&& repository)
{
  int count = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertCategoryToTableCategoriesInDatabase(std::move(*i->first));
    ++count;
  }
  PLOG_INFO << "Insert " << count << " categories to table 'Categories' in database";
}

//  Class member function
//  Insert one category to table 'Categories' in database
void DatabaseManager::InsertCategoryToTableCategoriesInDatabase(Category&& category)
{
  int table_rows = SizeOfTable("Categories");
  int id_start = 1;
  if (table_rows == 0)
  {
    const std::string sql_request = std::string("INSERT INTO Categories VALUES(") +
      "null, '" + 
      category.GetName() + "', " +
      std::to_string(id_start) + ");";
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
  if (table_rows > 0)
  {
    sqlite3_prepare_v2(database_, "SELECT * FROM Categories", -1, &database_stmt_, 0);
    int category_counter;
    const unsigned char* category_name;
    while (sqlite3_step(database_stmt_) != SQLITE_DONE)
    {
      category_name = (sqlite3_column_text(database_stmt_, 1));
      category_counter = sqlite3_column_int(database_stmt_, 2);
      if (category_name == nullptr)
      {
        const std::string sql_request = std::string("INSERT INTO Categories VALUES(") +
          "null, '" +
          category.GetName() + "', " +
          std::to_string(1) + ");";
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
      if (reinterpret_cast<const char*>(category_name) == category.GetName())
      {
        const std::string sql_request = std::string("UPDATE Categories SET counter = ") +
          std::to_string(category_counter + 1) +
          " WHERE name = " + "'" +
          reinterpret_cast<const char*>(category_name) + "';";
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
    const std::string sql_request = std::string("INSERT INTO Categories VALUES(") +
      "null, '" +
      category.GetName() + "', " +
      std::to_string(1) + ");";
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
//  Create table 'Currencies' in database
void DatabaseManager::CreateTableCurrenciesInDatabase()
{
  CreateTableInDatabase("Currencies");
}

//  Class member function
//  Remove table 'Currencies' from database
void DatabaseManager::RemoveTableCurrenciesFromDatabase(CurrencyRepository&& repository)
{
  RemoveTableFromDatabase("Currencies");
}

//  Class member function
//  Insert currencies to table 'Currencies' in database
void DatabaseManager::InsertCurrenciesToTableCurrenciesInDatabase(CurrencyRepository&& repository)
{
  int count = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertCurrencyToTableCurrenciesInDatabase(std::move(**i));
    ++count;
  }
  PLOG_INFO << "Insert " << count << " descriptions to table 'Descriptions' in database";
}

//  Class member function
//  Insert one currency to table 'Currencies' in database
void DatabaseManager::InsertCurrencyToTableCurrenciesInDatabase(Currency&& currency)
{
  int table_rows = SizeOfTable("Currencies");
  int id_start = 1;
  if (table_rows == 0)
  {
    const std::string sql_request = std::string("INSERT INTO Currencies VALUES(") +
      "null, '" +
      currency.GetName() + "', '" +
      currency.GetCode() + "', '" +
      std::to_string(currency.GetActivity() ? 1 : 0) + "');";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Insert currency to table 'Currencies' in database";
    }
    return;
  }
  if (table_rows > 0)
  {
    sqlite3_prepare_v2(database_, "SELECT * FROM Currencies", -1, &database_stmt_, 0);
    const unsigned char* currency_name;
    const unsigned char* currency_code;
    int currency_activity;
    while (sqlite3_step(database_stmt_) != SQLITE_DONE)
    {
      currency_name = sqlite3_column_text(database_stmt_, 1);
      currency_code = sqlite3_column_text(database_stmt_, 2);
      currency_activity = sqlite3_column_int(database_stmt_, 3);
      if (currency_name == nullptr)
      {
        const std::string sql_request = std::string("INSERT INTO Currencies VALUES(") +
          "null, '" +
          currency.GetName() + "', '" +
          currency.GetCode() + "', '" +
          std::to_string(currency.GetActivity() ? 1 : 0) + "');";
        database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
        if (database_status_ != SQLITE_OK)
        {
          PLOG_ERROR << "SQL Insert Error: " << database_error_;
        }
        else
        {
          PLOG_INFO << "Insert currency to table 'Currencies' in database";
        }
        return;
      }
      if (reinterpret_cast<const char*>(currency_name) == currency.GetName())
      {
        PLOG_ERROR << "Table 'Currencies' has this currency";
        return;
      }
    }
    const std::string sql_request = std::string("INSERT INTO Currencies VALUES(") +
      "null, '" +
      currency.GetName() + "', '" +
      currency.GetCode() + "', '" +
      std::to_string(currency.GetActivity() ? 1 : 0) + "');";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    else
    {
      PLOG_INFO << "Insert currency to table 'Currencies' in database";
    }
    return;
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
void DatabaseManager::RemoveTableDescriptionsFromDatabase(DescriptionRepository&& repository)
{
  RemoveTableFromDatabase("Descriptions");
}

//  Class member function
//  Insert descriptions to table 'Descriptions' in database
void DatabaseManager::InsertDescriptionsToTableDescriptionsInDatabase(DescriptionRepository&& repository)
{
  int count = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertDescriptionToTableDescriptionsInDatabase(std::move(*i->first));
    ++count;
  }
  PLOG_INFO << "Insert " << count << " descriptions to table 'Descriptions' in database";
}

//  Class member function
//  Insert one description to table 'Descriptions' in database
void DatabaseManager::InsertDescriptionToTableDescriptionsInDatabase(Description&& description)
{
  int table_rows = SizeOfTable("Descriptions");
  int id_start = 1;
  if (table_rows == 0)
  {
    const std::string sql_request = std::string("INSERT INTO Descriptions VALUES(") +
      "null, '" +
      description.GetName() + "', " +
      std::to_string(id_start) + ");";
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
  if (table_rows > 0)
  {
    sqlite3_prepare_v2(database_, "SELECT * FROM Descriptions", -1, &database_stmt_, 0);
    int description_counter;
    const unsigned char* description_name;
    while (sqlite3_step(database_stmt_) != SQLITE_DONE)
    {
      description_name = (sqlite3_column_text(database_stmt_, 1));
      description_counter = sqlite3_column_int(database_stmt_, 2);
      if (description_name == nullptr)
      {
        const std::string sql_request = std::string("INSERT INTO Descriptions VALUES(") +
          "null, '" +
          description.GetName() + "', " +
          std::to_string(1) + ");";
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
      if (reinterpret_cast<const char*>(description_name) == description.GetName())
      {
        const std::string sql_request = std::string("UPDATE Descriptions SET counter = ") +
          std::to_string(description_counter + 1) +
          " WHERE name = " + "'" +
          reinterpret_cast<const char*>(description_name) + "';";
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
    const std::string sql_request = std::string("INSERT INTO Descriptions VALUES(") +
      "null, '" +
      description.GetName() + "', " +
      std::to_string(1) + ");";
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
//  Find description with definite name in table 'Descriptions' in database
std::tuple<bool, Description> DatabaseManager::FindDescriptionByNameInTableDescriptionsInDatabase(const std::string& name)
{
  Description description;
  sqlite3_prepare_v2(database_, "SELECT * FROM Descriptions", -1, &database_stmt_, 0);
  while (sqlite3_step(database_stmt_) != SQLITE_DONE)
  {
    const unsigned char* description_name = (sqlite3_column_text(database_stmt_, 1));
    if (reinterpret_cast<const char*>(description_name) == name)
    {
      description.SetName((reinterpret_cast<const char*>(description_name)));
      PLOG_INFO << "Description with name " << name << " is found in table 'Descriptions' in database";
      return std::make_tuple(true, description);
    }
  }
  PLOG_INFO << "Description with name " << name << " isn't found in table 'Descriptions' in database";
  return std::make_tuple(false, description);
}

//  Class member function
//  Create table 'Payees' in database
void DatabaseManager::CreateTablePayeesInDatabase()
{
  CreateTableInDatabase("Payees");
}

//  Class member function
//  Remove table 'Payees' from database
void DatabaseManager::RemoveTablePayeesFromDatabase(PayeeRepository&& repository)
{
  RemoveTableFromDatabase("Payees");
}

//  Class member function
//  Insert payees to table 'Payees' in database
void DatabaseManager::InsertPayeesToTablePayeesInDatabase(PayeeRepository&& repository)
{
  int count = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertPayeeToTablePayeesInDatabase(std::move(*i->first));
    ++count;
  }
  PLOG_INFO << "Insert " << count << " payees to table 'Payees' in database";
}

//  Class member function
//  Insert one payee to table 'Payees' in database
void DatabaseManager::InsertPayeeToTablePayeesInDatabase(Payee&& payee)
{
  int table_rows = SizeOfTable("Payees");
  int id_start = 1;
  if (table_rows == 0)
  {
    const std::string sql_request = std::string("INSERT INTO Payees VALUES(") +
      "null, '" +
      payee.GetName() + "', " +
      std::to_string(id_start) + ");";
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
  if (table_rows > 0)
  {
    sqlite3_prepare_v2(database_, "SELECT * FROM Payees", -1, &database_stmt_, 0);
    int payee_counter;
    const unsigned char* payee_name;
    while (sqlite3_step(database_stmt_) != SQLITE_DONE)
    {
      payee_name = (sqlite3_column_text(database_stmt_, 1));
      payee_counter = sqlite3_column_int(database_stmt_, 2);
      if (payee_name == nullptr)
      {
        const std::string sql_request = std::string("INSERT INTO Payees VALUES(") +
          "null, '" +
          payee.GetName() + "', " +
          std::to_string(1) + ");";
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
      if (reinterpret_cast<const char*>(payee_name) == payee.GetName())
      {
        const std::string sql_request = std::string("UPDATE Payees SET counter = ") +
          std::to_string(payee_counter + 1) +
          " WHERE name = " + "'" +
          reinterpret_cast<const char*>(payee_name) + "';";
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
    const std::string sql_request = std::string("INSERT INTO Payees VALUES(") +
      "null, '" +
      payee.GetName() + "', " +
      std::to_string(1) + ");";
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
//  Find payee with definite name in table 'Comments' in database
std::tuple<bool, Payee> DatabaseManager::FindPayeeByNameInTablePayeesInDatabase(const std::string& name)
{
  Payee payee;
  sqlite3_prepare_v2(database_, "SELECT * FROM Payees", -1, &database_stmt_, 0);
  while (sqlite3_step(database_stmt_) != SQLITE_DONE)
  {
    const unsigned char* payee_name = (sqlite3_column_text(database_stmt_, 1));
    if (reinterpret_cast<const char*>(payee_name) == name)
    {
      payee.SetName((reinterpret_cast<const char*>(payee_name)));
      PLOG_INFO << "Payee with name " << name << " is found in table 'Payees' in database";
      return std::make_tuple(true, payee);
    }
  }
  PLOG_INFO << "Payee with name " << name << " isn't found in table 'Payees' in database";
  return std::make_tuple(false, payee);
}

//  Class member function
//  Create table 'Comments' in database
void DatabaseManager::CreateTableCommentsInDatabase()
{
  CreateTableInDatabase("Comments");
}

//  Class member function
//  Remove table 'Comments' from database
void DatabaseManager::RemoveTableCommentsFromDatabase(CommentRepository&& repository)
{
  RemoveTableFromDatabase("Comments");
}

//  Class member function
//  Insert comments to table 'Comments' in database
void DatabaseManager::InsertCommentsToTableCommentsInDatabase(CommentRepository&& repository)
{
  int count = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertCommentToTableCommentsInDatabase(std::move(*i->first));
    ++count;
  }
  PLOG_INFO << "Insert " << count << " comments to table 'Comments' in database";
}

//  Class member function
//  Insert one comment to table 'Comments' in database
void DatabaseManager::InsertCommentToTableCommentsInDatabase(Comment&& comment)
{
  int table_rows = SizeOfTable("Comments");
  int id_start = 1;
  if (table_rows == 0)
  {
    const std::string sql_request = std::string("INSERT INTO Comments VALUES(") +
      "null, '" +
      comment.GetName() + "', " +
      std::to_string(id_start) + ");";
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
  if (table_rows > 0)
  {
    sqlite3_prepare_v2(database_, "SELECT * FROM Comments", -1, &database_stmt_, 0);
    int comment_counter;
    const unsigned char* comment_name;
    while (sqlite3_step(database_stmt_) != SQLITE_DONE)
    {
      comment_name = (sqlite3_column_text(database_stmt_, 1));
      comment_counter = sqlite3_column_int(database_stmt_, 2);
      if (comment_name == nullptr)
      {
        const std::string sql_request = std::string("INSERT INTO Comments VALUES(") +
          "null, '" +
          comment.GetName() + "', " +
          std::to_string(1) + ");";
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
      if (reinterpret_cast<const char*>(comment_name) == comment.GetName())
      {
        const std::string sql_request = std::string("UPDATE Comments SET counter = ") +
          std::to_string(comment_counter + 1) +
          " WHERE name = " + "'" +
          reinterpret_cast<const char*>(comment_name) + "';";
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
    const std::string sql_request = std::string("INSERT INTO Comments VALUES(") +
      "null, '" +
      comment.GetName() + "', " +
      std::to_string(1) + ");";
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
//  Find comment with definite name in table 'Comments' in database
std::tuple<bool, Comment> DatabaseManager::FindCommentByNameInTableCommentsInDatabase(const std::string& name)
{
  Comment comment;
  sqlite3_prepare_v2(database_, "SELECT * FROM Comments", -1, &database_stmt_, 0);
  while (sqlite3_step(database_stmt_) != SQLITE_DONE)
  {
    const unsigned char* comment_name = (sqlite3_column_text(database_stmt_, 1));
    if (reinterpret_cast<const char*>(comment_name) == name)
    {
      comment.SetName((reinterpret_cast<const char*>(comment_name)));
      PLOG_INFO << "Comment with name " << name << " is found in table 'Comments' in database";
      return std::make_tuple(true, comment);
    }
  }
  PLOG_INFO << "Comment with name " << name << " isn't found in table 'Comments' in database";
  return std::make_tuple(false, comment);
}

//  Class member function
//  Create table 'Tags' in database
void DatabaseManager::CreateTableTagsInDatabase()
{
  CreateTableInDatabase("Tags");
}

//  Class member function
//  Remove table 'Tags' from database
void DatabaseManager::RemoveTableTagsFromDatabase(TagRepository&& repository)
{
  RemoveTableFromDatabase("Tags");
}

//  Class member function
//  Insert tags to table 'Tags' in database
void DatabaseManager::InsertTagsToTableTagsInDatabase(TagRepository&& repository)
{
  int count = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertTagToTableTagsInDatabase(std::move(*i->first));
    ++count;
  }
  PLOG_INFO << "Insert " << count << " tags to table 'Tags' in database";
}

//  Class member function
//  Insert one tag to table 'Tags' in database
void DatabaseManager::InsertTagToTableTagsInDatabase(Tag&& tag)
{
  int table_rows = SizeOfTable("Tags");
  int id_start = 1;
  if (table_rows == 0)
  {
    const std::string sql_request = std::string("INSERT INTO Tags VALUES(") +
      "null, '" +
      tag.GetName() + "', " +
      std::to_string(id_start) + ");";
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
  if (table_rows > 0)
  {
    sqlite3_prepare_v2(database_, "SELECT * FROM Tags", -1, &database_stmt_, 0);
    int tag_counter;
    const unsigned char* tag_name;
    while (sqlite3_step(database_stmt_) != SQLITE_DONE)
    {
      tag_name = (sqlite3_column_text(database_stmt_, 1));
      tag_counter = sqlite3_column_int(database_stmt_, 2);
      if (tag_name == nullptr)
      {
        const std::string sql_request = std::string("INSERT INTO Tags VALUES(") +
          "null, '" +
          tag.GetName() + "', " +
          std::to_string(1) + ");";
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
      if (reinterpret_cast<const char*>(tag_name) == tag.GetName())
      {
        const std::string sql_request = std::string("UPDATE Tags SET counter = ") +
          std::to_string(tag_counter + 1) +
          " WHERE name = " + "'" +
          reinterpret_cast<const char*>(tag_name) + "';";
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
    const std::string sql_request = std::string("INSERT INTO Tags VALUES(") +
      "null, '" +
      tag.GetName() + "', " +
      std::to_string(1) + ");";
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
//  Find tag with definite name in table 'Tags' in database
std::tuple<bool, Tag> DatabaseManager::FindTagByNameInTableTagsInDatabase(const std::string& name)
{
  Tag tag;
  sqlite3_prepare_v2(database_, "SELECT * FROM Tags", -1, &database_stmt_, 0);
  while (sqlite3_step(database_stmt_) != SQLITE_DONE)
  {
    const unsigned char* tag_name = (sqlite3_column_text(database_stmt_, 1));
    if (reinterpret_cast<const char*>(tag_name) == name)
    {
      tag.SetName((reinterpret_cast<const char*>(tag_name)));
      PLOG_INFO << "Tag with name " << name << " is found in table 'Tags' in database";
      return std::make_tuple(true, tag);
    }
  }
  PLOG_INFO << "Tag with name " << name << " isn't found in table 'Tags' in database";
  return std::make_tuple(false, tag);
}