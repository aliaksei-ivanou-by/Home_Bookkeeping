#include "CurrencyRepository.h"

CurrencyRepository::CurrencyRepository()
{}

void CurrencyRepository::add(Currency currencyForAdd)
{
	repository.insert(currencyForAdd);
}

void CurrencyRepository::remove(Currency currencyForRemove)
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

CurrencyRepositoryIterator CurrencyRepository::find(Currency&& currencyForFind) const
{
	return repository.find(std::move(currencyForFind));
}