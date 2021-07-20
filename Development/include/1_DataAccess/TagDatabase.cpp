#include "include/1_DataAccess/TagDatabase.h"

void TagDatabase::CreateTableTagsInDatabase()
{
  database_manager_->CreateTableInDatabase("Tags");
}

void TagDatabase::ClearTableTagsInDatabase()
{
  database_manager_->ClearTableInDatabase("Tags");
}