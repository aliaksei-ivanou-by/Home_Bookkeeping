#include "include/1_DataAccess/CurrencyDatabase.h"

void CurrencyDatabase::CreateTableCurrenciesInDatabase()
{
  database_manager_->CreateTableInDatabase("Currencies");
}

void CurrencyDatabase::ClearTableCurrenciesInDatabase()
{
  database_manager_->ClearTableInDatabase("Currencies");
}