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

size_t CategoryRepository::sizeCategoryRepository()
{
	return categoryRepository.size();
}

void CategoryRepository::clearCategoryRepository()
{
	categoryRepository.clear();
}

CategoryRepositoryIterator CategoryRepository::findCategoryRepository(Category&& categoryForFind)
{
	return categoryRepository.find(std::move(categoryForFind));
}