#ifndef HOMEBOOKKEEPING_1DATAACCESS_DESCRIPTIONREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_DESCRIPTIONREPOSITORY_H_

//  Class DescriptionRepository
//
//  Constructors:
//    Default
//
//  Class member functions:
//    Add description (default) to repository
//    Add description to repository
//    Add description (shared pointer) to repository
//    Remove description (shared pointer) from repository
//    Get name of description from repository
//    Set name of description from repository
//    Calculate size of repository
//    Clear repository
//    Find description (shared pointer) in repository
//    Find description with definite name in repository
//    Find begin iterator of repository
//    Find end iterator of repository
//    Make command to create table for repository in database
//    Make command to insert repository to database to table
//
//  Variables:
//    repository

#include <iostream>
#include <set>

#include "home_bookkeeping/0_Models/Description.h"

using DescriptionRepositoryIterator = std::set<std::shared_ptr<Description>>::iterator;

class DescriptionRepository
{
public:
  DescriptionRepository();
  void Add();
  void Add(Description description);
  void Add(std::shared_ptr<Description> description);
  void Remove(std::shared_ptr<Description> description);
  std::string GetName(DescriptionRepositoryIterator description) const;
  void SetName(DescriptionRepositoryIterator description, const std::string& name);
  size_t Size() const;
  void Clear();
  DescriptionRepositoryIterator Find(std::shared_ptr<Description> description) const;
  DescriptionRepositoryIterator Find(const std::string& description) const;
  DescriptionRepositoryIterator Begin() const;
  DescriptionRepositoryIterator End() const;
  std::string MakeCommandToCreateRepositoryInDatabase() const;
  std::string MakeCommandToInsertRepositoryToDatabase(size_t counter, DescriptionRepositoryIterator iterator) const;
private:
  std::set<std::shared_ptr<Description>> repository_;
};

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_DESCRIPTIONREPOSITORY_H_
