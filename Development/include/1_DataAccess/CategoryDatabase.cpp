#include "include/1_DataAccess/CategoryDatabase.h"

void CategoryDatabase::CreateTableCategoriesInDatabase()
{
  database_manager_->CreateTableInDatabase("Categories");
}

void CategoryDatabase::ClearTableCategoriesInDatabase()
{
  database_manager_->ClearTableInDatabase("Categories");
}