#include "pch.h"

TEST(CategoryTest, TestDefault)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_repository = "";

  //  Act
  FinanceRepository rep;
  rep.AddCategory();
  auto iterator_name = rep.FindCategory("Unspecified");
  if (iterator_name != rep.EndCategoryRepository())
  {
    name_repository = rep.GetCategoryName(iterator_name);
  }

  //  Assert
  EXPECT_EQ(name_expected, name_repository);
}

TEST(CategoryTest, TestDefaultWithRename)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  std::string name_repository_rename = "";

  //  Act
  FinanceRepository rep;
  rep.AddCategory();
  auto iterator_name = rep.FindCategory("Unspecified");
  if (iterator_name != rep.EndCategoryRepository())
  {
    name_repository = rep.GetCategoryName(iterator_name);
  }
  rep.SetCategoryName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindCategory("UnspecifiedRename");
  if (iterator_name_rename != rep.EndCategoryRepository())
  {
    name_repository_rename = rep.GetCategoryName(iterator_name_rename);
  }
  //  Assert
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_EQ(name_expected_rename, name_repository_rename);
}

TEST(CategoryTest, TestName)
{
  //  Arrange
  std::string name_expected = "Name1";
  std::string name_repository = "";

  //  Act
  FinanceRepository rep;
  rep.AddCategory({ "Name1" });
  auto iterator_name = rep.FindCategory("Name1");
  if (iterator_name != rep.EndCategoryRepository())
  {
    name_repository = rep.GetCategoryName(iterator_name);
  }

  //  Assert
  EXPECT_EQ(name_expected, name_repository);
}
