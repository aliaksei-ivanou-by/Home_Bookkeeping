#ifndef HOMEBOOKKEEPING_1DATAACCESS_DESCRIPTIONDATABASE_H_
#define HOMEBOOKKEEPING_1DATAACCESS_DESCRIPTIONDATABASE_H_

#include "include/1_DataAccess/DatabaseManager.h"
#include "include/1_DataAccess/DescriptionRepository.h"

class DescriptionDatabase
{
public:
  void CreateTableDescriptionsInDatabase();
  void ClearTableDescriptionsInDatabase();
private:
  DatabaseManager* database_manager_;
};

#endif