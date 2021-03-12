#ifndef HOMEBOOKKEEPING_1DATAACCESS_DESCRIPTIONREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_DESCRIPTIONREPOSITORY_H_

//  Class DescriptionRepository
//
//  Constructors:
//    Default
//
//  Class member functions:
//    Add description to repository
//    Add description (shared pointer) to repository
//    Remove description (shared pointer) from repository
//    Calculate size of repository
//    Clear repository
//    Find description (shared pointer) in repository
//    Find begin iterator of repository
//    Find end iterator of repository
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
  void Add(Description description);
  void Add(std::shared_ptr<Description> description);
  void Remove(std::shared_ptr<Description> description);
  size_t Size() const;
  void Clear();
  DescriptionRepositoryIterator Find(std::shared_ptr<Description> description) const;
  DescriptionRepositoryIterator Begin() const;
  DescriptionRepositoryIterator End() const;
private:
  std::set<std::shared_ptr<Description>> repository_;
};

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_DESCRIPTIONREPOSITORY_H_
