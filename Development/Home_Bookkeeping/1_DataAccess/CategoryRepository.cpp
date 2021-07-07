#include "Home_Bookkeeping/1_DataAccess/CategoryRepository.h"

//  Constructor
//  Default
CategoryRepository::CategoryRepository()
{}

//  Class member function (private)
//  Add category (shared pointer) to repository
void CategoryRepository::AddCategory(std::shared_ptr<Category> category)
{
  for (auto& i : repository_)
  {
    if (i.first->GetName() == category->GetName())
    {
      ++i.second;
      PLOG_INFO << "Add category to category repository (counter + 1)";
      return;
    }
  }
  repository_[category] = 1;
  PLOG_INFO << "Add category to category repository";
}

//  Class member function
//  Add category (default) to repository
void CategoryRepository::Add()
{
  std::shared_ptr<Category> category_temp = std::make_shared<Category>(Category());
  AddCategory(category_temp);
}

//  Class member function
//  Add category to repository
void CategoryRepository::Add(Category category)
{
  std::shared_ptr<Category> category_temp = std::make_shared<Category>(category);
  AddCategory(category_temp);
}

//  Class member function
//  Add category (shared pointer) to repository
void CategoryRepository::Add(std::shared_ptr<Category> category)
{
  AddCategory(category);
}

//  Class member function
//  Remove category (shared pointer) from repository
void CategoryRepository::Remove(std::shared_ptr<Category> category)
{
  auto iterator = repository_.find(category);
  if (iterator != repository_.end())
  {
    repository_.erase(iterator);
    //PLOG_INFO << "Remove category from category repository";
  }
  else
  {
    PLOG_ERROR << "Category repository haven't got category '" << category->GetName() << "'";
  }
}

//  Class member function
//  Get name of category from repository
std::string CategoryRepository::GetName(CategoryRepositoryIterator category) const
{
  return category->first->GetName();
}

//  Class member function
//  Set name of category from repository
void CategoryRepository::SetName(CategoryRepositoryIterator category, const std::string& name)
{
  category->first->SetName(name);
  PLOG_INFO << "Set new name of category in category repository";
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
  PLOG_INFO << "Clear category repository";
}

//  Class member function
//  Find category (shared pointer) in repository
CategoryRepositoryConstIterator CategoryRepository::Find(std::shared_ptr<Category> category) const
{
  return repository_.find(category);
}

//  Class member function
//  Find category with definite name in repository
CategoryRepositoryConstIterator CategoryRepository::Find(const std::string& name) const
{
  for (auto i = repository_.begin(); i != repository_.end(); ++i)
  {
    if (i->first->GetName() == name)
    {
      return i;
    }
  }
  return repository_.end();
}

//  Class member function
//  Find begin iterator of repository
CategoryRepositoryConstIterator CategoryRepository::Begin() const
{
  return repository_.begin();
}

//  Class member function
//  Find end iterator of repository
CategoryRepositoryConstIterator CategoryRepository::End() const
{
  return repository_.end();
}
