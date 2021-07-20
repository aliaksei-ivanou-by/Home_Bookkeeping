#ifndef HOMEBOOKKEEPING_1DATAACCESS_COMMENTDATABASE_H_
#define HOMEBOOKKEEPING_1DATAACCESS_COMMENTDATABASE_H_

#include "include/1_DataAccess/DatabaseManager.h"
#include "include/1_DataAccess/CommentRepository.h"

class CommentDatabase
{
public:
  void CreateTableCommentsInDatabase();
  void ClearTableCommentsInDatabase();
private:
  DatabaseManager* database_manager_;
};

#endif