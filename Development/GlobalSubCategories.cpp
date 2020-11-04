#include "GlobalSubCategories.h"

SubCategories::SubCategories()
	: SubCategory_Name{ "" }
{}

SubCategories::SubCategories(std::string name)
	: SubCategory_Name{ name }
{}

std::string SubCategories::get_name() const
{
	return this->SubCategory_Name;
}

void SubCategories::set_name(std::string name)
{
	this->SubCategory_Name = name;
}

bool operator<(const SubCategories& lhs, const SubCategories& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

Rep_SubCategories::Rep_SubCategories()
{}

void Rep_SubCategories::add(std::string name)
{
	SubCategories temp(name);
	repository.insert(temp);
}

void Rep_SubCategories::remove(std::string name)
{
	SubCategories temp(name);
	repository.erase(temp);
}

std::ostream& operator<<(std::ostream& os, const SubCategories& i)
{
	return os << i.get_name();
}

void Rep_SubCategories::print() const
{
	std::cout << "==========\nSubCategories:\n";
	for (const auto& i : repository)
	{
		std::cout << '\t' << i << '\n';
	}
	std::cout << "==========\n";
}