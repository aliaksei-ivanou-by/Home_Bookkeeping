#ifndef HOMEBOOKKEEPING_1DATAACCESS_TAGREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_TAGREPOSITORY_H_

//  Class TagRepository
//
//  Constructors:
//    Default
//
//  Class member functions:
//    Add tag to repository
//    Add tag (shared pointer) to repository
//    Remove tag (shared pointer) from repository
//    Calculate size of repository
//    Clear repository
//    Find tag (shared pointer) in repository
//    Find begin iterator of repository
//    Find end iterator of repository
//
//  Variables:
//    repository

#include <iostream>
#include <set>

#include "home_bookkeeping/0_Models/Tag.h"

using TagRepositoryIterator = std::set<std::shared_ptr<Tag>>::iterator;

class TagRepository
{
public:
  TagRepository();
  void Add(Tag tag);
  void Add(std::shared_ptr<Tag> tag);
  void Remove(std::shared_ptr<Tag> tag);
  size_t Size() const;
  void Clear();
  TagRepositoryIterator Find(std::shared_ptr<Tag> tag) const;
  TagRepositoryIterator Begin() const;
  TagRepositoryIterator End() const;
private:
  std::set<std::shared_ptr<Tag>> repository_;
};

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_TAGREPOSITORY_H_
