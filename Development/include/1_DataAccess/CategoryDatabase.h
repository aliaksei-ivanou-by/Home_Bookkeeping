#ifndef HOMEBOOKKEEPING_1DATAACCESS_CATEGORYDATABASE_H_
#define HOMEBOOKKEEPING_1DATAACCESS_CATEGORYDATABASE_H_

#include "include/1_DataAccess/DatabaseManager.h"
#include "include/1_DataAccess/CategoryRepository.h"

class CategoryDatabase
{
public:
  CategoryDatabase() = delete;
  CategoryDatabase(DatabaseManager* database_manager);
  void CreateTableCategoriesInDatabase();
  void ClearTableCategoriesInDatabase();
  void InsertCategoryToTableCategoriesInDatabase(Category&& category);
  void InsertCategoriesToTableCategoriesInDatabase(CategoryRepository&& repository);
  std::tuple<bool, int, Category, int> FindCategoryInTableCategoriesInDatabase(const std::string& model_name);
  void SetCategoryName(const std::string& model_name, const std::string& name);
  std::string GetCategoryName(const std::string& model_name);
  void RemoveCategoryFromTableCategoriesInDatabase(const std::string& model_name);
private:
  DatabaseManager* database_manager_;
};

#endif