#include <gtest/gtest.h>

#include "include/2_BusinessLogic/FinanceRepository.h"

extern FinanceRepository repository;

TEST(AccountTest, TestDefault)
{
  //  Arrange
  std::string expected_name = Account().GetName();

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddAccount();
  bool repository_model_is_in_table = false;
  std::tie(repository_model_is_in_table, std::ignore, std::ignore) = repository.FindAccount(expected_name);

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
}

TEST(AccountTest, TestDefaultWithRename)
{
  //  Arrange
  std::string expected_name = "Account";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddAccount();
  bool repository_model_is_in_table_old = false;
  bool repository_model_is_in_table_new = false;
  std::tie(repository_model_is_in_table_old, std::ignore, std::ignore) = repository.FindAccount(Account().GetName());
  if (repository_model_is_in_table_old)
  {
    repository.SetAccountName(Account().GetName(), expected_name);
    std::tie(repository_model_is_in_table_new, std::ignore, std::ignore) = repository.FindAccount(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table_new, true);
}

TEST(AccountTest, TestWithRename)
{
  //  Arrange
  std::string expected_name = "Account";

  //  Act
  repository.ClearTablesInDatabase();
  const std::string model_name = "Account_Old";
  repository.AddAccount(Account(model_name));
  bool repository_model_is_in_table_old = false;
  bool repository_model_is_in_table_new = false;
  std::tie(repository_model_is_in_table_old, std::ignore, std::ignore) = repository.FindAccount(model_name);
  if (repository_model_is_in_table_old)
  {
    repository.SetAccountName(model_name, expected_name);
    std::tie(repository_model_is_in_table_new, std::ignore, std::ignore) = repository.FindAccount(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table_new, true);
}

TEST(AccountTest, TestAddAccountAndRemove)
{
  //  Arrange
  std::string expected_name = "Account";

  //Act
  repository.ClearTablesInDatabase();
  repository.AddAccount(expected_name);
  bool repository_model_is_in_table = false;
  bool repository_model_not_is_in_table = true;
  std::tie(repository_model_is_in_table, std::ignore, std::ignore) = repository.FindAccount(expected_name);
  if (repository_model_is_in_table)
  {
    repository.RemoveAccount(expected_name);
    std::tie(repository_model_not_is_in_table, std::ignore, std::ignore) = repository.FindAccount(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_not_is_in_table, false);
}