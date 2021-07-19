#ifndef HOMEBOOKKEEPING_1DATAACCESS_ACCOUNTREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_ACCOUNTREPOSITORY_H_

#include <iostream>
#include <set>

#include "include/0_Models/Account.h"

using AccountRepositoryIterator = std::set<std::shared_ptr<Account>>::iterator;

class AccountRepository
{
public:
  AccountRepository();
  void Add();
  void Add(Account account);
  void Add(std::shared_ptr<Account> account);
  void Remove(std::shared_ptr<Account> account);
  std::string GetName(AccountRepositoryIterator account) const;
  NUM GetAmount(AccountRepositoryIterator account) const;
  void SetName(AccountRepositoryIterator account, const std::string& name);
  void SetAmount(AccountRepositoryIterator account, const double amount);
  size_t Size() const;
  void Clear();
  AccountRepositoryIterator Find(std::shared_ptr<Account> account) const;
  AccountRepositoryIterator Find(std::string name) const;
  AccountRepositoryIterator Find(double amount) const;
  AccountRepositoryIterator Begin() const;
  AccountRepositoryIterator End() const;
private:
  std::set<std::shared_ptr<Account>> repository_;
};

#endif