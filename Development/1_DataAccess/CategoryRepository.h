#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Category.h"

class CategoryRepository
{
private:
	std::set<Category> categoryRepository;
public:
	CategoryRepository();
	void addCategory(Category categoryForAdd);
	void removeCategory(Category categoryforRemove);
	size_t sizeCategoryRepository();
};