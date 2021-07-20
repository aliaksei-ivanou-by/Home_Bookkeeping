#ifndef HOMEBOOKKEEPING_1DATAACCESS_PAYEEDATABASE_H_
#define HOMEBOOKKEEPING_1DATAACCESS_PAYEEDATABASE_H_

#include "include/1_DataAccess/DatabaseManager.h"
#include "include/1_DataAccess/PayeeRepository.h"

class PayeeDatabase
{
public:
  void CreateTablePayeesInDatabase();
  void ClearTablePayeesInDatabase();
private:
  DatabaseManager* database_manager_;
};

#endif