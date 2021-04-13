#ifndef HOMEBOOKKEEPING_2BUSINESSLOGIC_DATABASEMANAGER_H_
#define HOMEBOOKKEEPING_2BUSINESSLOGIC_DATABASEMANAGER_H_

#include "home_bookkeeping/1_DataAccess/AccountRepository.h"
#include "home_bookkeeping/1_DataAccess/CategoryRepository.h"
#include "home_bookkeeping/1_DataAccess/CommentRepository.h"
#include "home_bookkeeping/1_DataAccess/CurrencyRepository.h"
#include "home_bookkeeping/1_DataAccess/DescriptionRepository.h"
#include "home_bookkeeping/1_DataAccess/PayeeRepository.h"
#include "home_bookkeeping/1_DataAccess/TagRepository.h"
#include "home_bookkeeping/1_DataAccess/TransactionRepository.h"

#include "home_bookkeeping/lib/sqlite/sqlite3.h"
#include "home_bookkeeping/lib/logger/Log.h"
#include "home_bookkeeping/lib/logger/Initializers/RollingFileInitializer.h"

class DatabaseManager
{
public:
  DatabaseManager();
  ~DatabaseManager();
  void SaveToDatabaseTransactions(TransactionRepository repository);
  void CreateTableTransactionInDatabase(TransactionRepository repository);
  void RemoveTableTransactionInDatabase(TransactionRepository repository);
  void InsertTransactionToTableTransactionInDatabase(TransactionRepository repository);
private:
  char* err_;
  int rc_;
  sqlite3* database_;
  sqlite3_stmt* database_stmt_;
};

#endif  //  HOMEBOOKKEEPING_2BUSINESSLOGIC_DATABASEMANAGER_H_
