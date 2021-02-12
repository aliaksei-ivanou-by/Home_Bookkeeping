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

size_t CurrencyRepository::sizeCurrencyRepository() const
{
	return currencyRepository.size();
}

void CurrencyRepository::clearCurrencyRepository()
{
	currencyRepository.clear();
}

CurrencyRepositoryIterator CurrencyRepository::findCurrencyRepository(Currency&& currencyForFind) const
{
	return currencyRepository.find(std::move(currencyForFind));
}