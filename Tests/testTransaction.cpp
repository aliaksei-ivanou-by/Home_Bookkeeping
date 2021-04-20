#include "pch.h"

TEST(TransactionTest, TestAddOneTransactionType1)
{
  //  Arrange
  std::string account_expected = "BYN Cash";
  std::string category_expected = "Bills";
  double amount_expected = 10.0;
  std::string account_repository = "";
  std::string category_repository = "";
  double amount_repository = DBL_MIN;
  //  Act
  FinanceRepository rep;
  Transaction tr({ "BYN Cash" }, { "Bills" }, 10);
  rep.AddTransaction(std::move(tr));
  auto iterator_account = rep.FindAccount(account_expected);
  if (iterator_account != rep.EndAccountRepository())
  {
    account_repository = rep.GetAccountName(iterator_account);
  }
  auto iterator_category = rep.FindCategory(category_expected);
  if (iterator_category != rep.EndCategoryRepository())
  {
    category_repository = rep.GetCategoryName(iterator_category);
  }
  //  Assert
  EXPECT_EQ(account_expected, account_repository);
  EXPECT_TRUE(true);
  EXPECT_EQ(category_expected, category_repository);
  EXPECT_TRUE(true);
}