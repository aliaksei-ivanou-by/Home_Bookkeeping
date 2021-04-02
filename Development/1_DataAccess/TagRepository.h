#ifndef HOMEBOOKKEEPING_1DATAACCESS_TAGREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_TAGREPOSITORY_H_

//  Class TagRepository
//
//  Constructors:
//    Default
//
//  Class member functions:
//    Add tag (default) to repository
//    Add tag to repository
//    Add tag (shared pointer) to repository
//    Remove tag (shared pointer) from repository
//    Get name of tag from repository
//    Set name of tag from repository
//    Calculate size of repository
//    Clear repository
//    Find tag (shared pointer) in repository
//    Find tag with definite name in repository
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

#include "home_bookkeeping/0_Models/Tag.h"

using TagRepositoryIterator = std::set<std::shared_ptr<Tag>>::iterator;

class TagRepository
{
public:
  TagRepository();
  void Add();
  void Add(Tag tag);
  void Add(std::shared_ptr<Tag> tag);
  void Remove(std::shared_ptr<Tag> tag);
  std::string GetName(TagRepositoryIterator tag) const;
  void SetName(TagRepositoryIterator tag, const std::string& name);
  size_t Size() const;
  void Clear();
  TagRepositoryIterator Find(std::shared_ptr<Tag> tag) const;
  TagRepositoryIterator Find(std::string name) const;
  TagRepositoryIterator Begin() const;
  TagRepositoryIterator End() const;
  std::string MakeCommandToCreateRepositoryInDatabase() const;
  std::string MakeCommandToInsertRepositoryToDatabase(size_t counter, TagRepositoryIterator iterator) const;
  std::string MakeCommandToRemoveRepositoryFromDatabase() const;
private:
  std::set<std::shared_ptr<Tag>> repository_;
};

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_TAGREPOSITORY_H_
