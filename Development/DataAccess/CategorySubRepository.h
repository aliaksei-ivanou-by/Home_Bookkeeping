#pragma once

#include "../include/stdafx.h"
#include "../Models/CategorySub.h"

class CategorySubRepository
{
private:
	std::set<CategorySub> categorySubRepository;
public:
	CategorySubRepository();
	void addCategorySub(CategorySub categorySubForAdd);
	void removeCategorySub(CategorySub categorySubForRemove);
	std::set<CategorySub> getCategorySubRepository() const;
	void setCategorySubRepository(std::set<CategorySub>&& categoriesSubForAdd);
};