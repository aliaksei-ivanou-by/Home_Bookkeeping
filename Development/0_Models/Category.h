#pragma once
#include "../include/stdafx.h"

/*
Class Category
Includes category name.

Constructors:
	Default (name of the category = categoryNameUnspecified)
	With the setting of the name of the category

Class member functions:
	Get the name of the category
	Set the name of the category
	Operator < for sorting categories
	Print category
*/

class Category
{
private:
	std::string categoryName;
	std::string categoryNameUnspecified = "Unspecified";
public:
	Category();
	Category(const std::string& categoryNameForAdd);

	std::string getCategoryName() const;

	void setCategoryName(const std::string& categoryNameForUpdate);

	friend bool operator<(const Category& leftCategory, const Category& rightCategory);
	friend std::ostream& operator<<(std::ostream& outputStream, const Category& category);
};