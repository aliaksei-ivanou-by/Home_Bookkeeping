#ifndef HOMEBOOKKEEPING_1DATAACCESS_TAGDATABASE_H_
#define HOMEBOOKKEEPING_1DATAACCESS_TAGDATABASE_H_

#include "include/1_DataAccess/DatabaseManager.h"
#include "include/1_DataAccess/TagRepository.h"

class TagDatabase
{
public:
  void CreateTableTagsInDatabase();
  void ClearTableTagsInDatabase();
private:
  DatabaseManager* database_manager_;
};

#endif