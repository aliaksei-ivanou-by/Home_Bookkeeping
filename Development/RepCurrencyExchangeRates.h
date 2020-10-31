#ifndef REPCURRENCYEXCHANGERATES_H
#define REPCURRENCYEXCHANGERATES_H

#include "stdafx.h"

class CurrencyExchangeRates
{
private:
	std::string CurrencyExchangeRate_Name;
public:
	CurrencyExchangeRates();
	CurrencyExchangeRates(std::string name);
	std::string get_name() const;
	void set_name(std::string name);
};

class Rep_CurrencyExchangeRates
{
private:
	CurrencyExchangeRates currencyexchangerates;
	std::set<CurrencyExchangeRates> repository;
public:
	Rep_CurrencyExchangeRates();
	void add(std::string tag);
	void remove(std::string tag);
	void print() const;
};

#endif