#include "GlobalCategories.h"

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
	repository.insert(name);
}

void Rep_Categories::remove(std::string name)
{
	repository.erase(name);
}

std::ostream& operator<<(std::ostream& os, const Categories& i)
{
	return os << i.get_name();
}

void Rep_Categories::print() const
{
	std::cout << "==========\nCaregories:\n";
	for (const auto& i : repository)
	{
		std::cout << '\t' << i << '\n';
	}
	std::cout << "==========\n";
}