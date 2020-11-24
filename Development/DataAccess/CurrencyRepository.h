#pragma once

#ifndef CURRENCYREPOSITORY_H
#define CURRENCYREPOSITORY_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

#ifndef CURRENCY_H
#include "../Models/Currency.h"
#endif

class CurrencyRepository
{
private:
	std::set<Currency> currencyRepository;
public:
	CurrencyRepository()
	{}
	void addCurrency(Currency currency)
	{
		currencyRepository.insert(currency);
	}
	void removeCurrency(Currency currency)
	{
		currencyRepository.erase(currency);
	}
	std::set<Currency> getCurrencyRepository() const
	{
		return currencyRepository;
	}
	void setCurrencyRepository(std::set<Currency>&& currencies)
	{
		currencyRepository = currencies;
	}
};

#endif