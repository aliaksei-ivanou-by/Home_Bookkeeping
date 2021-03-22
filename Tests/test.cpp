#include "pch.h"

TEST(AccountTest, TestNameDefault)
{
  std::string name_expected = "Unspecified";
  FinanceRepository rep;
  rep.AddAccount();
  auto name_repository = rep.GetAccountName(rep.FindAccount("Unspecified"));
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}

TEST(AccountTest, TestName)
{
  std::string name = "name";
  Account account = Account("name");
  EXPECT_EQ(name, account.GetName());
  EXPECT_TRUE(true);
}