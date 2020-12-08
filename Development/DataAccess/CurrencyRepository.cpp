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

std::set<Currency> CurrencyRepository::getCurrencyRepository() const
{
	return currencyRepository;
}

void CurrencyRepository::setCurrencyRepository(std::set<Currency>&& currenciesForAdd)
{
	currencyRepository = currenciesForAdd;
}