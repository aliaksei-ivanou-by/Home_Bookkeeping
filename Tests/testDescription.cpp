#include "pch.h"

extern FinanceRepository repository;

TEST(DescriptionTest, TestDefault)
{
  //  Arrange
  std::string expected_name = Description().GetName();

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddDescription();
  bool repository_model_is_in_table;
  int repository_model_id;
  Description repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindDescription(expected_name);

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
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindDescription(Description().GetName());
  if (repository_model_is_in_table)
  {
    repository.SetDescriptionName(Description().GetName(), expected_name);
    std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindDescription(expected_name);
  }

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
  const std::string model_name = "Description_Old";
  repository.AddDescription(Description(model_name));
  bool repository_model_is_in_table;
  int repository_model_id;
  Description repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindDescription(model_name);
  if (repository_model_is_in_table)
  {
    repository.SetDescriptionName(model_name, expected_name);
    std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindDescription(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
}

TEST(DescriptionTest, TestAddDescriptionAndRemove)
{
  //  Arrange
  std::string expected_name = "Description";

  //Act
  repository.ClearTablesInDatabase();
  repository.AddDescription(expected_name);
  bool repository_model_is_in_table;
  bool repository_model_not_is_in_table;
  int repository_model_id;
  Description repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindDescription(expected_name);
  if (repository_model_is_in_table)
  {
    repository.RemoveDescription(expected_name);
    std::tie(repository_model_not_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindDescription(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(repository_model_not_is_in_table, false);
}