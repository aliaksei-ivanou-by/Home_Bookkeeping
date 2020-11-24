#pragma once

#ifndef CATEGORYSUB_H
#define CATEGORYSUB_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class CategorySub
{
private:
	std::string categorySubName;
public:
	CategorySub()
		: categorySubName{ "" }
	{}
	CategorySub(std::string categorySubName)
		: categorySubName{ categorySubName }
	{}
	std::string getCategorySubName() const
	{
		return this->categorySubName;
	}
	void seName(std::string&& categorySubName)
	{
		this->categorySubName = categorySubName;
	}
	friend bool operator<(const CategorySub& leftCategorySub, const CategorySub& rightCategorySub)
	{
		return (leftCategorySub.getCategorySubName()) < (rightCategorySub.getCategorySubName());
	}
	friend std::ostream& operator<<(std::ostream& outputStream, const CategorySub& categorySub)
	{
		return outputStream << categorySub.getCategorySubName();
	}
};

#endif