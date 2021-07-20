#ifndef HOMEBOOKKEEPING_1DATAACCESS_CATEGORYDATABASE_H_
#define HOMEBOOKKEEPING_1DATAACCESS_CATEGORYDATABASE_H_

#include "include/1_DataAccess/DatabaseManager.h"
#include "include/1_DataAccess/CategoryRepository.h"

class CategoryDatabase
{
public:
  void CreateTableCategoriesInDatabase();
  void ClearTableCategoriesInDatabase();
private:
  DatabaseManager* database_manager_;
};

#endif