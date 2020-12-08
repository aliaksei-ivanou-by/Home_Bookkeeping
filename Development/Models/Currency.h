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
	Currency(std::string currencyNameNew);
	Currency(std::string currencyNameNew, std::string currencyCodeNew);
	Currency(std::string currencyNameNew, std::string currencyCodeNew, bool currencyActiveNew);
	std::string getCurrencyName() const;
	std::string getCurrencyCode() const;
	bool getCurrencyActive() const;
	void setCurrencyName(std::string&& currencyNameNew);
	friend bool operator<(const Currency& leftCurrency, const Currency& rightCurrency);
	friend std::ostream& operator<<(std::ostream& outputStream, const Currency& currency);
};