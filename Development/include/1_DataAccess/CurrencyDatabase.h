#ifndef HOMEBOOKKEEPING_1DATAACCESS_CURRENCYDATABASE_H_
#define HOMEBOOKKEEPING_1DATAACCESS_CURRENCYDATABASE_H_

#include "include/1_DataAccess/DatabaseManager.h"
#include "include/1_DataAccess/CurrencyRepository.h"

class CurrencyDatabase
{
public:
  void CreateTableCurrenciesInDatabase();
  void ClearTableCurrenciesInDatabase();
private:
  DatabaseManager* database_manager_;
};

#endif