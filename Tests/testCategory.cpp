#include "pch.h"

extern FinanceRepository repository;

TEST(CategoryTest, TestDefault)
{
  //  Arrange
  std::string expected_name = Category().GetName();

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddCategory();
  bool repository_model_is_in_table;
  int repository_model_id;
  Category repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindCategory(expected_name);

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
}

TEST(CategoryTest, TestDefaultWithRename)
{
  //  Arrange
  std::string expected_name = "Category";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddCategory();
  bool repository_model_is_in_table;
  int repository_model_id;
  Category repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindCategory(Category().GetName());
  if (repository_model_is_in_table)
  {
    repository.SetCategoryName(Category().GetName(), expected_name);
    std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindCategory(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
}

TEST(CategoryTest, TestWithRename)
{
  //  Arrange
  std::string expected_name = "Category";

  //  Act
  repository.ClearTablesInDatabase();
  const std::string model_name = "Category_Old";
  repository.AddCategory(Category(model_name));
  bool repository_model_is_in_table;
  int repository_model_id;
  Category repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindCategory(model_name);
  if (repository_model_is_in_table)
  {
    repository.SetCategoryName(model_name, expected_name);
    std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindCategory(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
}

TEST(CategoryTest, TestAddCategoryAndRemove)
{
  //  Arrange
  std::string expected_name = "Category";

  //Act
  repository.ClearTablesInDatabase();
  repository.AddCategory(expected_name);
  bool repository_model_is_in_table;
  bool repository_model_not_is_in_table;
  int repository_model_id;
  Category repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindCategory(expected_name);
  if (repository_model_is_in_table)
  {
    repository.RemoveCategory(expected_name);
    std::tie(repository_model_not_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindCategory(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(repository_model_not_is_in_table, false);
}