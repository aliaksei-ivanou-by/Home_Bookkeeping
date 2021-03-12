#ifndef HOMEBOOKKEEPING_1DATAACCESS_COMMENTREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_COMMENTREPOSITORY_H_

//  Class CommentRepository
//
//  Constructors:
//    Default
//
//  Class member functions:
//    Add comment to repository
//    Add shared pointer to comment to repository
//    Remove shared pointer to comment from repository
//    Calculate size of repository
//    Clear repository
//    Find shared pointer to comment in repository
//    Find begin iterator of repository
//    Find end iterator of repository
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
  void Add(Comment comment);
  void Add(std::shared_ptr<Comment> comment);
  void Remove(std::shared_ptr<Comment> comment);
  size_t Size() const;
  void Clear();
  CommentRepositoryIterator Find(std::shared_ptr<Comment> comment) const;
  CommentRepositoryIterator Begin() const;
  CommentRepositoryIterator End() const;
private:
  std::set<std::shared_ptr<Comment>> repository_;
};

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_COMMENTREPOSITORY_H_
