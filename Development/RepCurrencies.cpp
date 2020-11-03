#include "RepCurrencies.h"

Currencies::Currencies()
	: Currency_Name{ "" },
	Currency_Code{ "" },
	Currency_Active{ true }
{}

Currencies::Currencies(std::string name)
	: Currency_Name{ name },
	Currency_Code{ "" },
	Currency_Active{ true }
{}

Currencies::Currencies(std::string name, std::string code)
	: Currency_Name{ name },
	Currency_Code{ code },
	Currency_Active{ true }
{}

Currencies::Currencies(std::string name, std::string code, bool state)
	: Currency_Name{ name },
	Currency_Code{ code },
	Currency_Active{ state }
{}

std::string Currencies::get_name() const
{
	return this->Currency_Name;
}

std::string Currencies::get_code() const
{
	return this->Currency_Code;
}

bool Currencies::get_active() const
{
	return this->Currency_Active;
}

void Currencies::set_name(std::string name)
{
	this->Currency_Name = name;
}

bool operator<(const Currencies& lhs, const Currencies& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

Rep_Currencies::Rep_Currencies()
{}

void Rep_Currencies::add(std::string name)
{
	Currencies temp(name);
	repository.insert(temp);
}

void Rep_Currencies::remove(std::string name)
{
	Currencies temp(name);
	repository.erase(temp);
}

void Rep_Currencies::print() const
{
	std::cout << "==========\nCurrencies:\n";
	std::cout << "\tName\tCode\tActive\n";
	for (const auto& i : repository)
	{
		std::cout << '\t' << i.get_name() << '\t' << i.get_code() << '\t' << i.get_active() << '\n';
	}
	std::cout << "==========\n";
}