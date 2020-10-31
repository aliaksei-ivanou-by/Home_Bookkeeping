#include "RepCategories.h"

Categories::Categories()
	: Category_Name{ "" }
{}

Categories::Categories(std::string name)
	: Category_Name{ name }
{}

std::string Categories::get_name() const
{
	return this->Category_Name;
}

void Categories::set_name(std::string name)
{
	this->Category_Name = name;
}

bool operator<(const Categories& lhs, const Categories& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

Rep_Categories::Rep_Categories()
{}

void Rep_Categories::add(std::string name)
{
	Categories temp(name);
	repository.insert(temp);
}

void Rep_Categories::remove(std::string name)
{
	Categories temp(name);
	repository.erase(temp);
}

void Rep_Categories::print() const
{
	for (const auto& i : repository)
	{
		std::cout << i.get_name() << '\n';
	}
}