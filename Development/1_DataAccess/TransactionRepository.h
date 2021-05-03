#ifndef HOMEBOOKKEEPING_1DATAACCESS_TRANSACTIONREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_TRANSACTIONREPOSITORY_H_

//  Class TransactionRepository
//
//  Constructors:
//    Default
//
//  Class member functions:
//    Add transaction to repository
//    Add shared pointer to transaction to repository
//    Remove shared pointer to transaction from repository
//    Calculate size of repository
//    Clear repository
//    Find shared pointer to transaction in repository
//    Find begin iterator of repository
//    Find end iterator of repository
//    Make command to insert repository to database to table
//
//  Variables:
//    repository

#include <iostream>
#include <set>

#include "home_bookkeeping/0_Models/Transaction.h"

using TransactionRepositoryIterator = std::multiset<std::shared_ptr<Transaction>>::iterator;

class TransactionRepository
{
public:
  TransactionRepository();
  void Add(Transaction transaction);
  void Add(std::shared_ptr<Transaction> transaction);
  void Remove(std::shared_ptr<Transaction> transaction);
  size_t Size() const;
  void Clear();
  TransactionRepositoryIterator Find(std::shared_ptr<Transaction> transaction) const;
  TransactionRepositoryIterator Begin() const;
  TransactionRepositoryIterator End() const;
  std::string MakeCommandToInsertRepositoryToDatabase(size_t counter, TransactionRepositoryIterator iterator) const;
private:
  std::multiset<std::shared_ptr<Transaction>> repository_;
};

#endif  //  HOMEBOOKKEEPING_1DATAACCESS_TRANSACTIONREPOSITORY_H_
