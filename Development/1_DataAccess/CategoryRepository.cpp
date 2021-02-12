#include "CategoryRepository.h"

CategoryRepository::CategoryRepository()
{}

void CategoryRepository::add(Category categoryForAdd)
{
	repository.insert(categoryForAdd);
}

void CategoryRepository::remove(Category categoryForRemove)
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

CategoryRepositoryIterator CategoryRepository::find(Category&& categoryForFind) const
{
	return repository.find(std::move(categoryForFind));
}