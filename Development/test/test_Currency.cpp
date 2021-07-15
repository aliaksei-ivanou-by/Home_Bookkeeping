#include <gtest/gtest.h>

#include "include/2_BusinessLogic/FinanceRepository.h"

extern FinanceRepository repository;

TEST(CurrencyTest, TestAddCurrencyAndRemove)
{
  //  Arrange
  std::string expected_name = "Currency";

  //Act
  repository.ClearTablesInDatabase();
  repository.AddCurrency(expected_name);
  bool repository_model_is_in_table = false;
  bool repository_model_not_is_in_table = true;
  std::tie(repository_model_is_in_table, std::ignore, std::ignore) = repository.FindCurrency(expected_name);
  if (repository_model_is_in_table)
  {
    repository.RemoveCurrency(expected_name);
    std::tie(repository_model_not_is_in_table, std::ignore, std::ignore) = repository.FindCurrency(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_not_is_in_table, false);
}