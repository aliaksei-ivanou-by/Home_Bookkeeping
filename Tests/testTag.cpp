#include "pch.h"

extern FinanceRepository repository;

TEST(TagTest, TestDefault)
{
  //  Arrange
  std::string expected_name = Tag().GetName();

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddTag();
  bool repository_model_is_in_table;
  int repository_model_id;
  Tag repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindTag(expected_name);

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
}

TEST(TagTest, TestDefaultWithRename)
{
  //  Arrange
  std::string expected_name = "Tag";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddTag();
  bool repository_model_is_in_table;
  int repository_model_id;
  Tag repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindTag(Tag().GetName());
  if (repository_model_is_in_table)
  {
    repository.SetTagName(Tag().GetName(), expected_name);
    std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindTag(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
}

TEST(TagTest, TestWithRename)
{
  //  Arrange
  std::string expected_name = "Tag";

  //  Act
  repository.ClearTablesInDatabase();
  const std::string model_name = "Tag_Old";
  repository.AddTag(Tag(model_name));
  bool repository_model_is_in_table;
  int repository_model_id;
  Tag repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindTag(model_name);
  if (repository_model_is_in_table)
  {
    repository.SetTagName(model_name, expected_name);
    std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindTag(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
}

TEST(TagTest, TestAddTagAndRemove)
{
  //  Arrange
  std::string expected_name = "Tag";

  //Act
  repository.ClearTablesInDatabase();
  repository.AddTag(expected_name);
  bool repository_model_is_in_table;
  bool repository_model_not_is_in_table;
  int repository_model_id;
  Tag repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindTag(expected_name);
  if (repository_model_is_in_table)
  {
    repository.RemoveTag(expected_name);
    std::tie(repository_model_not_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindTag(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(repository_model_not_is_in_table, false);
}