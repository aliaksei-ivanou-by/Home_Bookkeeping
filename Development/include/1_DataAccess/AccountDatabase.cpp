#include "include/1_DataAccess/AccountDatabase.h"

AccountDatabase::AccountDatabase(DatabaseManager* database_manager)
{
  database_manager_ = database_manager;
}

void AccountDatabase::CreateTableAccountsInDatabase()
{
  database_manager_->CreateTableInDatabase("Accounts");
}

void AccountDatabase::ClearTableAccountsInDatabase()
{
  database_manager_->ClearTableInDatabase("Accounts");
}