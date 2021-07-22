#ifndef HOMEBOOKKEEPING_1DATAACCESS_COMMENTDATABASE_H_
#define HOMEBOOKKEEPING_1DATAACCESS_COMMENTDATABASE_H_

#include "include/1_DataAccess/DatabaseManager.h"
#include "include/1_DataAccess/CommentRepository.h"

class CommentDatabase
{
public:
  CommentDatabase() = delete;
  CommentDatabase(DatabaseManager* database_manager);
  void CreateTableCommentsInDatabase();
  void ClearTableCommentsInDatabase();
  void InsertCommentToTableCommentsInDatabase(Comment&& comment);
  void InsertCommentsToTableCommentsInDatabase(CommentRepository&& repository);
  std::tuple<bool, int, Comment, int> FindCommentInTableCommentsInDatabase(const std::string& model_name);
  void SetCommentName(const std::string& model_name, const std::string& name);
  std::string GetCommentName(const std::string& model_name);
  void RemoveCommentFromTableCommentsInDatabase(const std::string& model_name);
private:
  DatabaseManager* database_manager_;
};

#endif