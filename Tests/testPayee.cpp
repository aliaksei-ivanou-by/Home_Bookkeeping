#include "pch.h"

extern FinanceRepository repository;

TEST(PayeeTest, TestDefault)
{
  //  Arrange
  std::string expected_name = Payee().GetName();

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddPayee();
  bool repository_model_is_in_table;
  int repository_model_id;
  Payee repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindPayee(expected_name);

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
}

TEST(PayeeTest, TestDefaultWithRename)
{
  //  Arrange
  std::string expected_name = "Payee";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddPayee();
  bool repository_model_is_in_table;
  int repository_model_id;
  Payee repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindPayee(Payee().GetName());
  if (repository_model_is_in_table)
  {
    repository.SetPayeeName(Payee().GetName(), expected_name);
    std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindPayee(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
}

TEST(PayeeTest, TestWithRename)
{
  //  Arrange
  std::string expected_name = "Payee";

  //  Act
  repository.ClearTablesInDatabase();
  const std::string model_name = "Payee_Old";
  repository.AddPayee(Payee(model_name));
  bool repository_model_is_in_table;
  int repository_model_id;
  Payee repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindPayee(model_name);
  if (repository_model_is_in_table)
  {
    repository.SetPayeeName(model_name, expected_name);
    std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindPayee(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
}

TEST(PayeeTest, TestAddPayeeAndRemove)
{
  //  Arrange
  std::string expected_name = "Payee";

  //Act
  repository.ClearTablesInDatabase();
  repository.AddPayee(expected_name);
  bool repository_model_is_in_table;
  bool repository_model_not_is_in_table;
  int repository_model_id;
  Payee repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindPayee(expected_name);
  if (repository_model_is_in_table)
  {
    repository.RemovePayee(expected_name);
    std::tie(repository_model_not_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindPayee(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(repository_model_not_is_in_table, false);
}