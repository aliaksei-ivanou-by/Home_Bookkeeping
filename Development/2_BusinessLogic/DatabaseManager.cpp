#include "home_bookkeeping/2_BusinessLogic/DatabaseManager.h"

DatabaseManager::DatabaseManager():
  err_{ 0 },
  rc_{ 0 },
  database_{ nullptr },
  database_stmt_{ nullptr }
{
  sqlite3_open("database.db", &database_);
  PLOG_INFO << "Open database";
}

DatabaseManager::~DatabaseManager()
{
  sqlite3_close(database_);
  PLOG_INFO << "Close database";
}

void DatabaseManager::CreateTableTransactionInDatabase(TransactionRepository repository)
{
  int rc = sqlite3_exec(database_, repository.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &err_);
  if (rc != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << err_;
  }
}

void DatabaseManager::RemoveTableTransactionInDatabase(TransactionRepository repository)
{
  int rc = sqlite3_exec(database_, repository.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &err_);
  if (rc != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << err_;
  }
}

void DatabaseManager::InsertTransactionToTableTransactionInDatabase(TransactionRepository repository)
{
  size_t j = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    std::string str = repository.MakeCommandToInsertRepositoryToDatabase(j, i);
    rc_ = sqlite3_exec(database_, str.c_str(), NULL, NULL, &err_);
    if (rc_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << err_;
    }
    ++j;
  }
}

void DatabaseManager::SaveToDatabaseTransactions(TransactionRepository repository)
{
  RemoveTableTransactionInDatabase(repository);
  CreateTableTransactionInDatabase(repository);
  InsertTransactionToTableTransactionInDatabase(repository);
  PLOG_INFO << "Save transactions to database";
}