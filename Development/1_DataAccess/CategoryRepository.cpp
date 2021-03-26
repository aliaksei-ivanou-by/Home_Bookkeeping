#include "home_bookkeeping/1_DataAccess/CategoryRepository.h"

//  Constructor
//  Default
CategoryRepository::CategoryRepository()
{}

//  Class member function
//  Add category (default) to repository
void CategoryRepository::Add()
{
  repository_.insert(std::make_shared<Category>());
}

//  Class member function
//  Add category to repository
void CategoryRepository::Add(Category category)
{
  repository_.insert(std::make_shared<Category>(category));
}

//  Class member function
//  Add category (shared pointer) to repository
void CategoryRepository::Add(std::shared_ptr<Category> category)
{
  repository_.insert(category);
}

//  Class member function
//  Remove category (shared pointer) from repository
void CategoryRepository::Remove(std::shared_ptr<Category> category)
{
  repository_.erase(category);
}

//  Class member function
//  Get name of category from repository
std::string CategoryRepository::GetName(CategoryRepositoryIterator category) const
{
  return (**category).GetName();
}

//  Class member function
//  Set name of category from repository
void CategoryRepository::SetName(CategoryRepositoryIterator category, const std::string& name)
{
  (**category).SetName(name);
}

//  Class member function
//  Calculate size of repository
size_t CategoryRepository::Size() const
{
  return repository_.size();
}

//  Class member function
//  Clear repository
void CategoryRepository::Clear()
{
  repository_.clear();
}

//  Class member function
//  Find category (shared pointer) in repository
CategoryRepositoryIterator CategoryRepository::Find(std::shared_ptr<Category> category) const
{
  return repository_.find(category);
}

//  Class member function
//  Find category with definite name in repository
CategoryRepositoryIterator CategoryRepository::Find(const std::string& name) const
{
  for (auto i = repository_.begin(); i != repository_.end(); ++i)
  {
    if ((**i).GetName() == name)
    {
      return i;
    }
  }
  return repository_.end();
}

//  Class member function
//  Find begin iterator of repository
CategoryRepositoryIterator CategoryRepository::Begin() const
{
  return repository_.begin();
}

//  Class member function
//  Find end iterator of repository
CategoryRepositoryIterator CategoryRepository::End() const
{
  return repository_.end();
}
