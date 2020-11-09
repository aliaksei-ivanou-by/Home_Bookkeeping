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
	void add(std::string name)
	{
		repository.insert(name);
	}
	void remove(std::string name)
	{
		repository.erase(name);
	}
};

#endif