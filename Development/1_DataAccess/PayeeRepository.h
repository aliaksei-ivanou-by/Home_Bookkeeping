#ifndef HOMEBOOKKEEPING_1DATAACCESS_PAYEEREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_PAYEEREPOSITORY_H_

//  Class PayeeRepository
//
//  Constructors:
//    Default
//
//  Class member functions:
//    Add payee (default) to repository
//    Add payee to repository
//    Add payee (shared pointer) to repository
//    Remove payee (shared pointer) from repository
//    Get name of payee from repository
//    Set name of payee from repository
//    Calculate size of repository
//    Clear repository
//    Find payee (shared pointer) in repository
//    Find payee with definite name in repository
//    Find begin iterator of repository
//    Find end iterator of repository
//    Make command to create table for repository in database
//    Make command to insert repository to database to table
//
//  Variables:
//    repository

#include <iostream>
#include <set>

#include "home_bookkeeping/0_Models/Payee.h"

using PayeeRepositoryIterator = std::set<std::shared_ptr<Payee>>::iterator;

class PayeeRepository
{
public:
  PayeeRepository();
  void Add();
  void Add(Payee payee);
  void Add(std::shared_ptr<Payee> payee);
  void Remove(std::shared_ptr<Payee> payee);
  std::string GetName(PayeeRepositoryIterator payee) const;
  void SetName(PayeeRepositoryIterator payee, const std::string& name);
  size_t Size() const;
  void Clear();
  PayeeRepositoryIterator Find(std::shared_ptr<Payee> payee) const;
  PayeeRepositoryIterator Find(std::string name) const;
  PayeeRepositoryIterator Begin() const;
  PayeeRepositoryIterator End() const;
  std::string MakeCommandToCreateRepositoryInDatabase() const;
  std::string MakeCommandToInsertRepositoryToDatabase(size_t counter, PayeeRepositoryIterator iterator) const;
private:
  std::set<std::shared_ptr<Payee>> repository_;
};

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_PAYEEREPOSITORY_H_
