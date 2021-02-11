#include "CurrencyRepository.h"

CurrencyRepository::CurrencyRepository()
{}

void CurrencyRepository::addCurrency(Currency currencyForAdd)
{
	currencyRepository.insert(currencyForAdd);
}

void CurrencyRepository::removeCurrency(Currency currencyForRemove)
{
	currencyRepository.erase(currencyForRemove);
}

size_t CurrencyRepository::sizeCurrencyRepository()
{
	return currencyRepository.size();
}