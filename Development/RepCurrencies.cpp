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
	for (const auto& i : repository)
	{
		std::cout << i.get_name() << '\n';
	}
}