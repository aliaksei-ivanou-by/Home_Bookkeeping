#include "pch.h"

TEST(TagTest, TestDefault)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_repository = "";

  //  Act
  FinanceRepository rep;
  rep.AddTag();
  auto iterator_name = rep.FindTag("Unspecified");
  if (iterator_name != rep.EndTagRepository())
  {
    name_repository = rep.GetTagName(iterator_name);
  }

  //  Assert
  EXPECT_EQ(name_expected, name_repository);
}

TEST(TagTest, TestDefaultWithRename)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  std::string name_repository_rename = "";

  //  Act
  FinanceRepository rep;
  rep.AddTag();
  auto iterator_name = rep.FindTag("Unspecified");
  if (iterator_name != rep.EndTagRepository())
  {
    name_repository = rep.GetTagName(iterator_name);
  }
  rep.SetTagName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindTag("UnspecifiedRename");
  if (iterator_name_rename != rep.EndTagRepository())
  {
    name_repository_rename = rep.GetTagName(iterator_name_rename);
  }

  //  Assert
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_EQ(name_expected_rename, name_repository_rename);
}

TEST(TagTest, TestName)
{
  //  Arrange
  std::string name_expected = "Name1";
  std::string name_repository = "";

  //  Act
  FinanceRepository rep;
  rep.AddTag({ "Name1" });
  auto iterator_name = rep.FindTag("Name1");
  if (iterator_name != rep.EndTagRepository())
  {
    name_repository = rep.GetTagName(iterator_name);
  }

  //  Assert
  EXPECT_EQ(name_expected, name_repository);
}
