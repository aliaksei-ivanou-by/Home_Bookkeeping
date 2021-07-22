#ifndef HOMEBOOKKEEPING_1DATAACCESS_DATABASEMANAGER_H_
#define HOMEBOOKKEEPING_1DATAACCESS_DATABASEMANAGER_H_

#include "lib/sqlite/sqlite3.h"
#include "lib/logger/Log.h"
#include "lib/logger/Initializers/RollingFileInitializer.h"

#include "AccountRepository.h"
#include "TransactionRepository.h"

class DatabaseManager
{
public:
  DatabaseManager();
  ~DatabaseManager();

  int SizeOfTable(const std::string& table);
  void CreateTableInDatabase(const std::string& table);
  void CreateAllTablesInDatabase();
  void ClearTableInDatabase(const std::string& table);
  void ClearAllTablesInDatabase();
  bool CheckTableForExistenceInDatabase(const std::string& table);

  void InsertTransactionToTableTransactionsInDatabase(Transaction&& transaction);
  void InsertTransactionsToTableTransactionsInDatabase(TransactionRepository&& repository);
  std::tuple<bool, int, Transaction> FindTransactionInTableTransactionsInDatabase(const int id);
  void RemoveTransactionFromTableTransactionsInDatabase(const int id);
private:
  char* database_error_;
  int database_status_;
  sqlite3* database_;
  sqlite3_stmt* database_stmt_;

  friend class ModelDatabase;
  friend class AccountDatabase;
  friend class CategoryDatabase;
  friend class CommentDatabase;
  friend class CurrencyDatabase;
  friend class DescriptionDatabase;
  friend class PayeeDatabase;
  friend class TagDatabase;
  friend class TransactionDatabase;
};

#endif
