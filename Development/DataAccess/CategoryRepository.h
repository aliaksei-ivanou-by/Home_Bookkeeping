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
	std::set<Category> repository;
public:
	CategoryRepository() {}
	void add(Category name)
	{
		repository.insert(name);
	}
	void remove(Category name)
	{
		repository.erase(name);
	}
	std::set<Category> get_categories() const
	{
		return repository;
	}
};

#endif