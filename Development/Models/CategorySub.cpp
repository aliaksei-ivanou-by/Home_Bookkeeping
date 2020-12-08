#include "CategorySub.h"

CategorySub::CategorySub():
	categorySubName{ "" }
{}

CategorySub::CategorySub(std::string categorySubNameForAdd):
	categorySubName{ categorySubNameForAdd }
{}

std::string CategorySub::getCategorySubName() const
{
	return categorySubName;
}

void CategorySub::setName(std::string&& categorySubNameForUpdate)
{
	categorySubName = std::move(categorySubNameForUpdate);
}

bool operator<(const CategorySub& leftCategorySub, const CategorySub& rightCategorySub)
{
	return (leftCategorySub.getCategorySubName()) < (rightCategorySub.getCategorySubName());
}

std::ostream& operator<<(std::ostream& outputStream, const CategorySub& categorySub)
{
	return outputStream << categorySub.getCategorySubName();
}