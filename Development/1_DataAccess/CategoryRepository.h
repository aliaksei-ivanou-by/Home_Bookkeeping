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
//    Get name of category from repository
//    Set name of category from repository
//    Calculate size of repository
//    Clear repository
//    Find category (shared pointer) in repository
//    Find category with definite name in repository
//    Find begin iterator of repository
//    Find end iterator of repository
//
//  Variables:
//    repository

#include <iostream>
#include <map>

#include "home_bookkeeping/0_Models/Category.h"

using CategoryRepositoryIterator = std::map<std::shared_ptr<Category>, int>::iterator;
using CategoryRepositoryConstIterator = std::map<std::shared_ptr<Category>, int>::const_iterator;

class CategoryRepository
{
public:
  CategoryRepository();
  void Add();
  void Add(Category category);
  void Add(std::shared_ptr<Category> category);
  void Remove(std::shared_ptr<Category> category);
  std::string GetName(CategoryRepositoryIterator category) const;
  void SetName(CategoryRepositoryIterator category, const std::string& name);
  size_t Size() const;
  void Clear();
  CategoryRepositoryConstIterator Find(std::shared_ptr<Category> category) const;
  CategoryRepositoryConstIterator Find(const std::string& category) const;
  CategoryRepositoryConstIterator Begin() const;
  CategoryRepositoryConstIterator End() const;
private:
  void AddCategory(std::shared_ptr<Category> category);
  std::map<std::shared_ptr<Category>, int> repository_;
};

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_CATEGORYREPOSITORY_H_
