#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Currency.h"

using CurrencyRepositoryIterator = std::set<Currency>::iterator;

class CurrencyRepository
{
private:
	std::set<Currency> currencyRepository;
public:
	CurrencyRepository();
	void addCurrency(Currency currencyForAdd);
	void removeCurrency(Currency currencyForRemove);
	size_t sizeCurrencyRepository();
	void clearCurrencyRepository();
	CurrencyRepositoryIterator findCurrencyRepository(Currency&& currencyForFind);
};