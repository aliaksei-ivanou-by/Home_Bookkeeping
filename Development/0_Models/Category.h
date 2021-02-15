#pragma once

#include "../include/stdafx.h"

class Category
{
private:
	std::string categoryName;
public:
	Category();
	Category(const std::string& categoryNameForAdd);
	std::string getCategoryName() const;
	void setCategoryName(const std::string& categoryNameForUpdate);
	friend bool operator<(const Category& leftCategory, const Category& rightCategory);
	friend std::ostream& operator<<(std::ostream& outputStream, const Category& category);
};