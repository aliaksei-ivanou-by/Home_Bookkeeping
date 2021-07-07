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
//
//  Variables:
//    repository

#include <iostream>
#include <map>

#include "Home_Bookkeeping/0_Models/Payee.h"

using PayeeRepositoryIterator = std::map<std::shared_ptr<Payee>, int>::iterator;
using PayeeRepositoryConstIterator = std::map<std::shared_ptr<Payee>, int>::const_iterator;

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
  PayeeRepositoryConstIterator Find(std::shared_ptr<Payee> payee) const;
  PayeeRepositoryConstIterator Find(std::string name) const;
  PayeeRepositoryConstIterator Begin() const;
  PayeeRepositoryConstIterator End() const;
private:
  void AddPayee(std::shared_ptr<Payee> payee);
  std::map<std::shared_ptr<Payee>, int> repository_;
};

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_PAYEEREPOSITORY_H_
