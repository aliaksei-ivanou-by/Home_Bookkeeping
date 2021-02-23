#pragma once
#include "../include/stdafx.h"

/*
Class Currency
Includes currency name, currency code, status of the activity of the currency.

Constructors:
	Default (default currency is base currency)
	With the setting of the name of the currency
	With the setting of the name of the currency, code of the currency
	With the setting of the name of the currency, code of the currency, status of the activity of the currency

Class member functions:
	Get the name of the currency
	Get the code of the currency
	Get the status of the activity of the currency
	Set the name of the currency
	Set the code of the currency
	Set the status of the activity of the currency
	Operator < for sorting currencies
	Print currency

Will be updated:
	Base currency
*/

class Currency
{
private:
	std::string currencyName;
	std::string currencyCode;
	bool currencyActive;
public:
	Currency();
	Currency(const std::string& currencyNameForAdd);
	Currency(const std::string& currencyNameForAdd, const std::string& currencyCodeForAdd);
	Currency(const std::string& currencyNameForAdd, const std::string& currencyCodeForAdd, bool currencyActiveForAdd);
	
	std::string getCurrencyName() const;
	std::string getCurrencyCode() const;
	bool getCurrencyActive() const;

	void setCurrencyName(const std::string& currencyNameForUpdate);
	void setCurrencyCode(const std::string& currencyCodeForUpdate);
	void setCurrencyActive(const bool currencyActiveForUpdate);

	friend bool operator<(const Currency& leftCurrency, const Currency& rightCurrency);
	friend std::ostream& operator<<(std::ostream& outputStream, const Currency& currency);
};