#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Currency.h"

using CurrencyRepositoryIterator = std::set<Currency>::iterator;

class CurrencyRepository
{
private:
	std::set<Currency> repository;
public:
	CurrencyRepository();
	void add(Currency currencyForAdd);
	void remove(Currency currencyForRemove);
	size_t size() const;
	void clear();
	CurrencyRepositoryIterator find(Currency&& currencyForFind) const;
};