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

std::set<Category> CategoryRepository::getCategoryRepository() const
{
	return categoryRepository;
}

void CategoryRepository::setCategoryRepository(std::set<Category>&& categoriesForAdd)
{
	categoryRepository = categoriesForAdd;
}