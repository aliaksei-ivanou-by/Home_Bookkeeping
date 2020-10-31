#include "RepPayees.h"

Payees::Payees()
	: Payee_Name{ "" }
{}

Payees::Payees(std::string name)
	: Payee_Name{ name }
{}

std::string Payees::get_name() const
{
	return this->Payee_Name;
}

void Payees::set_name(std::string name)
{
	this->Payee_Name = name;
}

bool operator<(const Payees& lhs, const Payees& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

Rep_Payees::Rep_Payees()
{}

void Rep_Payees::add(std::string name)
{
	Payees temp(name);
	repository.insert(temp);
}

void Rep_Payees::remove(std::string name)
{
	Payees temp(name);
	repository.erase(temp);
}

void Rep_Payees::print() const
{
	for (const auto& i : repository)
	{
		std::cout << i.get_name() << '\n';
	}
}