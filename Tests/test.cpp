#include "pch.h"

TEST(AccountTest, TestNameDefault)
{
  std::string name_expected = "Unspecified";
  std::string name_repository = "";
  double amount_expected = 0.0;
  double amount_repository = DBL_MIN;
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
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_EQ(amount_expected, amount_repository);
  EXPECT_TRUE(true);
}

TEST(AccountTest, TestNameDefaultWithRenameAndReamount)
{
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  double amount_expected = 0.0;
  double amount_expected_rename = 20.0;
  double amount_repository = DBL_MIN;
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
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_EQ(amount_expected, amount_repository);
  EXPECT_TRUE(true);
  rep.SetAccountName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindAccount("UnspecifiedRename");
  if (iterator_name_rename != rep.EndAccountRepository())
  {
    name_repository = rep.GetAccountName(iterator_name_rename);
  }
  rep.SetAccountAmount(iterator_name, 20.0);
  auto iterator_amount_rename = rep.FindAccount("UnspecifiedRename");
  if (iterator_amount_rename != rep.EndAccountRepository())
  {
    amount_repository = rep.GetAccountAmount(iterator_name_rename);
  }
  EXPECT_EQ(name_expected_rename, name_repository);
  EXPECT_EQ(amount_expected_rename, amount_repository);
  EXPECT_TRUE(true);
}

TEST(AccountTest, TestName)
{
  std::string name_expected = "Name";
  std::string name_repository = "";
  double amount_expected = 15.0;
  double amount_repository = DBL_MIN;
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
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_EQ(amount_expected, amount_repository);
  EXPECT_TRUE(true);
}

TEST(TagTest, TestNameDefault)
{
  std::string name_expected = "Unspecified";
  std::string name_repository = "";
  FinanceRepository rep;
  rep.AddTag();
  auto iterator_name = rep.FindTag("Unspecified");
  if (iterator_name != rep.EndTagRepository())
  {
    name_repository = rep.GetTagName(iterator_name);
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}

TEST(TagTest, TestNameDefaultWithRename)
{
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  FinanceRepository rep;
  rep.AddTag();
  auto iterator_name = rep.FindTag("Unspecified");
  if (iterator_name != rep.EndTagRepository())
  {
    name_repository = rep.GetTagName(iterator_name);
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
  rep.SetTagName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindTag("UnspecifiedRename");
  if (iterator_name_rename != rep.EndTagRepository())
  {
    name_repository = rep.GetTagName(iterator_name_rename);
  }
  EXPECT_EQ(name_expected_rename, name_repository);
  EXPECT_TRUE(true);
}

TEST(TagTest, TestName)
{
  std::string name_expected = "Name1";
  std::string name_repository = "";
  FinanceRepository rep;
  rep.AddTag({ "Name1" });
  auto iterator_name = rep.FindTag("Name1");
  if (iterator_name != rep.EndTagRepository())
  {
    name_repository = rep.GetTagName(rep.FindTag("Name1"));
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}