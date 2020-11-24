#pragma once

#ifndef CATEGORY_H
#define CATEGORY_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class Category
{
private:
	std::string categoryName;
public:
	Category()
		: categoryName{ "" }
	{}
	Category(std::string categoryName)
		: categoryName{ categoryName }
	{}
	std::string getCategoryName() const
	{
		return this->categoryName;
	}
	void setCategoryName(std::string&& categoryName)
	{
		this->categoryName = categoryName;
	}
	friend bool operator<(const Category& leftCategory, const Category& rightCategory)
	{
		return (leftCategory.getCategoryName()) < (rightCategory.getCategoryName());
	}
	friend std::ostream& operator<<(std::ostream& outputStream, const Category& category)
	{
		return outputStream << category.getCategoryName();
	}
};

#endif