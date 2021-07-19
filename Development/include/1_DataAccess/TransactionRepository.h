#ifndef HOMEBOOKKEEPING_1DATAACCESS_TRANSACTIONREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_TRANSACTIONREPOSITORY_H_

#include <iostream>
#include <set>

#include "include/0_Models/Transaction.h"

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
private:
  std::multiset<std::shared_ptr<Transaction>> repository_;
};

#endif
