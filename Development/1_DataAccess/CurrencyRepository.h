#pragma once
#include "../include/stdafx.h"
#include "../0_Models/Currency.h"

/*
Class CurrencyRepository
Includes repository of currencies.

Constructors:
	Default

Class member functions:
	Add currency to repository
	Add shared pointer to currency to repository
	Remove shared pointer to currency from repository
	Calculate size of repository
	Clear repository
	Find shared pointer to currency in repository
	Find begin iterator of repository
	Find end iterator of repository
*/

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