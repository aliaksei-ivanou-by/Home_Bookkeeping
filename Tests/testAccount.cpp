#include "pch.h"

TEST(AccountTest, TestDefault)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_repository = "";
  double amount_expected = 0.0;
  double amount_repository = DBL_MIN;

  //  Act
  FinanceRepository rep;
  rep.AddAccount();
  auto iterator_name = rep.FindAccount("Unspecified");
  if (iterator_name != rep.EndAccountRepository())
  {
    name_repository = rep.GetAccountName(iterator_name);
  }
  auto iterator_amount = rep.FindAccount("Unspecified");
  if (iterator_amount != rep.EndAccountRepository())
  {
    amount_repository = rep.GetAccountAmount(iterator_amount);
  }

  //  Assert
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_EQ(amount_expected, amount_repository);
}

TEST(AccountTest, TestDefaultWithRenameAndReamount)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  std::string name_repository_rename = "";
  double amount_expected = 0.0;
  double amount_expected_rename = 20.0;
  double amount_repository = DBL_MIN;
  double amount_repository_rename = DBL_MIN;

  //  Act
  FinanceRepository rep;
  rep.AddAccount();
  auto iterator_name = rep.FindAccount("Unspecified");
  if (iterator_name != rep.EndAccountRepository())
  {
    name_repository = rep.GetAccountName(iterator_name);
  }
  auto iterator_amount = rep.FindAccount("Unspecified");
  if (iterator_amount != rep.EndAccountRepository())
  {
    amount_repository = rep.GetAccountAmount(iterator_amount);
  }
  rep.SetAccountName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindAccount("UnspecifiedRename");
  if (iterator_name_rename != rep.EndAccountRepository())
  {
    name_repository_rename = rep.GetAccountName(iterator_name_rename);
  }
  rep.SetAccountAmount(iterator_name, 20.0);
  auto iterator_amount_rename = rep.FindAccount("UnspecifiedRename");
  if (iterator_amount_rename != rep.EndAccountRepository())
  {
    amount_repository_rename = rep.GetAccountAmount(iterator_name_rename);
  }

  //  Assert
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_EQ(amount_expected, amount_repository);
  EXPECT_EQ(name_expected_rename, name_repository_rename);
  EXPECT_EQ(amount_expected_rename, amount_repository_rename);
}

TEST(AccountTest, TestNameAndAmount)
{
  //  Arrange
  std::string name_expected = "Name";
  std::string name_repository = "";
  double amount_expected = 15.0;
  double amount_repository = DBL_MIN;

  //  Act
  FinanceRepository rep;
  rep.AddAccount({ "Name", 15.0 });
  auto iterator_name = rep.FindAccount("Name");
  if (iterator_name != rep.EndAccountRepository())
  {
    name_repository = rep.GetAccountName(iterator_name);
  }
  auto iterator_amount = rep.FindAccount("Name");
  if (iterator_amount != rep.EndAccountRepository())
  {
    amount_repository = rep.GetAccountAmount(iterator_amount);
  }

  //  Assert
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_EQ(amount_expected, amount_repository);
}
