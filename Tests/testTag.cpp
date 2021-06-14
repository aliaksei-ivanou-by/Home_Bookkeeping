#include "pch.h"

extern FinanceRepository repository;

TEST(TagTest, TestDefault)
{
  //  Arrange
  std::string expected_name = "Unspecified";
  double expected_amount = 0.0;

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddTag();
  bool repository_is_in_table;
  int repository_tag_id;
  Tag repository_tag;
  int repository_tag_counter;
  std::tie(repository_is_in_table, repository_tag_id, repository_tag, repository_tag_counter) = repository.FindTag("Unspecified");

  //  Assert
  EXPECT_EQ(repository_is_in_table, true);
  EXPECT_EQ(expected_name, repository_tag.GetName());
}

TEST(AccountTest, TestDefaultWithRename)
{
  //  Arrange
  std::string expected_name = "Tag";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddTag();
  bool repository_is_in_table;
  int repository_tag_id;
  Tag repository_tag;
  int repository_tag_counter;
  std::tie(repository_is_in_table, repository_tag_id, repository_tag, repository_tag_counter) = repository.FindTag("Unspecified");
  repository.SetTagName("Unspecified", "Tag");
  std::tie(repository_is_in_table, repository_tag_id, repository_tag, repository_tag_counter) = repository.FindTag("Tag");

  //  Assert
  EXPECT_EQ(repository_is_in_table, true);
  EXPECT_EQ(expected_name, repository_tag.GetName());
}

TEST(AccountTest, TestWithRename)
{
  //  Arrange
  std::string expected_name = "Tag";

  //  Act
  repository.ClearTablesInDatabase();
  repository.AddTag(Tag("Unspecified_tag"));
  bool repository_is_in_table;
  int repository_tag_id;
  Tag repository_tag;
  int repository_tag_counter;
  std::tie(repository_is_in_table, repository_tag_id, repository_tag, repository_tag_counter) = repository.FindTag("Unspecified_tag");
  repository.SetTagName("Unspecified_tag", "Tag");
  std::tie(repository_is_in_table, repository_tag_id, repository_tag, repository_tag_counter) = repository.FindTag("Tag");

  //  Assert
  EXPECT_EQ(repository_is_in_table, true);
  EXPECT_EQ(expected_name, repository_tag.GetName());
}