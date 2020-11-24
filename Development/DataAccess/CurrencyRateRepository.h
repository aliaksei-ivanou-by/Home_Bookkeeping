#pragma once

#ifndef CURRENCYRATEREPOSITORY_H
#define CURRENCYRATEREPOSITORY_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

#ifndef CURRENCYRATE_H
#include "../Models/CurrencyRate.h"
#endif

class CurrencyRateRepository
{
private:
	std::set<CurrencyRate> currencyRateRepository;
public:
	CurrencyRateRepository()
	{}
	void addCurrencyRate(CurrencyRate currencyRate)
	{
		currencyRateRepository.insert(currencyRate);
	}
	void removeCurrencyRate(CurrencyRate currencyRate)
	{
		currencyRateRepository.erase(currencyRate);
	}
	std::set<CurrencyRate> getCurrencyRateRepository() const
	{
		return currencyRateRepository;
	}
	void setCurrencyRateRepository(std::set<CurrencyRate>&& currenciesRate)
	{
		currencyRateRepository = currenciesRate;
	}
};

#endif