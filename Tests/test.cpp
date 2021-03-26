#include "pch.h"

//  Account

TEST(AccountTest, TestDefault)
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

TEST(AccountTest, TestDefaultWithRenameAndReamount)
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

TEST(AccountTest, TestNameAndAmount)
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

//  Category

TEST(CategoryTest, TestDefault)
{
  std::string name_expected = "Unspecified";
  std::string name_repository = "";
  FinanceRepository rep;
  rep.AddCategory();
  auto iterator_name = rep.FindCategory("Unspecified");
  if (iterator_name != rep.EndCategoryRepository())
  {
    name_repository = rep.GetCategoryName(iterator_name);
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}

TEST(CategoryTest, TestDefaultWithRename)
{
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  FinanceRepository rep;
  rep.AddCategory();
  auto iterator_name = rep.FindCategory("Unspecified");
  if (iterator_name != rep.EndCategoryRepository())
  {
    name_repository = rep.GetCategoryName(iterator_name);
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
  rep.SetCategoryName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindCategory("UnspecifiedRename");
  if (iterator_name_rename != rep.EndCategoryRepository())
  {
    name_repository = rep.GetCategoryName(iterator_name_rename);
  }
  EXPECT_EQ(name_expected_rename, name_repository);
  EXPECT_TRUE(true);
}

TEST(CategoryTest, TestName)
{
  std::string name_expected = "Name1";
  std::string name_repository = "";
  FinanceRepository rep;
  rep.AddCategory({ "Name1" });
  auto iterator_name = rep.FindCategory("Name1");
  if (iterator_name != rep.EndCategoryRepository())
  {
    name_repository = rep.GetCategoryName(iterator_name);
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}

//  Currency

TEST(CurrencyTest, TestDefault)
{
  std::string name_expected = "Unspecified";
  std::string code_expected = "Unspecified";
  bool activity_expected = false;
  std::string name_repository = "";
  std::string code_repository = "";
  bool activity_repository = false;
  FinanceRepository rep;
  rep.AddCurrency();
  auto iterator_name = rep.FindCurrencyName("Unspecified");
  if (iterator_name != rep.EndCurrencyRepository())
  {
    name_repository = rep.GetCurrencyName(iterator_name);
  }
  auto iterator_code = rep.FindCurrencyCode("Unspecified");
  if (iterator_name != rep.EndCurrencyRepository())
  {
    name_repository = rep.GetCurrencyCode(iterator_name);
  }
  if (iterator_name != rep.EndCurrencyRepository())
  {
    activity_repository = rep.GetCurrencyActivity(iterator_name);
  }
  EXPECT_EQ(activity_expected, activity_repository);
  EXPECT_TRUE(true);
}

TEST(CurrencyTest, TestDefaultWithRename)
{
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string code_expected = "Unspecified";
  std::string code_expected_rename = "UnspecifiedRename";
  bool activity_expected = false;
  std::string name_repository = "";
  std::string code_repository = "";
  bool activity_repository = false;
  FinanceRepository rep;
  rep.AddCurrency();
  auto iterator_name = rep.FindCurrencyName("Unspecified");
  if (iterator_name != rep.EndCurrencyRepository())
  {
    name_repository = rep.GetCurrencyName(iterator_name);
  }
  auto iterator_code = rep.FindCurrencyCode("Unspecified");
  if (iterator_name != rep.EndCurrencyRepository())
  {
    name_repository = rep.GetCurrencyCode(iterator_name);
  }
  if (iterator_name != rep.EndCurrencyRepository())
  {
    activity_repository = rep.GetCurrencyActivity(iterator_name);
  }
  EXPECT_EQ(activity_expected, activity_repository);
  EXPECT_TRUE(true);
  rep.SetCurrencyName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindCurrencyName("UnspecifiedRename");
  if (iterator_name_rename != rep.EndCurrencyRepository())
  {
    name_repository = rep.GetCurrencyName(iterator_name_rename);
  }
  EXPECT_EQ(name_expected_rename, name_repository);
  EXPECT_TRUE(true);
  rep.SetCurrencyCode(iterator_code, "UnspecifiedRename");
  auto iterator_code_rename = rep.FindCurrencyName("UnspecifiedRename");
  if (iterator_code_rename != rep.EndCurrencyRepository())
  {
    code_repository = rep.GetCurrencyName(iterator_code_rename);
  }
  EXPECT_EQ(code_expected_rename, code_repository);
  EXPECT_TRUE(true);
}

TEST(CurrencyTest, TestName)
{
  std::string name_expected = "Name1";
  std::string name_repository = "";
  FinanceRepository rep;
  rep.AddCurrency({ "Name1" });
  auto iterator_name = rep.FindCurrencyName("Name1");
  if (iterator_name != rep.EndCurrencyRepository())
  {
    name_repository = rep.GetCurrencyName(iterator_name);
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}

//  Description

TEST(DescriptionTest, TestDefault)
{
  std::string name_expected = "Unspecified";
  std::string name_repository = "";
  FinanceRepository rep;
  rep.AddDescription();
  auto iterator_name = rep.FindDescription("Unspecified");
  if (iterator_name != rep.EndDescriptionRepository())
  {
    name_repository = rep.GetDescriptionName(iterator_name);
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}

TEST(DescriptionTest, TestDefaultWithRename)
{
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  FinanceRepository rep;
  rep.AddDescription();
  auto iterator_name = rep.FindDescription("Unspecified");
  if (iterator_name != rep.EndDescriptionRepository())
  {
    name_repository = rep.GetDescriptionName(iterator_name);
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
  rep.SetDescriptionName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindDescription("UnspecifiedRename");
  if (iterator_name_rename != rep.EndDescriptionRepository())
  {
    name_repository = rep.GetDescriptionName(iterator_name_rename);
  }
  EXPECT_EQ(name_expected_rename, name_repository);
  EXPECT_TRUE(true);
}

TEST(DescriptionTest, TestName)
{
  std::string name_expected = "Name1";
  std::string name_repository = "";
  FinanceRepository rep;
  rep.AddDescription({ "Name1" });
  auto iterator_name = rep.FindDescription("Name1");
  if (iterator_name != rep.EndDescriptionRepository())
  {
    name_repository = rep.GetDescriptionName(iterator_name);
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}

//  Payee

TEST(PayeeTest, TestDefault)
{
  std::string name_expected = "Unspecified";
  std::string name_repository = "";
  FinanceRepository rep;
  rep.AddPayee();
  auto iterator_name = rep.FindPayee("Unspecified");
  if (iterator_name != rep.EndPayeeRepository())
  {
    name_repository = rep.GetPayeeName(iterator_name);
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}

TEST(PayeeTest, TestDefaultWithRename)
{
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  FinanceRepository rep;
  rep.AddPayee();
  auto iterator_name = rep.FindPayee("Unspecified");
  if (iterator_name != rep.EndPayeeRepository())
  {
    name_repository = rep.GetPayeeName(iterator_name);
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
  rep.SetPayeeName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindPayee("UnspecifiedRename");
  if (iterator_name_rename != rep.EndPayeeRepository())
  {
    name_repository = rep.GetPayeeName(iterator_name_rename);
  }
  EXPECT_EQ(name_expected_rename, name_repository);
  EXPECT_TRUE(true);
}

TEST(PayeeTest, TestName)
{
  std::string name_expected = "Name1";
  std::string name_repository = "";
  FinanceRepository rep;
  rep.AddPayee({ "Name1" });
  auto iterator_name = rep.FindPayee("Name1");
  if (iterator_name != rep.EndPayeeRepository())
  {
    name_repository = rep.GetPayeeName(iterator_name);
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}

//  Comment

TEST(CommentTest, TestDefault)
{
  std::string name_expected = "Unspecified";
  std::string name_repository = "";
  FinanceRepository rep;
  rep.AddComment();
  auto iterator_name = rep.FindComment("Unspecified");
  if (iterator_name != rep.EndCommentRepository())
  {
    name_repository = rep.GetCommentName(iterator_name);
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}

TEST(CommentTest, TestDefaultWithRename)
{
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  FinanceRepository rep;
  rep.AddComment();
  auto iterator_name = rep.FindComment("Unspecified");
  if (iterator_name != rep.EndCommentRepository())
  {
    name_repository = rep.GetCommentName(iterator_name);
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
  rep.SetCommentName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindComment("UnspecifiedRename");
  if (iterator_name_rename != rep.EndCommentRepository())
  {
    name_repository = rep.GetCommentName(iterator_name_rename);
  }
  EXPECT_EQ(name_expected_rename, name_repository);
  EXPECT_TRUE(true);
}

TEST(CommentTest, TestName)
{
  std::string name_expected = "Name1";
  std::string name_repository = "";
  FinanceRepository rep;
  rep.AddComment({ "Name1" });
  auto iterator_name = rep.FindComment("Name1");
  if (iterator_name != rep.EndCommentRepository())
  {
    name_repository = rep.GetCommentName(iterator_name);
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}

//  Tag

TEST(TagTest, TestDefault)
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

TEST(TagTest, TestDefaultWithRename)
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
    name_repository = rep.GetTagName(iterator_name);
  }
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_TRUE(true);
}