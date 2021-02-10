#include "Currency.h"

Currency::Currency():
	currencyName{ "" },
	currencyCode{ "" },
	currencyActive{ true }
{}

Currency::Currency(std::string currencyNameForAdd):
	currencyName{ currencyNameForAdd },
	currencyCode{ "" },
	currencyActive{ true }
{}

Currency::Currency(std::string currencyNameForAdd, std::string currencyCodeForAdd):
	currencyName{ currencyNameForAdd },
	currencyCode{ currencyCodeForAdd },
	currencyActive{ true }
{}

Currency::Currency(std::string currencyNameForAdd, std::string currencyCodeForAdd, bool currencyActiveForAdd):
	currencyName{ currencyNameForAdd },
	currencyCode{ currencyCodeForAdd },
	currencyActive{ currencyActiveForAdd }
{}

std::string Currency::getCurrencyName() const
{
	return currencyName;
}

std::string Currency::getCurrencyCode() const
{
	return currencyCode;
}

bool Currency::getCurrencyActive() const
{
	return currencyActive;
}

void Currency::setCurrencyName(std::string&& currencyNameForUpdate)
{
	currencyName = std::move(currencyNameForUpdate);
}

bool operator<(const Currency& leftCurrency, const Currency& rightCurrency)
{
	return (leftCurrency.getCurrencyName()) < (rightCurrency.getCurrencyName());
}

std::ostream& operator<<(std::ostream& outputStream, const Currency& currency)
{
	return outputStream << currency.getCurrencyName() << '\t' <<
		currency.getCurrencyCode() << '\t' <<
		currency.getCurrencyActive();
}