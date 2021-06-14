#include "pch.h"

extern FinanceRepository repository;

TEST(CategoryTest, TestDefault)
{
  //  Arrange
  std::string expected_name = "Unspecified";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddCategory();
  bool repository_is_in_table;
  int repository_category_id;
  Category repository_category;
  int repository_category_counter;
  std::tie(repository_is_in_table, repository_category_id, repository_category, repository_category_counter) = repository.FindCategory("Unspecified");

  //  Assert
  EXPECT_EQ(repository_is_in_table, true);
  EXPECT_EQ(expected_name, repository_category.GetName());
}

TEST(CategoryTest, TestDefaultWithRename)
{
  //  Arrange
  std::string expected_name = "Category";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddCategory();
  bool repository_is_in_table;
  int repository_category_id;
  Category repository_category;
  int repository_category_counter;
  std::tie(repository_is_in_table, repository_category_id, repository_category, repository_category_counter) = repository.FindCategory("Unspecified");
  repository.SetCategoryName("Unspecified", "Category");
  std::tie(repository_is_in_table, repository_category_id, repository_category, repository_category_counter) = repository.FindCategory("Category");

  //  Assert
  EXPECT_EQ(repository_is_in_table, true);
  EXPECT_EQ(expected_name, repository_category.GetName());
}

TEST(CategoryTest, TestWithRename)
{
  //  Arrange
  std::string expected_name = "Category";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddCategory(Category("Unspecified_category"));
  bool repository_is_in_table;
  int repository_category_id;
  Category repository_category;
  int repository_category_counter;
  std::tie(repository_is_in_table, repository_category_id, repository_category, repository_category_counter) = repository.FindCategory("Unspecified_category");
  repository.SetCategoryName("Unspecified_category", "Category");
  std::tie(repository_is_in_table, repository_category_id, repository_category, repository_category_counter) = repository.FindCategory("Category");

  //  Assert
  EXPECT_EQ(repository_is_in_table, true);
  EXPECT_EQ(expected_name, repository_category.GetName());
}