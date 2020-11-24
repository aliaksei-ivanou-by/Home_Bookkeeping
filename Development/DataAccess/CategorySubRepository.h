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
	std::set<CategorySub> categorySubRepository;
public:
	CategorySubRepository()
	{}
	void addCategorySub(CategorySub categorySub)
	{
		categorySubRepository.insert(categorySub);
	}
	void removeCategorySub(CategorySub categorySub)
	{
		categorySubRepository.erase(categorySub);
	}
	std::set<CategorySub> getCategorySubRepository() const
	{
		return categorySubRepository;
	}
	void setCategorySubRepository(std::set<CategorySub>&& categoriesSub)
	{
		categorySubRepository = categoriesSub;
	}
};

#endif