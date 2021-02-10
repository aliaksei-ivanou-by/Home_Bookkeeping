#pragma once

#include "../include/stdafx.h"

class Currency
{
private:
	std::string currencyName;
	std::string currencyCode;
	bool currencyActive;
public:
	Currency();
	Currency(std::string currencyNameForAdd);
	Currency(std::string currencyNameForAdd, std::string currencyCodeForAdd);
	Currency(std::string currencyNameForAdd, std::string currencyCodeForAdd, bool currencyActiveForAdd);
	std::string getCurrencyName() const;
	std::string getCurrencyCode() const;
	bool getCurrencyActive() const;
	void setCurrencyName(std::string&& currencyNameForUpdate);
	friend bool operator<(const Currency& leftCurrency, const Currency& rightCurrency);
	friend std::ostream& operator<<(std::ostream& outputStream, const Currency& currency);
};