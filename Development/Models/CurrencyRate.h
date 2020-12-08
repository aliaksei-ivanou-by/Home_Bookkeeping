#pragma once

#include "../include/stdafx.h"

class CurrencyRate
{
private:
	std::string currencyRateName;
public:
	CurrencyRate();
	CurrencyRate(std::string currencyRateName);
	std::string getCurrencyRateName() const;
	void setCurrencyRateName(std::string&& currencyRateNameNew);
	friend bool operator<(const CurrencyRate& leftCurrencyRate, const CurrencyRate& rightCurrencyRate);
	friend std::ostream& operator<<(std::ostream& outputStream, const CurrencyRate& currencyRate);
};