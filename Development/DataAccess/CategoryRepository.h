#pragma once

#ifndef CATEGORYREPOSITORY_H
#define CATEGORYREPOSITORY_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

#ifndef CATEGORY_H
#include "../Models/Category.h"
#endif

class CategoryRepository
{
private:
	std::set<Category> categoryRepository;
public:
	CategoryRepository()
	{}
	void addCategory(Category category)
	{
		categoryRepository.insert(category);
	}
	void removeCategory(Category category)
	{
		categoryRepository.erase(category);
	}
	std::set<Category> getCategoryRepository() const
	{
		return categoryRepository;
	}
};

#endif