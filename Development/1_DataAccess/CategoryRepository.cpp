#include "CategoryRepository.h"

// Default constructor
CategoryRepository::CategoryRepository()
{}

// Class member function. Add category to repository
void CategoryRepository::add(Category categoryForAdd)
{
	repository.insert(std::make_shared<Category>(categoryForAdd));
}

// Class member function. Add shared pointer to category to repository
void CategoryRepository::add(std::shared_ptr<Category> categoryForAdd)
{
	repository.insert(categoryForAdd);
}

// Class member function. Remove shared pointer to category from repository
void CategoryRepository::remove(std::shared_ptr<Category> categoryForRemove)
{
	repository.erase(categoryForRemove);
}

// Class member function. Calculate size of repository
size_t CategoryRepository::size() const
{
	return repository.size();
}

// Class member function. Clear repository
void CategoryRepository::clear()
{
	repository.clear();
}

// Class member function. Find shared pointer to category in repository
CategoryRepositoryIterator CategoryRepository::find(std::shared_ptr<Category> categoryForFind) const
{
	return repository.find(categoryForFind);
}

// Class member function. Find begin iterator of repository
CategoryRepositoryIterator CategoryRepository::begin() const
{
	return repository.begin();
}

// Class member function. Find end iterator of repository
CategoryRepositoryIterator CategoryRepository::end() const
{
	return repository.end();
}