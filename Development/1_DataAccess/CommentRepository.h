#ifndef HOMEBOOKKEEPING_1DATAACCESS_COMMENTREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_COMMENTREPOSITORY_H_

//  Class CommentRepository
//
//  Constructors:
//    Default
//
//  Class member functions:
//    Add comment (default) to repository
//    Add comment to repository
//    Add shared pointer to comment to repository
//    Remove shared pointer to comment from repository
//    Get name of comment from repository
//    Set name of comment from repository
//    Calculate size of repository
//    Clear repository
//    Find shared pointer to comment in repository
//    Find comment with definite name in repository
//    Find begin iterator of repository
//    Find end iterator of repository
//    Make command to create table for repository in database
//    Make command to insert repository to database to table
//    Make command to remove table for repository from database
//
//  Variables:
//    repository

#include <iostream>
#include <set>

#include "home_bookkeeping/0_Models/Comment.h"

using CommentRepositoryIterator = std::set<std::shared_ptr<Comment>>::iterator;

class CommentRepository
{
public:
  CommentRepository();
  void Add();
  void Add(Comment comment);
  void Add(std::shared_ptr<Comment> comment);
  void Remove(std::shared_ptr<Comment> comment);
  std::string GetName(CommentRepositoryIterator comment) const;
  void SetName(CommentRepositoryIterator comment, const std::string& name);
  size_t Size() const;
  void Clear();
  CommentRepositoryIterator Find(std::shared_ptr<Comment> comment) const;
  CommentRepositoryIterator Find(const std::string& comment) const;
  CommentRepositoryIterator Begin() const;
  CommentRepositoryIterator End() const;
  std::string MakeCommandToCreateRepositoryInDatabase() const;
  std::string MakeCommandToInsertRepositoryToDatabase(size_t counter, CommentRepositoryIterator iterator) const;
  std::string MakeCommandToRemoveRepositoryFromDatabase() const;
private:
  std::set<std::shared_ptr<Comment>> repository_;
};

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_COMMENTREPOSITORY_H_
