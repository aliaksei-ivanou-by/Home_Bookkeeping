#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Category.h"

using CategoryRepositoryIterator = std::set<Category>::iterator;

class CategoryRepository
{
private:
	std::set<Category> repository;
public:
	CategoryRepository();
	void add(Category categoryForAdd);
	void remove(Category categoryforRemove);
	size_t size() const;
	void clear();
	CategoryRepositoryIterator find(const Category& categoryForFind) const;
	CategoryRepositoryIterator begin() const;
	CategoryRepositoryIterator end() const;
};