#ifndef HOMEBOOKKEEPING_1DATAACCESS_CURRENCYREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_CURRENCYREPOSITORY_H_

#include <iostream>
#include <set>

#include "include/0_Models/Currency.h"

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
private:
  std::set<std::shared_ptr<Currency>> repository_;
};

#endif
