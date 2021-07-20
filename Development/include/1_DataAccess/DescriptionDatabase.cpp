#include "include/1_DataAccess/DescriptionDatabase.h"

void DescriptionDatabase::CreateTableDescriptionsInDatabase()
{
  database_manager_->CreateTableInDatabase("Descriptions");
}

void DescriptionDatabase::ClearTableDescriptionsInDatabase()
{
  database_manager_->ClearTableInDatabase("Descriptions");
}