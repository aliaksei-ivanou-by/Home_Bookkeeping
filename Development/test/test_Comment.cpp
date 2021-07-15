#include <gtest/gtest.h>

#include "include/2_BusinessLogic/FinanceRepository.h"

extern FinanceRepository repository;

TEST(CommentTest, TestDefault)
{
  //  Arrange
  std::string expected_name = Comment().GetName();

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddComment();
  bool repository_model_is_in_table;
  std::tie(repository_model_is_in_table, std::ignore, std::ignore, std::ignore) = repository.FindComment(expected_name);

  //  Assert
  EXPECT_EQ(repository_model_is_in_table, true);
}

TEST(CommentTest, TestDefaultWithRename)
{
  //  Arrange
  std::string expected_name = "Comment";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddComment();
  bool repository_model_is_in_table_old = false;
  bool repository_model_is_in_table_new = false;
  std::tie(repository_model_is_in_table_old, std::ignore, std::ignore, std::ignore) = repository.FindComment(Comment().GetName());
  if (repository_model_is_in_table_old)
  {
    repository.SetCommentName(Comment().GetName(), expected_name);
    std::tie(repository_model_is_in_table_new, std::ignore, std::ignore, std::ignore) = repository.FindComment(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table_new, true);
}

TEST(CommentTest, TestWithRename)
{
  //  Arrange
  std::string expected_name = "Comment";

  //  Act
  repository.ClearTablesInDatabase();
  const std::string model_name = "Comment_Old";
  repository.AddComment(Comment(model_name));
  bool repository_model_is_in_table_old = false;
  bool repository_model_is_in_table_new = false;
  std::tie(repository_model_is_in_table_old, std::ignore, std::ignore, std::ignore) = repository.FindComment(model_name);
  if (repository_model_is_in_table_old)
  {
    repository.SetCommentName(model_name, expected_name);
    std::tie(repository_model_is_in_table_new, std::ignore, std::ignore, std::ignore) = repository.FindComment(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_is_in_table_new, true);
}

TEST(CommentTest, TestAddCommentAndRemove)
{
  //  Arrange
  std::string expected_name = "Comment";

  //Act
  repository.ClearTablesInDatabase();
  repository.AddComment(expected_name);
  bool repository_model_is_in_table = false;
  bool repository_model_not_is_in_table = true;
  std::tie(repository_model_is_in_table, std::ignore, std::ignore, std::ignore) = repository.FindComment(expected_name);
  if (repository_model_is_in_table)
  {
    repository.RemoveComment(expected_name);
    std::tie(repository_model_not_is_in_table, std::ignore, std::ignore, std::ignore) = repository.FindComment(expected_name);
  }

  //  Assert
  EXPECT_EQ(repository_model_not_is_in_table, false);
}