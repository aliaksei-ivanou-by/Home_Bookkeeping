#include "Currency.h"

Currency::Currency():
	currencyName{ "" },
	currencyCode{ "" },
	currencyActive{ true }
{}

Currency::Currency(const std::string& currencyNameForAdd):
	currencyName{ currencyNameForAdd },
	currencyCode{ "" },
	currencyActive{ true }
{}

Currency::Currency(const std::string& currencyNameForAdd, const std::string& currencyCodeForAdd):
	currencyName{ currencyNameForAdd },
	currencyCode{ currencyCodeForAdd },
	currencyActive{ true }
{}

Currency::Currency(const std::string& currencyNameForAdd, const std::string& currencyCodeForAdd, bool currencyActiveForAdd):
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

void Currency::setCurrencyName(const std::string& currencyNameForUpdate)
{
	currencyName = currencyNameForUpdate;
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