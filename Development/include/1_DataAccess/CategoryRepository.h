#ifndef HOMEBOOKKEEPING_1DATAACCESS_CATEGORYREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_CATEGORYREPOSITORY_H_

#include <iostream>
#include <map>

#include "include/0_Models/Category.h"

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

#endif
