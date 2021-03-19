#include "pch.h"

TEST(AccountTest, TestNameDefault)
{
  std::string name = "Unspecified";
  Account account = Account();
  EXPECT_EQ(name, account.GetName());
  EXPECT_TRUE(true);
}

TEST(AccountTest, TestName)
{
  std::string name = "name";
  Account account = Account("name");
  EXPECT_EQ(name, account.GetName());
  EXPECT_TRUE(true);
}