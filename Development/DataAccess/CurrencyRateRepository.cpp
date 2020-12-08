#include "CurrencyRateRepository.h"

CurrencyRateRepository::CurrencyRateRepository()
{}

void CurrencyRateRepository::addCurrencyRate(CurrencyRate currencyRateForAdd)
{
	currencyRateRepository.insert(currencyRateForAdd);
}

void CurrencyRateRepository::removeCurrencyRate(CurrencyRate currencyRateForRemove)
{
	currencyRateRepository.erase(currencyRateForRemove);
}

std::set<CurrencyRate> CurrencyRateRepository::getCurrencyRateRepository() const
{
	return currencyRateRepository;
}

void CurrencyRateRepository::setCurrencyRateRepository(std::set<CurrencyRate>&& currenciesRateForAdd)
{
	currencyRateRepository = currenciesRateForAdd;
}