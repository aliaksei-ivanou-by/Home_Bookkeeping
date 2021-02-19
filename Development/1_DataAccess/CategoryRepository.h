#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Category.h"

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