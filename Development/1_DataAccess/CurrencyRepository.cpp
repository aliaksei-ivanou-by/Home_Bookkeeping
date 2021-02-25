#include "CurrencyRepository.h"

// Default constructor
CurrencyRepository::CurrencyRepository()
{}

// Class member function. Add currency to repository
void CurrencyRepository::add(Currency currencyForAdd)
{
	repository.insert(std::make_shared<Currency>(currencyForAdd));
}

// Class member function. Add shared pointer to currency to repository
void CurrencyRepository::add(std::shared_ptr<Currency> currencyForAdd)
{
	repository.insert(currencyForAdd);
}

// Class member function. Remove shared pointer to currency from repository
void CurrencyRepository::remove(std::shared_ptr<Currency> currencyForRemove)
{
	repository.erase(currencyForRemove);
}

// Class member function. Calculate size of repository
size_t CurrencyRepository::size() const
{
	return repository.size();
}

// Class member function. Clear repository
void CurrencyRepository::clear()
{
	repository.clear();
}

// Class member function. Find shared pointer to currency in repository
CurrencyRepositoryIterator CurrencyRepository::find(std::shared_ptr<Currency> currencyForFind) const
{
	return repository.find(currencyForFind);
}

// Class member function. Find begin iterator of repository
CurrencyRepositoryIterator CurrencyRepository::begin() const
{
	return repository.begin();
}

// Class member function. Find end iterator of repository
CurrencyRepositoryIterator CurrencyRepository::end() const
{
	return repository.end();
}