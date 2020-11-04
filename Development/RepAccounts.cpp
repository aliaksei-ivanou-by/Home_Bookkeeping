#include "RepAccounts.h"

Accounts::Accounts()
	: Account_Name{ "" }
{}

Accounts::Accounts(std::string name)
	: Account_Name{ name }
{}

std::string Accounts::get_name() const
{
	return this->Account_Name;
}

void Accounts::set_name(std::string name)
{
	this->Account_Name = name;
}

bool operator<(const Accounts& lhs, const Accounts& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

Rep_Accounts::Rep_Accounts()
{}

void Rep_Accounts::add(std::string name)
{
	Accounts temp(name);
	repository.insert(temp);
}

void Rep_Accounts::remove(std::string name)
{
	Accounts temp(name);
	repository.erase(temp);
}

std::ostream& operator<<(std::ostream& os, const Accounts& i)
{
	return os << i.get_name();
}

void Rep_Accounts::print() const
{
	std::cout << "==========\nAccounts:\n";
	for (const auto& i : repository)
	{
		std::cout << '\t' << i << '\n';
	}
	std::cout << "==========\n";
}