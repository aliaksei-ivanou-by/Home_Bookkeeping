#include "CategoryRepository.h"

CategoryRepository::CategoryRepository()
{}

void CategoryRepository::addCategory(Category categoryForAdd)
{
	categoryRepository.insert(categoryForAdd);
}

void CategoryRepository::removeCategory(Category categoryForRemove)
{
	categoryRepository.erase(categoryForRemove);
}

size_t CategoryRepository::sizeCategoryRepository() const
{
	return categoryRepository.size();
}

void CategoryRepository::clearCategoryRepository()
{
	categoryRepository.clear();
}

CategoryRepositoryIterator CategoryRepository::findCategoryRepository(Category&& categoryForFind) const
{
	return categoryRepository.find(std::move(categoryForFind));
}