#include "CurrencyRepository.h"

CurrencyRepository::CurrencyRepository()
{}

void CurrencyRepository::add(Currency currencyForAdd)
{
	repository.insert(std::make_shared<Currency>(currencyForAdd));
}

void CurrencyRepository::add(std::shared_ptr<Currency> currencyForAdd)
{
	repository.insert(currencyForAdd);
}

void CurrencyRepository::remove(std::shared_ptr<Currency> currencyForRemove)
{
	repository.erase(currencyForRemove);
}

size_t CurrencyRepository::size() const
{
	return repository.size();
}

void CurrencyRepository::clear()
{
	repository.clear();
}

CurrencyRepositoryIterator CurrencyRepository::find(std::shared_ptr<Currency> currencyForFind) const
{
	return repository.find(currencyForFind);
}

CurrencyRepositoryIterator CurrencyRepository::begin() const
{
	return repository.begin();
}

CurrencyRepositoryIterator CurrencyRepository::end() const
{
	return repository.end();
}