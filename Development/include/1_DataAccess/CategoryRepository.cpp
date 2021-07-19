#include "include/1_DataAccess/CategoryRepository.h"

CategoryRepository::CategoryRepository()
{}

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

void CategoryRepository::Add()
{
  std::shared_ptr<Category> category_temp = std::make_shared<Category>(Category());
  AddCategory(category_temp);
}

void CategoryRepository::Add(Category category)
{
  std::shared_ptr<Category> category_temp = std::make_shared<Category>(category);
  AddCategory(category_temp);
}

void CategoryRepository::Add(std::shared_ptr<Category> category)
{
  AddCategory(category);
}

void CategoryRepository::Remove(std::shared_ptr<Category> category)
{
  auto iterator = repository_.find(category);
  if (iterator != repository_.end())
  {
    repository_.erase(iterator);
    PLOG_INFO << "Remove category from category repository";
  }
  else
  {
    PLOG_ERROR << "Category repository haven't got category '" << category->GetName() << "'";
  }
}

std::string CategoryRepository::GetName(CategoryRepositoryIterator category) const
{
  return category->first->GetName();
}

void CategoryRepository::SetName(CategoryRepositoryIterator category, const std::string& name)
{
  category->first->SetName(name);
  PLOG_INFO << "Set new name of category in category repository";
}

size_t CategoryRepository::Size() const
{
  return repository_.size();
}

void CategoryRepository::Clear()
{
  repository_.clear();
  PLOG_INFO << "Clear category repository";
}

CategoryRepositoryConstIterator CategoryRepository::Find(std::shared_ptr<Category> category) const
{
  return repository_.find(category);
}

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

CategoryRepositoryConstIterator CategoryRepository::Begin() const
{
  return repository_.begin();
}

CategoryRepositoryConstIterator CategoryRepository::End() const
{
  return repository_.end();
}
