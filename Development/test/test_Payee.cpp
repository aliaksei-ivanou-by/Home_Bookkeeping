#include <gtest/gtest.h>

#include "include/2_BusinessLogic/FinanceRepository.h"

extern FinanceRepository repository;

TEST(PayeeTest, TestDefault)
{
  //  Arrange
  std::string expected_name = Payee().GetName();

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddPayee();
  bool repository_model_is_in_table;
  std::tie(repository_model_is_in_table, std::ignore, std::ignore, std::ignore) = repository.FindPayee(expected_name);

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
}

TEST(PayeeTest, TestDefaultWithRename)
{
  //  Arrange
  std::string expected_name = "Payee";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddPayee();
  bool repository_model_is_in_table_old = false;
  bool repository_model_is_in_table_new = false;
  std::tie(repository_model_is_in_table_old, std::ignore, std::ignore, std::ignore) = repository.FindPayee(Payee().GetName());
  if (repository_model_is_in_table_old)
  {
    repository.SetPayeeName(Payee().GetName(), expected_name);
    std::tie(repository_model_is_in_table_new, std::ignore, std::ignore, std::ignore) = repository.FindPayee(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table_new, true);
}

TEST(PayeeTest, TestWithRename)
{
  //  Arrange
  std::string expected_name = "Payee";

  //  Act
  repository.ClearTablesInDatabase();
  const std::string model_name = "Payee_Old";
  repository.AddPayee(Payee(model_name));
  bool repository_model_is_in_table_old = false;
  bool repository_model_is_in_table_new = false;
  std::tie(repository_model_is_in_table_old, std::ignore, std::ignore, std::ignore) = repository.FindPayee(model_name);
  if (repository_model_is_in_table_old)
  {
    repository.SetPayeeName(model_name, expected_name);
    std::tie(repository_model_is_in_table_new, std::ignore, std::ignore, std::ignore) = repository.FindPayee(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table_new, true);
}

TEST(PayeeTest, TestAddPayeeAndRemove)
{
  //  Arrange
  std::string expected_name = "Payee";

  //Act
  repository.ClearTablesInDatabase();
  repository.AddPayee(expected_name);
  bool repository_model_is_in_table = false;
  bool repository_model_not_is_in_table = true;
  std::tie(repository_model_is_in_table, std::ignore, std::ignore, std::ignore) = repository.FindPayee(expected_name);
  if (repository_model_is_in_table)
  {
    repository.RemovePayee(expected_name);
    std::tie(repository_model_not_is_in_table, std::ignore, std::ignore, std::ignore) = repository.FindPayee(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_not_is_in_table, false);
}