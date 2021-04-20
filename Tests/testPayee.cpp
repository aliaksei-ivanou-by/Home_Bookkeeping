#include "pch.h"

TEST(PayeeTest, TestDefault)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_repository = "";
  //  Act
  FinanceRepository rep;
  rep.AddPayee();
  auto iterator_name = rep.FindPayee("Unspecified");
  if (iterator_name != rep.EndPayeeRepository())
  {
    name_repository = rep.GetPayeeName(iterator_name);
  }
  //  Assert
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}

TEST(PayeeTest, TestDefaultWithRename)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  //  Act (1)
  FinanceRepository rep;
  rep.AddPayee();
  auto iterator_name = rep.FindPayee("Unspecified");
  if (iterator_name != rep.EndPayeeRepository())
  {
    name_repository = rep.GetPayeeName(iterator_name);
  }
  //  Assert (1)
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
  //  Act (2)
  rep.SetPayeeName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindPayee("UnspecifiedRename");
  if (iterator_name_rename != rep.EndPayeeRepository())
  {
    name_repository = rep.GetPayeeName(iterator_name_rename);
  }
  //  Assert (2)
  EXPECT_EQ(name_expected_rename, name_repository);
  EXPECT_TRUE(true);
}

TEST(PayeeTest, TestName)
{
  //  Arrange
  std::string name_expected = "Name1";
  std::string name_repository = "";
  //  Act
  FinanceRepository rep;
  rep.AddPayee({ "Name1" });
  auto iterator_name = rep.FindPayee("Name1");
  if (iterator_name != rep.EndPayeeRepository())
  {
    name_repository = rep.GetPayeeName(iterator_name);
  }
  //  Assert
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}