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
	std::set<CurrencyRate> repository;
public:
	CurrencyRateRepository() {}
	void add(CurrencyRate name)
	{
		repository.insert(name);
	}
	void remove(CurrencyRate name)
	{
		repository.erase(name);
	}
};

#endif