#include "include/1_DataAccess/CommentDatabase.h"

void CommentDatabase::CreateTableCommentsInDatabase()
{
  database_manager_->CreateTableInDatabase("Comments");
}

void CommentDatabase::ClearTableCommentsInDatabase()
{
  database_manager_->ClearTableInDatabase("Comments");
}