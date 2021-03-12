#ifndef HOMEBOOKKEEPING_1DATAACCESS_PAYEEREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_PAYEEREPOSITORY_H_

//  Class PayeeRepository
//
//  Constructors:
//    Default
//
//  Class member functions:
//    Add payee to repository
//    Add payee (shared pointer) to repository
//    Remove payee (shared pointer) from repository
//    Calculate size of repository
//    Clear repository
//    Find payee (shared pointer) in repository
//    Find begin iterator of repository
//    Find end iterator of repository
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
	void Add(Payee payee);
	void Add(std::shared_ptr<Payee> payee);
	void Remove(std::shared_ptr<Payee> payee);
	size_t Size() const;
	void Clear();
	PayeeRepositoryIterator Find(std::shared_ptr<Payee> payee) const;
	PayeeRepositoryIterator Begin() const;
	PayeeRepositoryIterator End() const;
private:
  std::set<std::shared_ptr<Payee>> repository_;
};

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_PAYEEREPOSITORY_H_
