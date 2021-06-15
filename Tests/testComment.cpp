#include "pch.h"

extern FinanceRepository repository;

TEST(CommentTest, TestDefault)
{
  //  Arrange
  std::string expected_name = "Unspecified";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddComment();
  bool repository_is_in_table;
  int repository_comment_id;
  Comment repository_comment;
  int repository_comment_counter;
  std::tie(repository_is_in_table, repository_comment_id, repository_comment, repository_comment_counter) = repository.FindComment("Unspecified");

  //  Assert
  EXPECT_EQ(repository_is_in_table, true);
  EXPECT_EQ(expected_name, repository_comment.GetName());
}

TEST(CommentTest, TestDefaultWithRename)
{
  //  Arrange
  std::string expected_name = "Comment";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddComment();
  bool repository_is_in_table;
  int repository_comment_id;
  Comment repository_comment;
  int repository_comment_counter;
  std::tie(repository_is_in_table, repository_comment_id, repository_comment, repository_comment_counter) = repository.FindComment("Unspecified");
  repository.SetCommentName("Unspecified", "Comment");
  std::tie(repository_is_in_table, repository_comment_id, repository_comment, repository_comment_counter) = repository.FindComment("Comment");

  //  Assert
  EXPECT_EQ(repository_is_in_table, true);
  EXPECT_EQ(expected_name, repository_comment.GetName());
}

TEST(CommentTest, TestWithRename)
{
  //  Arrange
  std::string expected_name = "Comment";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddComment(Comment("Unspecified_comment"));
  bool repository_is_in_table;
  int repository_comment_id;
  Comment repository_comment;
  int repository_comment_counter;
  std::tie(repository_is_in_table, repository_comment_id, repository_comment, repository_comment_counter) = repository.FindComment("Unspecified_comment");
  repository.SetCommentName("Unspecified_comment", "Comment");
  std::tie(repository_is_in_table, repository_comment_id, repository_comment, repository_comment_counter) = repository.FindComment("Comment");

  //  Assert
  EXPECT_EQ(repository_is_in_table, true);
  EXPECT_EQ(expected_name, repository_comment.GetName());
}