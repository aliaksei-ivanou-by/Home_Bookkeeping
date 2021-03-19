#ifndef HOMEBOOKKEEPING_1DATAACCESS_CATEGORYREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_CATEGORYREPOSITORY_H_

//  Class CategoryRepository
//
//  Constructors:
//    Default
//
//  Class member functions:
//    Add category (default) to repository
//    Add category to repository
//    Add category (shared pointer) to repository
//    Remove category (shared pointer) from repository
//    Calculate size of repository
//    Clear repository
//    Find category (shared pointer) in repository
//    Find begin iterator of repository
//    Find end iterator of repository
//
//  Variables:
//    repository

#include <iostream>
#include <set>

#include "home_bookkeeping/0_Models/Category.h"

using CategoryRepositoryIterator = std::set<std::shared_ptr<Category>>::iterator;

class CategoryRepository
{
public:
  CategoryRepository();
  void Add();
  void Add(Category category);
  void Add(std::shared_ptr<Category> category);
  void Remove(std::shared_ptr<Category> category);
  size_t Size() const;
  void Clear();
  CategoryRepositoryIterator Find(std::shared_ptr<Category> category) const;
  CategoryRepositoryIterator Begin() const;
  CategoryRepositoryIterator End() const;
private:
  std::set<std::shared_ptr<Category>> repository_;
};

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_CATEGORYREPOSITORY_H_
