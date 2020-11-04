#include "RepDescriptions.h"

Descriptions::Descriptions()
	: Description_Name{ "" }
{}

Descriptions::Descriptions(std::string name)
	: Description_Name{ name }
{}

std::string Descriptions::get_name() const
{
	return this->Description_Name;
}

void Descriptions::set_name(std::string name)
{
	this->Description_Name = name;
}

bool operator<(const Descriptions& lhs, const Descriptions& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

Rep_Descriptions::Rep_Descriptions()
{}

void Rep_Descriptions::add(std::string name)
{
	Descriptions temp(name);
	repository.insert(temp);
}

void Rep_Descriptions::remove(std::string name)
{
	Descriptions temp(name);
	repository.erase(temp);
}

std::ostream& operator<<(std::ostream& os, const Descriptions& i)
{
	return os << i.get_name();
}

void Rep_Descriptions::print() const
{
	std::cout << "==========\nDescriptions:\n";
	for (const auto& i : repository)
	{
		std::cout << '\t' << i << '\n';
	}
	std::cout << "==========\n";
}