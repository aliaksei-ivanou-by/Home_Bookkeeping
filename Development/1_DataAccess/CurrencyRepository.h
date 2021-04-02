#ifndef HOMEBOOKKEEPING_1DATAACCESS_CURRENCYREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_CURRENCYREPOSITORY_H_

//  Class CurrencyRepository
//
//  Constructors:
//    Default
//
//  Class member functions:
//    Add currency (default) to repository
//    Add currency to repository
//    Add currency (shared pointer) to repository
//    Remove currency (shared pointer) from repository
//    Get name of currency from repository
//    Get code of currency from repository
//    Get activity of currency from repository
//    Set name of currency from repository
//    Set code of currency from repository
//    Set activity of currency from repository
//    Switch activity of currency from repository
//    Switch on activity of currency from repository
//    Switch off activity of currency from repository
//    Calculate size of repository
//    Clear repository
//    Find currency (shared pointer) in repository
//    Find currency with definite name in repository
//    Find currency with definite code in repository
//    Find begin iterator of repository
//    Find end iterator of repository
//    Make command to create table for repository in database
//    Make command to insert repository to database to table
//    Make command to remove table for repository from database
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
  void Add();
  void Add(Currency currency);
  void Add(std::shared_ptr<Currency> currency);
  void Remove(std::shared_ptr<Currency> currency);
  std::string GetName(CurrencyRepositoryIterator currency) const;
  std::string GetCode(CurrencyRepositoryIterator currency) const;
  bool GetActivity(CurrencyRepositoryIterator currency) const;
  void SetName(CurrencyRepositoryIterator currency, const std::string& name);
  void SetCode(CurrencyRepositoryIterator currency, const std::string& code);
  void SetActivity(CurrencyRepositoryIterator currency, const bool activity);
  void Switch(CurrencyRepositoryIterator currency);
  void SwitchOn(CurrencyRepositoryIterator currency);
  void SwitchOff(CurrencyRepositoryIterator currency);
  size_t Size() const;
  void Clear();
  CurrencyRepositoryIterator Find(std::shared_ptr<Currency> currency) const;
  CurrencyRepositoryIterator FindName(const std::string& category) const;
  CurrencyRepositoryIterator FindCode(const std::string& category) const;
  CurrencyRepositoryIterator Begin() const;
  CurrencyRepositoryIterator End() const;
  std::string MakeCommandToCreateRepositoryInDatabase() const;
  std::string MakeCommandToInsertRepositoryToDatabase(size_t counter, CurrencyRepositoryIterator iterator) const;
  std::string MakeCommandToRemoveRepositoryFromDatabase() const;
private:
  std::set<std::shared_ptr<Currency>> repository_;
};

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_CURRENCYREPOSITORY_H_
