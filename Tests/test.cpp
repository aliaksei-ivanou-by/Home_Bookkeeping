#include "pch.h"

//  Account

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
  EXPECT_TRUE(true);
}

TEST(AccountTest, TestDefaultWithRenameAndReamount)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  double amount_expected = 0.0;
  double amount_expected_rename = 20.0;
  double amount_repository = DBL_MIN;
  //  Act (1)
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
  //  Assert (1)
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_EQ(amount_expected, amount_repository);
  EXPECT_TRUE(true);
  //  Act (2)
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
  //  Assert (2)
  EXPECT_EQ(name_expected_rename, name_repository);
  EXPECT_EQ(amount_expected_rename, amount_repository);
  EXPECT_TRUE(true);
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
  EXPECT_TRUE(true);
}

//  Category

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

//  Currency

TEST(CurrencyTest, TestDefault)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string code_expected = "Unspecified";
  bool activity_expected = false;
  std::string name_repository = "";
  std::string code_repository = "";
  bool activity_repository = false;
  //  Act
  FinanceRepository rep;
  rep.AddCurrency();
  auto iterator_name = rep.FindCurrencyName("Unspecified");
  if (iterator_name != rep.EndCurrencyRepository())
  {
    name_repository = rep.GetCurrencyName(iterator_name);
  }
  auto iterator_code = rep.FindCurrencyCode("Unspecified");
  if (iterator_code != rep.EndCurrencyRepository())
  {
    code_repository = rep.GetCurrencyCode(iterator_name);
  }
  if (iterator_name != rep.EndCurrencyRepository())
  {
    activity_repository = rep.GetCurrencyActivity(iterator_name);
  }
  //  Assert
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
  EXPECT_EQ(code_expected, code_repository);
  EXPECT_TRUE(true);
  EXPECT_EQ(activity_expected, activity_repository);
  EXPECT_TRUE(true);
}

TEST(CurrencyTest, TestDefaultWithRename)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string code_expected = "Unspecified";
  std::string code_expected_rename = "UnspecifiedRename";
  bool activity_expected = false;
  std::string name_repository = "";
  std::string code_repository = "";
  bool activity_repository = false;
  //  Act (1)
  FinanceRepository rep;
  rep.AddCurrency();
  auto iterator_name = rep.FindCurrencyName("Unspecified");
  if (iterator_name != rep.EndCurrencyRepository())
  {
    name_repository = rep.GetCurrencyName(iterator_name);
  }
  auto iterator_code = rep.FindCurrencyCode("Unspecified");
  if (iterator_code != rep.EndCurrencyRepository())
  {
    code_repository = rep.GetCurrencyCode(iterator_name);
  }
  if (iterator_name != rep.EndCurrencyRepository())
  {
    activity_repository = rep.GetCurrencyActivity(iterator_name);
  }
  //  Assert (1)
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
  EXPECT_EQ(code_expected, code_repository);
  EXPECT_TRUE(true);
  EXPECT_EQ(activity_expected, activity_repository);
  EXPECT_TRUE(true);
  //  Act (2)
  rep.SetCurrencyName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindCurrencyName("UnspecifiedRename");
  if (iterator_name_rename != rep.EndCurrencyRepository())
  {
    name_repository = rep.GetCurrencyName(iterator_name_rename);
  }
  rep.SetCurrencyCode(iterator_code, "UnspecifiedRename");
  auto iterator_code_rename = rep.FindCurrencyName("UnspecifiedRename");
  if (iterator_code_rename != rep.EndCurrencyRepository())
  {
    code_repository = rep.GetCurrencyName(iterator_code_rename);
  }
  //  Assert (2)
  EXPECT_EQ(name_expected_rename, name_repository);
  EXPECT_TRUE(true);
  EXPECT_EQ(code_expected_rename, code_repository);
  EXPECT_TRUE(true);
  EXPECT_EQ(activity_expected, activity_repository);
  EXPECT_TRUE(true);
}

TEST(CurrencyTest, TestName)
{
  //  Arrange
  std::string name_expected = "Name1";
  std::string name_repository = "";
  //  Act
  FinanceRepository rep;
  rep.AddCurrency({ "Name1" });
  auto iterator_name = rep.FindCurrencyName("Name1");
  if (iterator_name != rep.EndCurrencyRepository())
  {
    name_repository = rep.GetCurrencyName(iterator_name);
  }
  //  Assert
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}

//  Description

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
  EXPECT_TRUE(true);
}

TEST(DescriptionTest, TestDefaultWithRename)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  //  Act (1)
  FinanceRepository rep;
  rep.AddDescription();
  auto iterator_name = rep.FindDescription("Unspecified");
  if (iterator_name != rep.EndDescriptionRepository())
  {
    name_repository = rep.GetDescriptionName(iterator_name);
  }
  //  Assert (1)
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
  //  Act (2)
  rep.SetDescriptionName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindDescription("UnspecifiedRename");
  if (iterator_name_rename != rep.EndDescriptionRepository())
  {
    name_repository = rep.GetDescriptionName(iterator_name_rename);
  }
  //  Assert (2)
  EXPECT_EQ(name_expected_rename, name_repository);
  EXPECT_TRUE(true);
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
  EXPECT_TRUE(true);
}

//  Payee

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

//  Comment

TEST(CommentTest, TestDefault)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_repository = "";
  //  Act
  FinanceRepository rep;
  rep.AddComment();
  auto iterator_name = rep.FindComment("Unspecified");
  if (iterator_name != rep.EndCommentRepository())
  {
    name_repository = rep.GetCommentName(iterator_name);
  }
  //  Assert
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}

TEST(CommentTest, TestDefaultWithRename)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  //  Act (1)
  FinanceRepository rep;
  rep.AddComment();
  auto iterator_name = rep.FindComment("Unspecified");
  if (iterator_name != rep.EndCommentRepository())
  {
    name_repository = rep.GetCommentName(iterator_name);
  }
  //  Assert (1)
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
  //  Act (2)
  rep.SetCommentName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindComment("UnspecifiedRename");
  if (iterator_name_rename != rep.EndCommentRepository())
  {
    name_repository = rep.GetCommentName(iterator_name_rename);
  }
  //  Assert (2)
  EXPECT_EQ(name_expected_rename, name_repository);
  EXPECT_TRUE(true);
}

TEST(CommentTest, TestName)
{
  //  Arrange
  std::string name_expected = "Name1";
  std::string name_repository = "";
  //  Act
  FinanceRepository rep;
  rep.AddComment({ "Name1" });
  auto iterator_name = rep.FindComment("Name1");
  if (iterator_name != rep.EndCommentRepository())
  {
    name_repository = rep.GetCommentName(iterator_name);
  }
  //  Assert
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}

//  Tag

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
  EXPECT_TRUE(true);
}

TEST(TagTest, TestDefaultWithRename)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  //  Act (1)
  FinanceRepository rep;
  rep.AddTag();
  auto iterator_name = rep.FindTag("Unspecified");
  if (iterator_name != rep.EndTagRepository())
  {
    name_repository = rep.GetTagName(iterator_name);
  }
  //  Assert (1)
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
  //  Act (2)
  rep.SetTagName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindTag("UnspecifiedRename");
  if (iterator_name_rename != rep.EndTagRepository())
  {
    name_repository = rep.GetTagName(iterator_name_rename);
  }
  //  Assert (2)
  EXPECT_EQ(name_expected_rename, name_repository);
  EXPECT_TRUE(true);
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
  EXPECT_TRUE(true);
}

//  Transaction

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
  rep.AddTransaction(tr);
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