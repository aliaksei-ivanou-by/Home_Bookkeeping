#pragma once

#ifndef CURRENCYRATES_H
#define CURRENCYRATES_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class CurrencyRate
{
private:
	std::string currencyRateName;
public:
	CurrencyRate()
		: currencyRateName{ "" }
	{}
	CurrencyRate(std::string currencyRateName)
		: currencyRateName{ currencyRateName }
	{}
	std::string getCurrencyRateName() const
	{
		return this->currencyRateName;
	}
	void setCurrencyRateName(std::string&& currencyRateName)
	{
		this->currencyRateName = currencyRateName;
	}
	friend bool operator<(const CurrencyRate& leftCurrencyRate, const CurrencyRate& rightCurrencyRate)
	{
		return (leftCurrencyRate.getCurrencyRateName()) < (rightCurrencyRate.getCurrencyRateName());
	}
	friend std::ostream& operator<<(std::ostream& outputStream, const CurrencyRate& currencyRate)
	{
		return outputStream << currencyRate.getCurrencyRateName();
	}
};

#endif