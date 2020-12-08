#include "CategorySubRepository.h"

CategorySubRepository::CategorySubRepository()
{}

void CategorySubRepository::addCategorySub(CategorySub categorySubForAdd)
{
	categorySubRepository.insert(categorySubForAdd);
}

void CategorySubRepository::removeCategorySub(CategorySub categorySubForRemove)
{
	categorySubRepository.erase(categorySubForRemove);
}

std::set<CategorySub> CategorySubRepository::getCategorySubRepository() const
{
	return categorySubRepository;
}

void CategorySubRepository::setCategorySubRepository(std::set<CategorySub>&& categoriesSubForAdd)
{
	categorySubRepository = categoriesSubForAdd;
}