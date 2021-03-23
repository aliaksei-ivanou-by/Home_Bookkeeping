#include "pch.h"

TEST(AccountTest, TestNameDefault)
{
  std::string name_expected = "Unspecified";
  double amount_expected = 0.0;
  FinanceRepository rep;
  rep.AddAccount();
  auto name_repository = rep.GetAccountName(rep.FindAccount("Unspecified"));
  auto amount_repository = rep.GetAccountAmount(rep.FindAccount("Unspecified"));
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_EQ(amount_expected, amount_repository);
  EXPECT_TRUE(true);
}

TEST(AccountTest, TestName)
{
  std::string name_expected = "Name1";
  double amount_expected = 15.0;
  FinanceRepository rep;
  rep.AddAccount({ "Name1", 15.0 });
  auto name_repository = rep.GetAccountName(rep.FindAccount("Name1"));
  auto amount_repository = rep.GetAccountAmount(rep.FindAccount("Name1"));
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_EQ(amount_expected, amount_repository);
  EXPECT_TRUE(true);
}

TEST(TagTest, TestNameDefault)
{
  std::string name_expected = "Unspecified";
  FinanceRepository rep;
  rep.AddTag();
  auto name_repository = rep.GetTagName(rep.FindTag("Unspecified"));
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}

TEST(TagTest, TestName)
{
  std::string name_expected = "Name1";
  FinanceRepository rep;
  rep.AddTag({ "Name1" });
  auto name_repository = rep.GetTagName(rep.FindTag("Name1"));
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}