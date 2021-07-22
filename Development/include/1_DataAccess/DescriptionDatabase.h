#ifndef HOMEBOOKKEEPING_1DATAACCESS_DESCRIPTIONDATABASE_H_
#define HOMEBOOKKEEPING_1DATAACCESS_DESCRIPTIONDATABASE_H_

#include "include/1_DataAccess/DatabaseManager.h"
#include "include/1_DataAccess/DescriptionRepository.h"

class DescriptionDatabase
{
public:
  DescriptionDatabase() = delete;
  DescriptionDatabase(DatabaseManager* database_manager);
  void CreateTableDescriptionsInDatabase();
  void ClearTableDescriptionsInDatabase();
  void InsertDescriptionToTableDescriptionsInDatabase(Description&& description);
  void InsertDescriptionsToTableDescriptionsInDatabase(DescriptionRepository&& repository);
  std::tuple<bool, int, Description, int> FindDescriptionInTableDescriptionsInDatabase(const std::string& model_name);
  void SetDescriptionName(const std::string& model_name, const std::string& name);
  std::string GetDescriptionName(const std::string& model_name);
  void RemoveDescriptionFromTableDescriptionsInDatabase(const std::string& model_name);
private:
  DatabaseManager* database_manager_;
};

#endif