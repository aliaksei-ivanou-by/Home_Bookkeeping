﻿#include "pch.h"

TEST(AccountTest, TestDefault)
{
  //  Arrange
  std::string expected_name = "Unspecified";
  double expected_amount = 0.0;

  //  Act
  FinanceRepository repository;
  //repository.ClearTablesInDatabase();
  //repository.AddAccount();
  //bool repository_is_in_table;
 // int repository_account_id;
 // Account repository_account;
 // std::tie(repository_is_in_table, repository_account_id, repository_account) = repository.FindAccount("Unspecified");

  //  Assert
  //EXPECT_EQ(repository_is_in_table, true);
  //EXPECT_EQ(expected_name, repository_account.GetName());
  //EXPECT_EQ(expected_amount, repository_account.GetAmount().getAsDouble());
}

TEST(AccountTest, TestDefaultWithRenameAndReamount)
{
  //  Arrange
  std::string expected_name = "Account";
  double expected_amount = 20.0;

  //  Act
  FinanceRepository repository;
  repository.ClearTablesInDatabase();
  repository.AddAccount();
  bool repository_is_in_table;
  int repository_account_id;
  Account repository_account;
  std::tie(repository_is_in_table, repository_account_id, repository_account) = repository.FindAccount("Unspecified");
  repository.SetAccountName("Unspecified", "Account");
  repository.SetAccountAmount("Account", 20.0);
  std::tie(repository_is_in_table, repository_account_id, repository_account) = repository.FindAccount("Account");

  //  Assert
  EXPECT_EQ(repository_is_in_table, true);
  EXPECT_EQ(expected_name, repository_account.GetName());
  EXPECT_EQ(expected_amount, repository_account.GetAmount().getAsDouble());
}

TEST(AccountTest, TestNameAndAmount)
{
  //  Arrange
  std::string expected_name = "Account";
  double expected_amount = 15.0;

  //  Act
  FinanceRepository repository;
  repository.ClearTablesInDatabase();
  repository.AddAccount(Account("Account", 15.0));
  bool repository_is_in_table;
  int repository_account_id;
  Account repository_account;
  std::tie(repository_is_in_table, repository_account_id, repository_account) = repository.FindAccount("Unspecified");

  //  Assert
  EXPECT_EQ(repository_is_in_table, true);
  EXPECT_EQ(expected_name, repository_account.GetName());
  EXPECT_EQ(expected_amount, repository_account.GetAmount().getAsDouble());
}