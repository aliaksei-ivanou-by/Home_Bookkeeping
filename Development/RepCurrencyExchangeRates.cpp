#include "RepCurrencyExchangeRates.h"

CurrencyExchangeRates::CurrencyExchangeRates()
	: CurrencyExchangeRate_Name{ "" }
{}

CurrencyExchangeRates::CurrencyExchangeRates(std::string name)
	: CurrencyExchangeRate_Name{ name }
{}

std::string CurrencyExchangeRates::get_name() const
{
	return this->CurrencyExchangeRate_Name;
}

void CurrencyExchangeRates::set_name(std::string name)
{
	this->CurrencyExchangeRate_Name = name;
}

bool operator<(const CurrencyExchangeRates& lhs, const CurrencyExchangeRates& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

Rep_CurrencyExchangeRates::Rep_CurrencyExchangeRates()
{}

void Rep_CurrencyExchangeRates::add(std::string name)
{
	CurrencyExchangeRates temp(name);
	repository.insert(temp);
}

void Rep_CurrencyExchangeRates::remove(std::string name)
{
	CurrencyExchangeRates temp(name);
	repository.erase(temp);
}

std::ostream& operator<<(std::ostream& os, const CurrencyExchangeRates& i)
{
	return os << i.get_name();
}

void Rep_CurrencyExchangeRates::print() const
{
	std::cout << "==========\nCurrency Exchange Rates:\n";
	for (const auto& i : repository)
	{
		std::cout << '\t' << i << '\n';
	}
	std::cout << "==========\n";
}