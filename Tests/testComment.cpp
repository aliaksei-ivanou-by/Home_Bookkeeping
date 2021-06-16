#include "pch.h"

extern FinanceRepository repository;

TEST(CommentTest, TestDefault)
{
  //  Arrange
  std::string expected_name = Comment().GetName();

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddComment();
  bool repository_model_is_in_table;
  int repository_model_id;
  Comment repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindComment(expected_name);

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
}

TEST(CommentTest, TestDefaultWithRename)
{
  //  Arrange
  std::string expected_name = "Comment";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddComment();
  bool repository_model_is_in_table;
  int repository_model_id;
  Comment repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindComment(Comment().GetName());
  if (repository_model_is_in_table)
  {
    repository.SetCommentName(Comment().GetName(), expected_name);
    std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindComment(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
}

TEST(CommentTest, TestWithRename)
{
  //  Arrange
  std::string expected_name = "Comment";

  //  Act
  repository.ClearTablesInDatabase();
  const std::string model_name = "Comment_Old";
  repository.AddComment(Comment(model_name));
  bool repository_model_is_in_table;
  int repository_model_id;
  Comment repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindComment(model_name);
  if (repository_model_is_in_table)
  {
    repository.SetCommentName(model_name, expected_name);
    std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindComment(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(expected_name, repository_model.GetName());
}

TEST(CommentTest, TestAddCommentAndRemove)
{
  //  Arrange
  std::string expected_name = "Comment";

  //Act
  repository.ClearTablesInDatabase();
  repository.AddComment(expected_name);
  bool repository_model_is_in_table;
  bool repository_model_not_is_in_table;
  int repository_model_id;
  Comment repository_model;
  int repository_model_counter;
  std::tie(repository_model_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindComment(expected_name);
  if (repository_model_is_in_table)
  {
    repository.RemoveComment(expected_name);
    std::tie(repository_model_not_is_in_table, repository_model_id, repository_model, repository_model_counter) = repository.FindComment(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
  EXPECT_EQ(repository_model_not_is_in_table, false);
}