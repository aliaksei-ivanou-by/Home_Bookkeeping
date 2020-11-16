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
	std::set<Currency> repository;
public:
	CurrencyRepository() {}
	void add(Currency name)
	{
		repository.insert(name);
	}
	void remove(Currency name)
	{
		repository.erase(name);
	}
	std::set<Currency> get_currency_repository() const
	{
		return repository;
	}
};

#endif