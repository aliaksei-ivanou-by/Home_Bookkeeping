#include <gtest/gtest.h>

#include "include/2_BusinessLogic/FinanceRepository.h"

extern FinanceRepository repository;

TEST(DescriptionTest, TestDefault)
{
  //  Arrange
  std::string expected_name = Description().GetName();

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddDescription();
  bool repository_model_is_in_table = false;
  std::tie(repository_model_is_in_table, std::ignore, std::ignore, std::ignore) = repository.FindDescription(expected_name);

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
}

TEST(DescriptionTest, TestDefaultWithRename)
{
  //  Arrange
  std::string expected_name = "Description";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddDescription();
  bool repository_model_is_in_table_old = false;
  bool repository_model_is_in_table_new = false;
  std::tie(repository_model_is_in_table_old, std::ignore, std::ignore, std::ignore) = repository.FindDescription(Description().GetName());
  if (repository_model_is_in_table_old)
  {
    repository.SetDescriptionName(Description().GetName(), expected_name);
    std::tie(repository_model_is_in_table_new, std::ignore, std::ignore, std::ignore) = repository.FindDescription(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table_new, true);
}

TEST(DescriptionTest, TestWithRename)
{
  //  Arrange
  std::string expected_name = "Description";

  //  Act
  repository.ClearTablesInDatabase();
  const std::string model_name = "Description_Old";
  repository.AddDescription(Description(model_name));
  bool repository_model_is_in_table_old = false;
  bool repository_model_is_in_table_new = false;
  std::tie(repository_model_is_in_table_old, std::ignore, std::ignore, std::ignore) = repository.FindDescription(model_name);
  if (repository_model_is_in_table_old)
  {
    repository.SetDescriptionName(model_name, expected_name);
    std::tie(repository_model_is_in_table_new, std::ignore, std::ignore, std::ignore) = repository.FindDescription(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table_new, true);
}

TEST(DescriptionTest, TestAddDescriptionAndRemove)
{
  //  Arrange
  std::string expected_name = "Description";

  //Act
  repository.ClearTablesInDatabase();
  repository.AddDescription(expected_name);
  bool repository_model_is_in_table = false;
  bool repository_model_not_is_in_table = true;
  std::tie(repository_model_is_in_table, std::ignore, std::ignore, std::ignore) = repository.FindDescription(expected_name);
  if (repository_model_is_in_table)
  {
    repository.RemoveDescription(expected_name);
    std::tie(repository_model_not_is_in_table, std::ignore, std::ignore, std::ignore) = repository.FindDescription(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_not_is_in_table, false);
}