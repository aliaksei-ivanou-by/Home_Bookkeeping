#include "pch.h"

TEST(DescriptionTest, TestDefault)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_repository = "";

  //  Act
  FinanceRepository rep;
  rep.AddDescription();
  auto iterator_name = rep.FindDescription("Unspecified");
  if (iterator_name != rep.EndDescriptionRepository())
  {
    name_repository = rep.GetDescriptionName(iterator_name);
  }

  //  Assert
  EXPECT_EQ(name_expected, name_repository);
}

TEST(DescriptionTest, TestDefaultWithRename)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  std::string name_repository_rename = "";

  //  Act
  FinanceRepository rep;
  rep.AddDescription();
  auto iterator_name = rep.FindDescription("Unspecified");
  if (iterator_name != rep.EndDescriptionRepository())
  {
    name_repository = rep.GetDescriptionName(iterator_name);
  }
  rep.SetDescriptionName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindDescription("UnspecifiedRename");
  if (iterator_name_rename != rep.EndDescriptionRepository())
  {
    name_repository_rename = rep.GetDescriptionName(iterator_name_rename);
  }

  //  Assert
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_EQ(name_expected_rename, name_repository_rename);
}

TEST(DescriptionTest, TestName)
{
  //  Arrange
  std::string name_expected = "Name1";
  std::string name_repository = "";

  // Act
  FinanceRepository rep;
  rep.AddDescription({ "Name1" });
  auto iterator_name = rep.FindDescription("Name1");
  if (iterator_name != rep.EndDescriptionRepository())
  {
    name_repository = rep.GetDescriptionName(iterator_name);
  }

  //  Assert
  EXPECT_EQ(name_expected, name_repository);
}
