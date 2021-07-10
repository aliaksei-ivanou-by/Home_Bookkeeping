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
//
//  Variables:
//    repository

#include <iostream>
#include <map>

#include "include/0_Models/Comment.h"

using CommentRepositoryIterator = std::map<std::shared_ptr<Comment>, int>::iterator;
using CommentRepositoryConstIterator = std::map<std::shared_ptr<Comment>, int>::const_iterator;

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
  CommentRepositoryConstIterator Find(std::shared_ptr<Comment> comment) const;
  CommentRepositoryConstIterator Find(const std::string& comment) const;
  CommentRepositoryConstIterator Begin() const;
  CommentRepositoryConstIterator End() const;
private:
  void AddComment(std::shared_ptr<Comment> comment);
  std::map<std::shared_ptr<Comment>, int> repository_;
};

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_COMMENTREPOSITORY_H_
