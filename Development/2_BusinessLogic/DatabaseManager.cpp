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
  const std::string sql_request = "SELECT COUNT(*) FROM " + table;
  int table_rows = 0;
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), callback, &table_rows, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  return table_rows;
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
  const std::string sql_request = std::string("CREATE TABLE Transactions(") + 
    "id SERIAL PRIMARY KEY, " + 
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
//  Remove table 'Transactions' in database
void DatabaseManager::RemoveTableTransactionsInDatabase(TransactionRepository&& repository)
{
  const std::string sql_request = "TRUNCATE TABLE IF EXISTS Transactions";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Remove table 'Transactions' in database if exists";
}

//  Class member function
//  Insert transactions to table 'Transactions' in database
void DatabaseManager::InsertTransactionsToTableTransactionsInDatabase(TransactionRepository&& repository)
{
  size_t j = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    const std::string sql_request = std::string("INSERT INTO Transactions VALUES(") +
      std::to_string(j) + ", '" +
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
    ++j;
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
  std::string sql_request = std::string("CREATE TABLE Accounts(") + 
    "name TEXT NOT NULL" + ", " + 
    "amount DOUBLE NOT NULL" + ");";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Create table 'Accounts' in database";
}

//  Class member function
//  Remove table 'Accounts' in database
void DatabaseManager::RemoveTableAccountsInDatabase()
{
  const std::string sql_request = "TRUNCATE TABLE IF EXISTS Accounts";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Remove table 'Accounts' in database if exists";
}

//  Class member function
//  Insert accounts to table 'Accounts' in database
void DatabaseManager::InsertAccountsToTableAccountsInDatabase(AccountRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    const std::string sql_request = std::string("INSERT INTO Accounts VALUES('") +
      (**i).GetName() + "', " +
      dec::toString((**i).GetAmount()) + ")";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
  }
  PLOG_INFO << "Insert accounts to table 'Accounts' in database";
}

//  Class member function
//  Insert account to table 'Accounts' in database
void DatabaseManager::InsertAccountToTableAccountsInDatabase(Account&& account)
{

}

//  Class member function
//  Create table 'Categories' in database
void DatabaseManager::CreateTableCategoriesInDatabase()
{
  std::string sql_request = std::string("CREATE TABLE Categories(") + 
    "id SERIAL PRIMARY KEY, " + 
    "name TEXT NOT NULL, " + 
    "counter INTEGER NOT NULL" + ");";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Create table 'Categories' in database";
}

//  Class member function
//  Remove table 'Categories' in database
void DatabaseManager::RemoveTableCategoriesInDatabase(CategoryRepository&& repository)
{
  const std::string sql_request = "TRUNCATE TABLE IF EXISTS Categories";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Remove table 'Categories' in database if exists";
}

//  Class member function
//  Insert categories to table 'Categories' in database
void DatabaseManager::InsertCategoriesToTableCategoriesInDatabase(CategoryRepository&& repository)
{
  size_t j = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    const std::string sql_request = std::string("INSERT INTO Categories VALUES(") +
      std::to_string(j) + ", '" +
      i->first->GetName() + "', " +
      std::to_string(i->second) + ")";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    ++j;
  }
  PLOG_INFO << "Insert categories to table 'Categories' in database";
}

//  Class member function
//  Insert one category to table 'Categories' in database
void DatabaseManager::InsertCategoryToTableCategoriesInDatabase(Category&& category)
{
  int table_rows = SizeOfTable("Categories");

  if (table_rows == 0)
  {
    const std::string sql_request = std::string("INSERT INTO Categories VALUES(") +
      std::to_string(1) + ", '" +
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
  }
  if (table_rows > 0)
  {
    sqlite3_prepare_v2(database_, "SELECT * FROM Categories", -1, &database_stmt_, 0);
    int category_id;
    int category_counter;
    const unsigned char* category_name;
    while (sqlite3_step(database_stmt_) != SQLITE_DONE)
    {
      category_id = sqlite3_column_int(database_stmt_, 0);
      category_name = (sqlite3_column_text(database_stmt_, 1));
      category_counter = sqlite3_column_int(database_stmt_, 2);
      if (category_name == nullptr)
      {
        const std::string sql_request = std::string("INSERT INTO Categories VALUES(") +
          std::to_string(1) + ", '" +
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
      }
    }
  }
}

//  Class member function
//  Create table 'Currencies' in database
void DatabaseManager::CreateTableCurrenciesInDatabase()
{
  std::string sql_request = std::string("CREATE TABLE Currencies(") + 
    "id SERIAL PRIMARY KEY, " + 
    "name TEXT NOT NULL, " + 
    "code TEXT NOT NULL, " + 
    "activity BOOL NOT NULL" + ");";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Create table 'Currencies' in database";
}

//  Class member function
//  Remove table 'Currencies' in database
void DatabaseManager::RemoveTableCurrenciesInDatabase(CurrencyRepository&& repository)
{
  const std::string sql_request = "TRUNCATE TABLE IF EXISTS Currencies";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Remove table 'Currencies' in database if exists";
}

//  Class member function
//  Insert currencies to table 'Currencies' in database
void DatabaseManager::InsertCurrenciesToTableCurrenciesInDatabase(CurrencyRepository&& repository)
{
  size_t j = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    const std::string sql_request = std::string("INSERT INTO Currencies VALUES(") +
      std::to_string(j) + ", '" +
      (**i).GetName() + "', '" +
      (**i).GetCode() + "', " +
      std::to_string((**i).GetActivity()) + ")";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    ++j;
  }
  PLOG_INFO << "Insert currencies to table 'Currencies' in database";
}

//  Class member function
//  Insert one currency to table 'Currencies' in database
void DatabaseManager::InsertCurrencyToTableCurrenciesInDatabase(Currency&& currency)
{

}

//  Class member function
//  Create table 'Descriptions' in database
void DatabaseManager::CreateTableDescriptionsInDatabase()
{
  std::string sql_request = std::string("CREATE TABLE Descriptions(") + 
    "id SERIAL PRIMARY KEY, " +
    "name TEXT NOT NULL, " +
    "counter INTEGER NOT NULL" + ");";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Create table 'Descriptions' in database";
}

//  Class member function
//  Remove table 'Descriptions' in database
void DatabaseManager::RemoveTableDescriptionsInDatabase(DescriptionRepository&& repository)
{
  const std::string sql_request = "TRUNCATE TABLE IF EXISTS Descriptions";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Remove table 'Descriptions' in database if exists";
}

//  Class member function
//  Insert descriptions to table 'Descriptions' in database
void DatabaseManager::InsertDescriptionsToTableDescriptionsInDatabase(DescriptionRepository&& repository)
{
  size_t j = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    const std::string sql_request = std::string("INSERT INTO Descriptions VALUES(") +
      std::to_string(j) + ", '" +
      i->first->GetName() + "', " +
      std::to_string(i->second) + ")";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    ++j;
  }
  PLOG_INFO << "Insert descriptions to table 'Descriptions' in database";
}

//  Class member function
//  Insert one description to table 'Descriptions' in database
void DatabaseManager::InsertDescriptionToTableDescriptionsInDatabase(Description&& description)
{
  int table_rows = SizeOfTable("Descriptions");

  if (table_rows == 0)
  {
    const std::string sql_request = std::string("INSERT INTO Descriptions VALUES(") +
      std::to_string(1) + ", '" +
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
  }
  if (table_rows > 0)
  {
    sqlite3_prepare_v2(database_, "SELECT * FROM Descriptions", -1, &database_stmt_, 0);
    int description_id;
    int description_counter;
    const unsigned char* description_name;
    while (sqlite3_step(database_stmt_) != SQLITE_DONE)
    {
      description_id = sqlite3_column_int(database_stmt_, 0);
      description_name = (sqlite3_column_text(database_stmt_, 1));
      description_counter = sqlite3_column_int(database_stmt_, 2);
      if (description_name == nullptr)
      {
        const std::string sql_request = std::string("INSERT INTO Descriptions VALUES(") +
          std::to_string(1) + ", '" +
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
      }
    }
  }
}

//  Class member function
//  Create table 'Payees' in database
void DatabaseManager::CreateTablePayeesInDatabase()
{
  std::string sql_request = std::string("CREATE TABLE Payees(") + 
    "name TEXT NOT NULL, " +
    "counter INTEGER NOT NULL" + ");";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Create table 'Payees' in database";
}

//  Class member function
//  Remove table 'Payees' in database
void DatabaseManager::RemoveTablePayeesInDatabase(PayeeRepository&& repository)
{
  const std::string sql_request = "TRUNCATE TABLE IF EXISTS Payees";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Remove table 'Payees' in database if exists";
}

//  Class member function
//  Insert payees to table 'Payees' in database
void DatabaseManager::InsertPayeesToTablePayeesInDatabase(PayeeRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertPayeeToTablePayeesInDatabase(std::move(*i->first));
  }
  PLOG_INFO << "Insert payee repository to table 'Payees' in database";
}

//  Class member function
//  Insert one payee to table 'Payees' in database
void DatabaseManager::InsertPayeeToTablePayeesInDatabase(Payee&& payee)
{
  int table_rows = SizeOfTable("Payees");
  int id_start = 1;
  if (table_rows == 0)
  {
    const std::string sql_request = std::string("INSERT INTO Payees VALUES('") +
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
  }
  if (table_rows > 0)
  {
    sqlite3_prepare_v2(database_, "SELECT * FROM Payees", -1, &database_stmt_, 0);
    int payee_counter;
    const unsigned char* payee_name;
    while (sqlite3_step(database_stmt_) != SQLITE_DONE)
    {
      payee_name = (sqlite3_column_text(database_stmt_, 0));
      payee_counter = sqlite3_column_int(database_stmt_, 1);
      if (payee_name == nullptr)
      {
        const std::string sql_request = std::string("INSERT INTO Payees VALUES('") +
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
    const std::string sql_request = std::string("INSERT INTO Payees VALUES('") +
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
//  Create table 'Comments' in database
void DatabaseManager::CreateTableCommentsInDatabase()
{
  std::string sql_request = std::string("CREATE TABLE Comments(") + 
    "id SERIAL PRIMARY KEY, " +
    "name TEXT NOT NULL, " +
    "counter INTEGER NOT NULL" + ");";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Create table 'Comments' in database";
}

//  Class member function
//  Remove table 'Comments' in database
void DatabaseManager::RemoveTableCommentsInDatabase(CommentRepository&& repository)
{
  const std::string sql_request = "TRUNCATE TABLE IF EXISTS Comments";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Remove table 'Comments' in database if exists";
}

//  Class member function
//  Insert comments to table 'Comments' in database
void DatabaseManager::InsertCommentsToTableCommentsInDatabase(CommentRepository&& repository)
{
  size_t j = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    const std::string sql_request = std::string("INSERT INTO Comments VALUES(") +
      std::to_string(j) + ", '" +
      i->first->GetName() + "', " +
      std::to_string(i->second) + ")";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    ++j;
  }
  PLOG_INFO << "Insert comments to table 'Comments' in database";
}

//  Class member function
//  Insert one comment to table 'Comments' in database
void DatabaseManager::InsertCommentToTableCommentsInDatabase(Comment&& comment)
{
  int table_rows = SizeOfTable("Comments");

  if (table_rows == 0)
  {
    const std::string sql_request = std::string("INSERT INTO Comments VALUES(") +
      std::to_string(1) + ", '" +
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
  }
  if (table_rows > 0)
  {
    sqlite3_prepare_v2(database_, "SELECT * FROM Comments", -1, &database_stmt_, 0);
    int comment_id;
    int comment_counter;
    const unsigned char* comment_name;
    while (sqlite3_step(database_stmt_) != SQLITE_DONE)
    {
      comment_id = sqlite3_column_int(database_stmt_, 0);
      comment_name = (sqlite3_column_text(database_stmt_, 1));
      comment_counter = sqlite3_column_int(database_stmt_, 2);
      if (comment_name == nullptr)
      {
        const std::string sql_request = std::string("INSERT INTO Comments VALUES(") +
          std::to_string(1) + ", '" +
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
      }
    }
  }
}

//  Class member function
//  Create table 'Tags' in database
void DatabaseManager::CreateTableTagsInDatabase()
{
  std::string sql_request = std::string("CREATE TABLE Tags(") + 
    "id SERIAL PRIMARY KEY, " +
    "name TEXT NOT NULL, " +
    "counter INTEGER NOT NULL" + ");";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Create table 'Tags' in database";
}

//  Class member function
//  Remove table 'Tags' in database
void DatabaseManager::RemoveTableTagsInDatabase(TagRepository&& repository)
{
  const std::string sql_request = "TRUNCATE TABLE IF EXISTS Tags";
  database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Remove table 'Tags' in database if exists";
}

//  Class member function
//  Insert tags to table 'Tags' in database
void DatabaseManager::InsertTagsToTableTagsInDatabase(TagRepository&& repository)
{
  size_t j = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    const std::string sql_request = std::string("INSERT INTO Tags VALUES(") +
      std::to_string(j) + ", '" +
      i->first->GetName() + "', " +
      std::to_string(i->second) + ")";
    database_status_ = sqlite3_exec(database_, sql_request.c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    ++j;
  }
  PLOG_INFO << "Insert tags to table 'Tags' in database";
}

//  Class member function
//  Insert one tag to table 'Tags' in database
void DatabaseManager::InsertTagToTableTagsInDatabase(Tag&& tag)
{
  int table_rows = SizeOfTable("Tags");

  if (table_rows == 0)
  {
    const std::string sql_request = std::string("INSERT INTO Tags VALUES(") +
      std::to_string(1) + ", '" +
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
  }
  if (table_rows > 0)
  {
    sqlite3_prepare_v2(database_, "SELECT * FROM Tags", -1, &database_stmt_, 0);
    int tag_id;
    int tag_counter;
    const unsigned char* tag_name;
    while (sqlite3_step(database_stmt_) != SQLITE_DONE)
    {
      tag_id = sqlite3_column_int(database_stmt_, 0);
      tag_name = (sqlite3_column_text(database_stmt_, 1));
      tag_counter = sqlite3_column_int(database_stmt_, 2);
      if (tag_name == nullptr)
      {
        const std::string sql_request = std::string("INSERT INTO Tags VALUES(") +
          std::to_string(1) + ", '" +
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
      }
    }
  }
}
