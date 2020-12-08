#pragma once

#include "../include/stdafx.h"

class Category
{
private:
	std::string categoryName;
public:
	Category();
	Category(std::string categoryNameNew);
	std::string getCategoryName() const;
	void setCategoryName(std::string&& categoryNameNew);
	friend bool operator<(const Category& leftCategory, const Category& rightCategory);
	friend std::ostream& operator<<(std::ostream& outputStream, const Category& category);
};