#include "Currency.h"

// Default constructor
Currency::Currency():
	currencyName{ "" },
	currencyCode{ "" },
	currencyActive{ true }
{}

// Constructor with the setting of the name of the currency
Currency::Currency(const std::string& currencyNameForAdd):
	currencyName{ currencyNameForAdd },
	currencyCode{ "" },
	currencyActive{ true }
{}

// Constructor with the setting of the name of the currency, code of the currency
Currency::Currency(const std::string& currencyNameForAdd, const std::string& currencyCodeForAdd):
	currencyName{ currencyNameForAdd },
	currencyCode{ currencyCodeForAdd },
	currencyActive{ true }
{}

// Constructor with the setting of the name of the currency, code of the currency, status of the activity of the currency
Currency::Currency(const std::string& currencyNameForAdd, const std::string& currencyCodeForAdd, bool currencyActiveForAdd):
	currencyName{ currencyNameForAdd },
	currencyCode{ currencyCodeForAdd },
	currencyActive{ currencyActiveForAdd }
{}

// Class member function. Get the name of the currency
std::string Currency::getCurrencyName() const
{
	return currencyName;
}

// Class member function. Get the code of the currency
std::string Currency::getCurrencyCode() const
{
	return currencyCode;
}

// Class member function. Get the status of the activity of the currency
bool Currency::getCurrencyActive() const
{
	return currencyActive;
}

// Class member function. Set the name of the currency
void Currency::setCurrencyName(const std::string& currencyNameForUpdate)
{
	currencyName = currencyNameForUpdate;
}

// Class member function. Set the code of the currency
void Currency::setCurrencyCode(const std::string& currencyCodeForUpdate)
{
	currencyCode = currencyCodeForUpdate;
}

// Class member function. Set the status of the activity of the currency
void Currency::setCurrencyActive(const bool currencyActiveForUpdate)
{
	currencyActive = currencyActiveForUpdate;
}

// Class member function. Operator < for sorting currencies
bool operator<(const Currency& leftCurrency, const Currency& rightCurrency)
{
	return (leftCurrency.getCurrencyName()) < (rightCurrency.getCurrencyName());
}

// Class member function. Print currency
std::ostream& operator<<(std::ostream& outputStream, const Currency& currency)
{
	return outputStream << currency.getCurrencyName() << '\t' <<
		currency.getCurrencyCode() << '\t' <<
		currency.getCurrencyActive();
}