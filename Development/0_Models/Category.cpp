#include "Category.h"

Category::Category():
	categoryName{ "" }
{}

Category::Category(const std::string& categoryNameForAdd):
	categoryName{ categoryNameForAdd }
{}

std::string Category::getCategoryName() const
{
	return categoryName;
}

void Category::setCategoryName(const std::string& categoryNameForUpdate)
{
	categoryName = categoryNameForUpdate;
}

bool operator<(const Category& leftCategory, const Category& rightCategory)
{
	return (leftCategory.getCategoryName()) < (rightCategory.getCategoryName());
}

std::ostream& operator<<(std::ostream& outputStream, const Category& category)
{
	return outputStream << category.getCategoryName();
}