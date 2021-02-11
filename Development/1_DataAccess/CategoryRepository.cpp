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