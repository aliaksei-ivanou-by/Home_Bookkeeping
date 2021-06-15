#include "pch.h"

extern FinanceRepository repository;

TEST(PayeeTest, TestDefault)
{
  //  Arrange
  std::string expected_name = "Unspecified";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddPayee();
  bool repository_is_in_table;
  int repository_payee_id;
  Payee repository_payee;
  int repository_payee_counter;
  std::tie(repository_is_in_table, repository_payee_id, repository_payee, repository_payee_counter) = repository.FindPayee("Unspecified");

  //  Assert
  EXPECT_EQ(repository_is_in_table, true);
  EXPECT_EQ(expected_name, repository_payee.GetName());
}

TEST(PayeeTest, TestDefaultWithRename)
{
  //  Arrange
  std::string expected_name = "Payee";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddPayee();
  bool repository_is_in_table;
  int repository_payee_id;
  Payee repository_payee;
  int repository_payee_counter;
  std::tie(repository_is_in_table, repository_payee_id, repository_payee, repository_payee_counter) = repository.FindPayee("Unspecified");
  repository.SetPayeeName("Unspecified", "Payee");
  std::tie(repository_is_in_table, repository_payee_id, repository_payee, repository_payee_counter) = repository.FindPayee("Payee");

  //  Assert
  EXPECT_EQ(repository_is_in_table, true);
  EXPECT_EQ(expected_name, repository_payee.GetName());
}

TEST(PayeeTest, TestWithRename)
{
  //  Arrange
  std::string expected_name = "Payee";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddPayee(Payee("Unspecified_payee"));
  bool repository_is_in_table;
  int repository_payee_id;
  Payee repository_payee;
  int repository_payee_counter;
  std::tie(repository_is_in_table, repository_payee_id, repository_payee, repository_payee_counter) = repository.FindPayee("Unspecified_payee");
  repository.SetPayeeName("Unspecified_payee", "Payee");
  std::tie(repository_is_in_table, repository_payee_id, repository_payee, repository_payee_counter) = repository.FindPayee("Payee");

  //  Assert
  EXPECT_EQ(repository_is_in_table, true);
  EXPECT_EQ(expected_name, repository_payee.GetName());
}