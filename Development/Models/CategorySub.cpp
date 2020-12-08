#include "CategorySub.h"

CategorySub::CategorySub():
	categorySubName{ "" }
{}

CategorySub::CategorySub(std::string categorySubNameNew):
	categorySubName{ categorySubNameNew }
{}

std::string CategorySub::getCategorySubName() const
{
	return categorySubName;
}

void CategorySub::setName(std::string&& categorySubNameNew)
{
	categorySubName = std::move(categorySubNameNew);
}

bool operator<(const CategorySub& leftCategorySub, const CategorySub& rightCategorySub)
{
	return (leftCategorySub.getCategorySubName()) < (rightCategorySub.getCategorySubName());
}

std::ostream& operator<<(std::ostream& outputStream, const CategorySub& categorySub)
{
	return outputStream << categorySub.getCategorySubName();
}