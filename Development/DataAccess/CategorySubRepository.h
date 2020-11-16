#pragma once

#ifndef CATEGORYSUBREPOSITORY_H
#define CATEGORYSUBREPOSITORY_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

#ifndef CATEGORYSUB_H
#include "../Models/CategorySub.h"
#endif

class CategorySubRepository
{
private:
	std::set<CategorySub> repository;
public:
	CategorySubRepository() {}
	void add(CategorySub name)
	{
		repository.insert(name);
	}
	void remove(CategorySub name)
	{
		repository.erase(name);
	}
	std::set<CategorySub> get_categorysub_repository() const
	{
		return repository;
	}
};

#endif