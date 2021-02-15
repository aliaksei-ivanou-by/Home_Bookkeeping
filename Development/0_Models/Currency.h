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
	Currency(const std::string& currencyNameForAdd);
	Currency(const std::string& currencyNameForAdd, const std::string& currencyCodeForAdd);
	Currency(const std::string& currencyNameForAdd, const std::string& currencyCodeForAdd, bool currencyActiveForAdd);
	std::string getCurrencyName() const;
	std::string getCurrencyCode() const;
	bool getCurrencyActive() const;
	void setCurrencyName(const std::string& currencyNameForUpdate);
	friend bool operator<(const Currency& leftCurrency, const Currency& rightCurrency);
	friend std::ostream& operator<<(std::ostream& outputStream, const Currency& currency);
};