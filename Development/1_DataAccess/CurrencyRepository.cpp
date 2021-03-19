#include "home_bookkeeping/1_DataAccess/CurrencyRepository.h"

//  Constructor
//  Default
CurrencyRepository::CurrencyRepository()
{}

//  Class member function
//  Add currency (default) to repository
void CurrencyRepository::Add()
{
  repository_.insert(std::make_shared<Currency>());
}

//  Class member function
//  Add currency to repository
void CurrencyRepository::Add(Currency currency)
{
  repository_.insert(std::make_shared<Currency>(currency));
}

//  Class member function
//  Add currency (shared pointer) to repository
void CurrencyRepository::Add(std::shared_ptr<Currency> currency)
{
  repository_.insert(currency);
}

//  Class member function
//  Remove currency (shared pointer) from repository
void CurrencyRepository::Remove(std::shared_ptr<Currency> currency)
{
  repository_.erase(currency);
}

//  Class member function
//  Calculate size of repository
size_t CurrencyRepository::Size() const
{
  return repository_.size();
}

//  Class member function
//  Clear repository
void CurrencyRepository::Clear()
{
  repository_.clear();
}

//  Class member function
//  Find currency (shared pointer) in repository
CurrencyRepositoryIterator CurrencyRepository::Find(std::shared_ptr<Currency> currency) const
{
  return repository_.find(currency);
}

//  Class member function
//  Find begin iterator of repository
CurrencyRepositoryIterator CurrencyRepository::Begin() const
{
  return repository_.begin();
}

//  Class member function
//  Find end iterator of repository
CurrencyRepositoryIterator CurrencyRepository::End() const
{
  return repository_.end();
}
