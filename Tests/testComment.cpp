#include "pch.h"

TEST(CommentTest, TestDefault)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_repository = "";

  //  Act
  FinanceRepository rep;
  rep.AddComment();
  auto iterator_name = rep.FindComment("Unspecified");
  if (iterator_name != rep.EndCommentRepository())
  {
    name_repository = rep.GetCommentName(iterator_name);
  }

  //  Assert
  EXPECT_EQ(name_expected, name_repository);
}

TEST(CommentTest, TestDefaultWithRename)
{
  //  Arrange
  std::string name_expected = "Unspecified";
  std::string name_expected_rename = "UnspecifiedRename";
  std::string name_repository = "";
  std::string name_repository_rename = "";

  //  Act
  FinanceRepository rep;
  rep.AddComment();
  auto iterator_name = rep.FindComment("Unspecified");
  if (iterator_name != rep.EndCommentRepository())
  {
    name_repository = rep.GetCommentName(iterator_name);
  }
  rep.SetCommentName(iterator_name, "UnspecifiedRename");
  auto iterator_name_rename = rep.FindComment("UnspecifiedRename");
  if (iterator_name_rename != rep.EndCommentRepository())
  {
    name_repository_rename = rep.GetCommentName(iterator_name_rename);
  }

  //  Assert
  EXPECT_EQ(name_expected, name_repository);
  EXPECT_EQ(name_expected_rename, name_repository_rename);
}

TEST(CommentTest, TestName)
{
  //  Arrange
  std::string name_expected = "Name1";
  std::string name_repository = "";

  //  Act
  FinanceRepository rep;
  rep.AddComment({ "Name1" });
  auto iterator_name = rep.FindComment("Name1");
  if (iterator_name != rep.EndCommentRepository())
  {
    name_repository = rep.GetCommentName(iterator_name);
  }

  //  Assert
  EXPECT_EQ(name_expected, name_repository);
}
