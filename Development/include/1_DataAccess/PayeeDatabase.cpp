#include "include/1_DataAccess/PayeeDatabase.h"

void PayeeDatabase::CreateTablePayeesInDatabase()
{
  database_manager_->CreateTableInDatabase("Payees");
}

void PayeeDatabase::ClearTablePayeesInDatabase()
{
  database_manager_->ClearTableInDatabase("Payees");
}