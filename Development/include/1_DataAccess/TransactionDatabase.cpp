#include "include/1_DataAccess/TransactionDatabase.h"

void TransactionDatabase::CreateTableTransactionsInDatabase()
{
  database_manager_->CreateTableInDatabase("Transactions");
}

void TransactionDatabase::ClearTableTransactionsInDatabase()
{
  database_manager_->ClearTableInDatabase("Transactions");
}