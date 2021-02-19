#include "CategoryRepository.h"

CategoryRepository::CategoryRepository()
{}

void CategoryRepository::add(Category categoryForAdd)
{
	repository.insert(std::make_shared<Category>(categoryForAdd));
}

void CategoryRepository::add(std::shared_ptr<Category> categoryForAdd)
{
	repository.insert(categoryForAdd);
}

void CategoryRepository::remove(std::shared_ptr<Category> categoryForRemove)
{
	repository.erase(categoryForRemove);
}

size_t CategoryRepository::size() const
{
	return repository.size();
}

void CategoryRepository::clear()
{
	repository.clear();
}

CategoryRepositoryIterator CategoryRepository::find(std::shared_ptr<Category> categoryForFind) const
{
	return repository.find(categoryForFind);
}

CategoryRepositoryIterator CategoryRepository::begin() const
{
	return repository.begin();
}

CategoryRepositoryIterator CategoryRepository::end() const
{
	return repository.end();
}