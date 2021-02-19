#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Currency.h"

using CurrencyRepositoryIterator = std::set<std::shared_ptr<Currency>>::iterator;

class CurrencyRepository
{
private:
	std::set<std::shared_ptr<Currency>> repository;
public:
	CurrencyRepository();
	void add(Currency currencyForAdd);
	void add(std::shared_ptr<Currency> currencyForAdd);
	void remove(std::shared_ptr<Currency> currencyForRemove);
	size_t size() const;
	void clear();
	CurrencyRepositoryIterator find(std::shared_ptr<Currency> currencyForFind) const;
	CurrencyRepositoryIterator begin() const;
	CurrencyRepositoryIterator end() const;
};