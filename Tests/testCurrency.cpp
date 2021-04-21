#include "pch.h"

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
  EXPECT_EQ(code_expected, code_repository);
  EXPECT_EQ(activity_expected, activity_repository);
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
  std::string name_repository_rename = "";
  std::string code_repository_rename = "";
  bool activity_repository_rename = false;

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
  rep.SetCurrencyName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindCurrencyName("UnspecifiedRename");
  if (iterator_name_rename != rep.EndCurrencyRepository())
  {
    name_repository_rename = rep.GetCurrencyName(iterator_name_rename);
  }
  rep.SetCurrencyCode(iterator_code, "UnspecifiedRename");
  auto iterator_code_rename = rep.FindCurrencyName("UnspecifiedRename");
  if (iterator_code_rename != rep.EndCurrencyRepository())
  {
    code_repository_rename = rep.GetCurrencyName(iterator_code_rename);
  }
  if (iterator_name_rename != rep.EndCurrencyRepository())
  {
    activity_repository_rename = rep.GetCurrencyActivity(iterator_name_rename);
  }

  //  Assert
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_EQ(code_expected, code_repository);
  EXPECT_EQ(activity_expected, activity_repository);
  EXPECT_EQ(name_expected_rename, name_repository_rename);
  EXPECT_EQ(code_expected_rename, code_repository_rename);
  EXPECT_EQ(activity_expected, activity_repository_rename);
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
}
