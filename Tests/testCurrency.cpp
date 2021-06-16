#include "pch.h"

extern FinanceRepository repository;

TEST(CurrencyTest, TestAddCurrencyAndRemove)
{
  //  Arrange
  std::string expected_name = "Currency";

  //Act
  repository.ClearTablesInDatabase();
  repository.AddCurrency(expected_name);
  bool repository_model_is_in_table;
  bool repository_model_not_is_in_table;
  int repository_model_id;
  Currency repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model) = repository.FindCurrency(expected_name);
  if (repository_model_is_in_table)
  {
    repository.RemoveCurrency(expected_name);
    std::tie(repository_model_not_is_in_table, repository_model_id, repository_model) = repository.FindCurrency(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(repository_model_not_is_in_table, false);
}