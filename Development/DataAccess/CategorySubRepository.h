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
	void add(std::string name)
	{
		repository.insert(name);
	}
	void remove(std::string name)
	{
		repository.erase(name);
	}
};

#endif