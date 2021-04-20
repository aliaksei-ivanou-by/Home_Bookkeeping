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
  EXPECT_TRUE(true);
}

TEST(CategoryTest, TestDefaultWithRename)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  //  Act (1)
  FinanceRepository rep;
  rep.AddCategory();
  auto iterator_name = rep.FindCategory("Unspecified");
  if (iterator_name != rep.EndCategoryRepository())
  {
    name_repository = rep.GetCategoryName(iterator_name);
  }
  //  Assert (1)
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
  //  Act (2)
  rep.SetCategoryName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindCategory("UnspecifiedRename");
  if (iterator_name_rename != rep.EndCategoryRepository())
  {
    name_repository = rep.GetCategoryName(iterator_name_rename);
  }
  //  Assert (2)
  EXPECT_EQ(name_expected_rename, name_repository);
  EXPECT_TRUE(true);
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
  EXPECT_TRUE(true);
}