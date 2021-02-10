#include "Category.h"

Category::Category():
	categoryName{ "" }
{}

Category::Category(std::string categoryNameForAdd):
	categoryName{ categoryNameForAdd }
{}

std::string Category::getCategoryName() const
{
	return categoryName;
}

void Category::setCategoryName(std::string&& categoryNameForUpdate)
{
	categoryName = std::move(categoryNameForUpdate);
}

bool operator<(const Category& leftCategory, const Category& rightCategory)
{
	return (leftCategory.getCategoryName()) < (rightCategory.getCategoryName());
}

std::ostream& operator<<(std::ostream& outputStream, const Category& category)
{
	return outputStream << category.getCategoryName();
}