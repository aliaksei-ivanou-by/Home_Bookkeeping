#include "RepTags.h"

Tags::Tags()
	: Tag_Name{ "" }
{}

Tags::Tags(std::string name)
	: Tag_Name{ name }
{}

std::string Tags::get_name() const
{
	return this->Tag_Name;
}

void Tags::set_name(std::string name)
{
	this->Tag_Name = name;
}

bool operator<(const Tags& lhs, const Tags& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

Rep_Tags::Rep_Tags()
{}

void Rep_Tags::add(std::string name)
{
	Tags temp(name);
	repository.insert(temp);
}

void Rep_Tags::remove(std::string name)
{
	Tags temp(name);
	repository.erase(temp);
}

std::ostream& operator<<(std::ostream& os, const Tags& i)
{
	return os << i.get_name();
}

void Rep_Tags::print() const
{
	std::cout << "==========\nTags:\n";
	for (const auto& i : repository)
	{
		std::cout << '\t' << i << '\n';
	}
	std::cout << "==========\n";
}