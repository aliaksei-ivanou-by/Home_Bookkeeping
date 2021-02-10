#pragma once

#include "../include/stdafx.h"
#include "../0_Models/CurrencyRate.h"

class CurrencyRateRepository
{
private:
	std::set<CurrencyRate> currencyRateRepository;
public:
	CurrencyRateRepository();
	void addCurrencyRate(CurrencyRate currencyRateForAdd);
	void removeCurrencyRate(CurrencyRate currencyRateForRemove);
	std::set<CurrencyRate> getCurrencyRateRepository() const;
	void setCurrencyRateRepository(std::set<CurrencyRate>&& currenciesRateForAdd);
};
