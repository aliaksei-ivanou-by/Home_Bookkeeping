#include <gtest/gtest.h>

#include "include/2_BusinessLogic/FinanceRepository.h"

FinanceRepository repository;

TEST(TagTest, TestDefault)
{
  //  Arrange
  std::string expected_name = Tag().GetName();

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddTag();
  bool repository_model_is_in_table = false;
  std::tie(repository_model_is_in_table, std::ignore, std::ignore, std::ignore) = repository.FindTag(expected_name);

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
}

TEST(TagTest, TestDefaultWithRename)
{
  //  Arrange
  std::string expected_name = "Tag";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddTag();
  bool repository_model_is_in_table_old = false;
  bool repository_model_is_in_table_new = false;
  std::tie(repository_model_is_in_table_old, std::ignore, std::ignore, std::ignore) = repository.FindTag(Tag().GetName());
  if (repository_model_is_in_table_old)
  {
    repository.SetTagName(Tag().GetName(), expected_name);
    std::tie(repository_model_is_in_table_new, std::ignore, std::ignore, std::ignore) = repository.FindTag(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table_new, true);
}

TEST(TagTest, TestWithRename)
{
  //  Arrange
  std::string expected_name = "Tag";

  //  Act
  repository.ClearTablesInDatabase();
  const std::string model_name = "Tag_Old";
  repository.AddTag(Tag(model_name));
  bool repository_model_is_in_table_old = false;
  bool repository_model_is_in_table_new = false;
  std::tie(repository_model_is_in_table_old, std::ignore, std::ignore, std::ignore) = repository.FindTag(model_name);
  if (repository_model_is_in_table_old)
  {
    repository.SetTagName(model_name, expected_name);
    std::tie(repository_model_is_in_table_new, std::ignore, std::ignore, std::ignore) = repository.FindTag(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table_new, true);
}

TEST(TagTest, TestAddTagAndRemove)
{
  //  Arrange
  std::string expected_name = "Tag";

  //Act
  repository.ClearTablesInDatabase();
  repository.AddTag(expected_name);
  bool repository_model_is_in_table = false;
  bool repository_model_not_is_in_table = true;
  std::tie(repository_model_is_in_table, std::ignore, std::ignore, std::ignore) = repository.FindTag(expected_name);
  if (repository_model_is_in_table)
  {
    repository.RemoveTag(expected_name);
    std::tie(repository_model_not_is_in_table, std::ignore, std::ignore, std::ignore) = repository.FindTag(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_not_is_in_table, false);
}