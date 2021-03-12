#ifndef HOMEBOOKKEEPING_1DATAACCESS_CURRENCYREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_CURRENCYREPOSITORY_H_

//  Class CurrencyRepository
//
//  Constructors:
//    Default
//
//  Class member functions:
//    Add currency to repository
//    Add currency (shared pointer) to repository
//    Remove currency (shared pointer) from repository
//    Calculate size of repository
//    Clear repository
//    Find currency (shared pointer) in repository
//    Find begin iterator of repository
//    Find end iterator of repository
//
//  Variables:
//    repository

#include <iostream>
#include <set>

#include "home_bookkeeping/0_Models/Currency.h"

using CurrencyRepositoryIterator = std::set<std::shared_ptr<Currency>>::iterator;

class CurrencyRepository
{
public:
  CurrencyRepository();
  void Add(Currency currency);
  void Add(std::shared_ptr<Currency> currency);
  void Remove(std::shared_ptr<Currency> currency);
  size_t Size() const;
  void Clear();
  CurrencyRepositoryIterator Find(std::shared_ptr<Currency> currency) const;
  CurrencyRepositoryIterator Begin() const;
  CurrencyRepositoryIterator End() const;
private:
  std::set<std::shared_ptr<Currency>> repository_;
};

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_CURRENCYREPOSITORY_H_
