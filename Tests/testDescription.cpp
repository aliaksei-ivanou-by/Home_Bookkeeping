#include "pch.h"

extern FinanceRepository repository;

TEST(DescriptionTest, TestDefault)
{
  //  Arrange
  std::string expected_name = "Unspecified";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddDescription();
  bool repository_model_is_in_table;
  int repository_model_id;
  Description repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindDescription("Unspecified");

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
}

TEST(DescriptionTest, TestDefaultWithRename)
{
  //  Arrange
  std::string expected_name = "Description";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddDescription();
  bool repository_model_is_in_table;
  int repository_model_id;
  Description repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindDescription("Unspecified");
  repository.SetDescriptionName("Unspecified", "Description");
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindDescription("Description");

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
}

TEST(DescriptionTest, TestWithRename)
{
  //  Arrange
  std::string expected_name = "Description";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddDescription(Description("Unspecified_description"));
  bool repository_model_is_in_table;
  int repository_model_id;
  Description repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindDescription("Unspecified_description");
  repository.SetDescriptionName("Unspecified_description", "Description");
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindDescription("Description");

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
}