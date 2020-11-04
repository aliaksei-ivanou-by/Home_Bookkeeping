#include "RepComments.h"

Comments::Comments()
	: Comment_Name{ "" }
{}

Comments::Comments(std::string name)
	: Comment_Name{ name }
{}

std::string Comments::get_name() const
{
	return this->Comment_Name;
}

void Comments::set_name(std::string name)
{
	this->Comment_Name = name;
}

bool operator<(const Comments& lhs, const Comments& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

Rep_Comments::Rep_Comments()
{}

void Rep_Comments::add(std::string name)
{
	Comments temp(name);
	repository.insert(temp);
}

void Rep_Comments::remove(std::string name)
{
	Comments temp(name);
	repository.erase(temp);
}

std::ostream& operator<<(std::ostream& os, const Comments& i)
{
	return os << i.get_name();
}

void Rep_Comments::print() const
{
	std::cout << "==========\nComments:\n";
	for (const auto& i : repository)
	{
		std::cout << '\t' << i << '\n';
	}
	std::cout << "==========\n";
}