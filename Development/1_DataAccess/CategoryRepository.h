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
//    Make command to create table for repository in database
//    Make command to insert repository to database to table
//    Make command to remove table for repository from database
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
  std::string GetName(CategoryRepositoryIterator category) const;
  void SetName(CategoryRepositoryIterator category, const std::string& name);
  size_t Size() const;
  void Clear();
  CategoryRepositoryIterator Find(std::shared_ptr<Category> category) const;
  CategoryRepositoryIterator Find(const std::string& category) const;
  CategoryRepositoryIterator Begin() const;
  CategoryRepositoryIterator End() const;
  std::string MakeCommandToCreateRepositoryInDatabase() const;
  std::string MakeCommandToInsertRepositoryToDatabase(size_t counter, CategoryRepositoryIterator iterator) const;
  std::string MakeCommandToRemoveRepositoryFromDatabase() const;
private:
  std::set<std::shared_ptr<Category>> repository_;
};

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_CATEGORYREPOSITORY_H_
