#include <gtest/gtest.h>

#include "include/2_BusinessLogic/FinanceRepository.h"

extern FinanceRepository repository;

TEST(CategoryTest, TestDefault)
{
  //  Arrange
  std::string expected_name = Category().GetName();

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddCategory();
  bool repository_model_is_in_table = false;
  std::tie(repository_model_is_in_table, std::ignore, std::ignore, std::ignore) = repository.FindCategory(expected_name);

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
}

TEST(CategoryTest, TestDefaultWithRename)
{
  //  Arrange
  std::string expected_name = "Category";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddCategory();
  bool repository_model_is_in_table_old = false;
  bool repository_model_is_in_table_new = false;
  std::tie(repository_model_is_in_table_old, std::ignore, std::ignore, std::ignore) = repository.FindCategory(Category().GetName());
  if (repository_model_is_in_table_old)
  {
    repository.SetCategoryName(Category().GetName(), expected_name);
    std::tie(repository_model_is_in_table_new, std::ignore, std::ignore, std::ignore) = repository.FindCategory(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table_new, true);
}

TEST(CategoryTest, TestWithRename)
{
  //  Arrange
  std::string expected_name = "Category";

  //  Act
  repository.ClearTablesInDatabase();
  const std::string model_name = "Category_Old";
  repository.AddCategory(Category(model_name));
  bool repository_model_is_in_table_old = false;
  bool repository_model_is_in_table_new = false;
  std::tie(repository_model_is_in_table_old, std::ignore, std::ignore, std::ignore) = repository.FindCategory(model_name);
  if (repository_model_is_in_table_old)
  {
    repository.SetCategoryName(model_name, expected_name);
    std::tie(repository_model_is_in_table_new, std::ignore, std::ignore, std::ignore) = repository.FindCategory(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table_new, true);
}

TEST(CategoryTest, TestAddCategoryAndRemove)
{
  //  Arrange
  std::string expected_name = "Category";

  //Act
  repository.ClearTablesInDatabase();
  repository.AddCategory(expected_name);
  bool repository_model_is_in_table = false;
  bool repository_model_not_is_in_table = true;
  std::tie(repository_model_is_in_table, std::ignore, std::ignore, std::ignore) = repository.FindCategory(expected_name);
  if (repository_model_is_in_table)
  {
    repository.RemoveCategory(expected_name);
    std::tie(repository_model_not_is_in_table, std::ignore, std::ignore, std::ignore) = repository.FindCategory(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_not_is_in_table, false);
}