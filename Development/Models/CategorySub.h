#pragma once

#include "../include/stdafx.h"

class CategorySub
{
private:
	std::string categorySubName;
public:
	CategorySub();
	CategorySub(std::string categorySubNameForAdd);
	std::string getCategorySubName() const;
	void setName(std::string&& categorySubNameForUpdate);
	friend bool operator<(const CategorySub& leftCategorySub, const CategorySub& rightCategorySub);
	friend std::ostream& operator<<(std::ostream& outputStream, const CategorySub& categorySub);
};