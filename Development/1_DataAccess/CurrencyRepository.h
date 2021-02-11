#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Currency.h"

class CurrencyRepository
{
private:
	std::set<Currency> currencyRepository;
public:
	CurrencyRepository();
	void addCurrency(Currency currencyForAdd);
	void removeCurrency(Currency currencyForRemove);
	std::set<Currency> getCurrencyRepository() const;
	void setCurrencyRepository(std::set<Currency>&& currenciesForAdd);
};