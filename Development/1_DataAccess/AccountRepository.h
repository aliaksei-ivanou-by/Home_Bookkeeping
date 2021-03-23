#ifndef HOMEBOOKKEEPING_1DATAACCESS_ACCOUNTREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_ACCOUNTREPOSITORY_H_

//  Class AccountRepository
//
//  Constructors:
//    Default
//
//  Class member functions:
//    Add account (default) to repository
//    Add account to repository
//    Add account (shared pointer) to repository
//    Remove account (shared pointer) from repository
//    Get name of account from repository
//    Get amount of account from repository
//    Calculate size of repository
//    Clear repository
//    Find account (shared pointer) in repository
//    Find account with definite name in repository
//    Find account with definite amount in repository
//    Find begin iterator of repository
//    Find end iterator of repository
//
//  Variables:
//    repository

#include <iostream>
#include <set>

#include "home_bookkeeping/0_Models/Account.h"

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
  double GetAmount(AccountRepositoryIterator account) const;
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

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_ACCOUNTREPOSITORY_H_
