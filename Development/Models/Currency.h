#pragma once

#ifndef CURRENCY_H
#define CURRENCY_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class Currency
{
private:
	std::string currencyName;
	std::string currencyCode;
	bool currencyActive;
public:
	Currency()
		: currencyName{ "" },
		currencyCode{ "" },
		currencyActive{ true }
	{}
	Currency(std::string currencyName)
		: currencyName{ currencyName },
		currencyCode{ "" },
		currencyActive{ true }
	{}
	Currency(std::string currencyName, std::string currencyCode)
		: currencyName{ currencyName },
		currencyCode{ currencyCode },
		currencyActive{ true }
	{}
	Currency(std::string currencyName, std::string currencyCode, bool currencyActive)
		: currencyName{ currencyName },
		currencyCode{ currencyCode },
		currencyActive{ currencyActive }
	{}
	std::string getCurrencyName() const
	{
		return this->currencyName;
	}
	std::string getCurrencyCode() const
	{
		return this->currencyCode;
	}
	bool getCurrencyActive() const
	{
		return this->currencyActive;
	}
	void setCurrencyName(std::string&& currencyName)
	{
		this->currencyName = currencyName;
	}
	friend bool operator<(const Currency& leftCurrency, const Currency& rightCurrency)
	{
		return (leftCurrency.getCurrencyName()) < (rightCurrency.getCurrencyName());
	}
	friend std::ostream& operator<<(std::ostream& outputStream, const Currency& currency)
	{
		return outputStream << currency.getCurrencyName() << '\t' <<
								currency.getCurrencyCode() << '\t' <<
								currency.getCurrencyActive();
	}
};

#endif