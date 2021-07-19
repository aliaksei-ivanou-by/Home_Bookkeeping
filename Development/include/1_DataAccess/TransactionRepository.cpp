#include "include/1_DataAccess/TransactionRepository.h"

TransactionRepository::TransactionRepository()
{}

void TransactionRepository::Add(Transaction transaction)
{
  repository_.insert(std::make_shared<Transaction>(transaction));
  PLOG_INFO << "Add transaction to transaction repository";
}

void TransactionRepository::Add(std::shared_ptr<Transaction> transaction)
{
  repository_.insert(transaction);
  PLOG_INFO << "Add transaction to transaction repository";
}

void TransactionRepository::Remove(std::shared_ptr<Transaction> transaction)
{
  repository_.erase(transaction);
  PLOG_INFO << "Remove transaction from transaction repository";
}

size_t TransactionRepository::Size() const
{
  return repository_.size();
}

void TransactionRepository::Clear()
{
  repository_.clear();
  PLOG_INFO << "Clear transaction repository";
}

TransactionRepositoryIterator TransactionRepository::Find(std::shared_ptr<Transaction> transaction) const
{
  return repository_.find(transaction);
}

TransactionRepositoryIterator TransactionRepository::Begin() const
{
  return repository_.begin();
}

TransactionRepositoryIterator TransactionRepository::End() const
{
  return repository_.end();
}
