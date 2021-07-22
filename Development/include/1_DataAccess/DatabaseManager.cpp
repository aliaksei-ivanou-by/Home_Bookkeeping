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
