#ifndef HOMEBOOKKEEPING_1DATAACCESS_TRANSACTIONDATABASE_H_
#define HOMEBOOKKEEPING_1DATAACCESS_TRANSACTIONDATABASE_H_

#include "include/1_DataAccess/DatabaseManager.h"
#include "include/1_DataAccess/TransactionRepository.h"

class TransactionDatabase
{
public:
  void CreateTableTransactionsInDatabase();
  void ClearTableTransactionsInDatabase();
private:
  DatabaseManager* database_manager_;
};

#endif