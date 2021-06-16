#include "pch.h"

extern FinanceRepository repository;

TEST(AccountTest, TestDefault)
{
  //  Arrange
  std::string expected_name = Account().GetName();
  double expected_amount = 0.0;

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddAccount();
  bool repository_model_is_in_table;
  int repository_model_id;
  Account repository_model;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model) = repository.FindAccount(expected_name);

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
  EXPECT_EQ(expected_amount, repository_model.GetAmount().getAsDouble());
}

TEST(AccountTest, TestDefaultWithRenameAndReamount)
{
  //  Arrange
  std::string expected_name = "Account";
  double expected_amount = 20.0;

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddAccount();
  bool repository_model_is_in_table;
  int repository_model_id;
  Account repository_model;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model) = repository.FindAccount(Account().GetName());
  if (repository_model_is_in_table)
  {
    repository.SetAccountName(Account().GetName(), expected_name);
    repository.SetAccountAmount(expected_name, expected_amount);
    std::tie(repository_model_is_in_table, repository_model_id, repository_model) = repository.FindAccount(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
  EXPECT_EQ(expected_amount, repository_model.GetAmount().getAsDouble());
}

TEST(AccountTest, TestWithRenameAndReamount)
{
  //  Arrange
  std::string expected_name = "Account";
  double expected_amount = 15.0;

  //  Act
  repository.ClearTablesInDatabase();
  const std::string model_name = "Account_Old";
  repository.AddAccount(Account(model_name, 10.0));
  bool repository_model_is_in_table;
  int repository_model_id;
  Account repository_model;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model) = repository.FindAccount(model_name);
  if (repository_model_is_in_table)
  {
    repository.SetAccountName(model_name, expected_name);
    repository.SetAccountAmount(expected_name, expected_amount);
    std::tie(repository_model_is_in_table, repository_model_id, repository_model) = repository.FindAccount(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
  EXPECT_EQ(expected_amount, repository_model.GetAmount().getAsDouble());
}

TEST(AccountTest, TestWithRenameAndReamountAndRecurrency)
{
  //  Arrange
  std::string expected_name = "Account";
  double expected_amount = 15.0;
  Currency expected_currency("BYN");

  //  Act
  repository.ClearTablesInDatabase();
  const std::string model_name = "Account_Old";
  repository.AddAccount(Account(model_name, 10.0));
  bool repository_is_in_table;
  int repository_model_id;
  Account repository_model;
  std::tie(repository_is_in_table, repository_model_id, repository_model) = repository.FindAccount(model_name);
  if (repository_is_in_table)
  {
    repository.SetAccountName(model_name, expected_name);
    repository.SetAccountAmount(expected_name, expected_amount);
    repository.SetAccountCurrency(expected_name, std::move(expected_currency));
    std::tie(repository_is_in_table, repository_model_id, repository_model) = repository.FindAccount(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
  EXPECT_EQ(expected_amount, repository_model.GetAmount().getAsDouble());
  EXPECT_EQ(expected_currency, repository_model.GetCurrency());
}