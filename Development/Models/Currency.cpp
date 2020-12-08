#include "Currency.h"

Currency::Currency():
	currencyName{ "" },
	currencyCode{ "" },
	currencyActive{ true }
{}

Currency::Currency(std::string currencyNameNew):
	currencyName{ currencyNameNew },
	currencyCode{ "" },
	currencyActive{ true }
{}

Currency::Currency(std::string currencyNameNew, std::string currencyCodeNew):
	currencyName{ currencyNameNew },
	currencyCode{ currencyCodeNew },
	currencyActive{ true }
{}

Currency::Currency(std::string currencyNameNew, std::string currencyCodeNew, bool currencyActiveNew):
	currencyName{ currencyNameNew },
	currencyCode{ currencyCodeNew },
	currencyActive{ currencyActiveNew }
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

void Currency::setCurrencyName(std::string&& currencyNameNew)
{
	currencyName = std::move(currencyNameNew);
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