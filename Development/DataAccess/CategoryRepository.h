#pragma once

#include "../include/stdafx.h"
#include "../Models/Category.h"

class CategoryRepository
{
private:
	std::set<Category> categoryRepository;
public:
	CategoryRepository();
	void addCategory(Category categoryForAdd);
	void removeCategory(Category categoryforRemove);
	std::set<Category> getCategoryRepository() const;
	void setCategoryRepository(std::set<Category>&& categoriesForAdd);
};