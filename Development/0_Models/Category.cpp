#include "Category.h"

// Default constructor
Category::Category():
	categoryName{ "Unspecified" }
{}

// Constructor with the setting of the name of the category
Category::Category(const std::string& categoryNameForAdd):
	categoryName{ categoryNameForAdd }
{}

// Class member function. Get the name of the category
std::string Category::getCategoryName() const
{
	return categoryName;
}

// Class member function. Set the name of the category
void Category::setCategoryName(const std::string& categoryNameForUpdate)
{
	categoryName = categoryNameForUpdate;
}

// Class member function. Operator < for sorting categories
bool operator<(const Category& leftCategory, const Category& rightCategory)
{
	return (leftCategory.getCategoryName()) < (rightCategory.getCategoryName());
}

// Class member function. Print category
std::ostream& operator<<(std::ostream& outputStream, const Category& category)
{
	return outputStream << category.getCategoryName();
}