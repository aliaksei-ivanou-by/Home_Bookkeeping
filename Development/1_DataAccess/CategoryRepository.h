#pragma once
#include "../include/stdafx.h"
#include "../0_Models/Category.h"

/*
Class CategoryRepository
Includes repository of categories.

Constructors:
	Default

Class member functions:
	Add category to repository
	Add shared pointer to category to repository
	Remove shared pointer to category from repository
	Calculate size of repository
	Clear repository
	Find shared pointer to category in repository
	Find begin iterator of repository
	Find end iterator of repository
*/

using CategoryRepositoryIterator = std::set<std::shared_ptr<Category>>::iterator;

class CategoryRepository
{
private:
	std::set<std::shared_ptr<Category>> repository;
public:
	CategoryRepository();

	void add(Category categoryForAdd);

	void add(std::shared_ptr<Category> categoryForAdd);
	void remove(std::shared_ptr<Category> categoryforRemove);

	size_t size() const;

	void clear();

	CategoryRepositoryIterator find(std::shared_ptr<Category> categoryForFind) const;

	CategoryRepositoryIterator begin() const;
	CategoryRepositoryIterator end() const;
};