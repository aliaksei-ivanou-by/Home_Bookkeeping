#ifndef HOMEBOOKKEEPING_1DATAACCESS_ACCOUNTDATABASE_H_
#define HOMEBOOKKEEPING_1DATAACCESS_ACCOUNTDATABASE_H_

#include "include/1_DataAccess/DatabaseManager.h"
#include "include/1_DataAccess/AccountRepository.h"

class AccountDatabase
{
public:
  AccountDatabase() = delete;
  AccountDatabase(DatabaseManager* database_manager);
  void CreateTableAccountsInDatabase();
  void ClearTableAccountsInDatabase();
private:
  DatabaseManager* database_manager_;
};

#endif