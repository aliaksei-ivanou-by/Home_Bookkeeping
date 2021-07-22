#ifndef HOMEBOOKKEEPING_1DATAACCESS_TAGDATABASE_H_
#define HOMEBOOKKEEPING_1DATAACCESS_TAGDATABASE_H_

#include "include/1_DataAccess/DatabaseManager.h"
#include "include/1_DataAccess/TagRepository.h"

class TagDatabase
{
public:
  TagDatabase() = delete;
  TagDatabase(DatabaseManager* database_manager);
  void CreateTableTagsInDatabase();
  void ClearTableTagsInDatabase();
  void InsertTagToTableTagsInDatabase(Tag&& tag);
  void InsertTagsToTableTagsInDatabase(TagRepository&& repository);
  std::tuple<bool, int, Tag, int> FindTagInTableTagsInDatabase(const std::string& model_name);
  void SetTagName(const std::string& model_name, const std::string& name);
  std::string GetTagName(const std::string& model_name);
  void RemoveTagFromTableTagsInDatabase(const std::string& model_name);
private:
  DatabaseManager* database_manager_;
};

#endif