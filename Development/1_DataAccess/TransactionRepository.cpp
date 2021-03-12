#include "home_bookkeeping/1_DataAccess/TransactionRepository.h"

//  Constructor
//  Default
TransactionRepository::TransactionRepository()
{}

//  Class member function
//  Add transaction to repository
void TransactionRepository::Add(Transaction transaction)
{
  repository_.insert(std::make_shared<Transaction>(transaction));
}

//  Class member function
//  Add transaction (shared pointer) to repository
void TransactionRepository::Add(std::shared_ptr<Transaction> transaction)
{
  repository_.insert(transaction);
}

//  Class member function
//  Remove transaction (shared pointer) from repository
void TransactionRepository::Remove(std::shared_ptr<Transaction> transaction)
{
  repository_.erase(transaction);
}

//  Class member function
//  Calculate size of repository
size_t TransactionRepository::Size() const
{
  return repository_.size();
}

//  Class member function
//  Clear repository
void TransactionRepository::Clear()
{
  repository_.clear();
}

//  Class member function
//  Find transaction (shared pointer) in repository
TransactionRepositoryIterator TransactionRepository::Find(std::shared_ptr<Transaction> transaction) const
{
  return repository_.find(transaction);
}

//  Class member function
//  Find begin iterator of repository
TransactionRepositoryIterator TransactionRepository::Begin() const
{
  return repository_.begin();
}

//  Class member function
//  Find end iterator of repository
TransactionRepositoryIterator TransactionRepository::End() const
{
  return repository_.end();
}
