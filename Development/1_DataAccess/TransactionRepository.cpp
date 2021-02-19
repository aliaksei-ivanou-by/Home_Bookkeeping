#include "TransactionRepository.h"

TransactionRepository::TransactionRepository()
{}

void TransactionRepository::add(Transaction transactionForAdd)
{
	repository.insert(std::make_shared<Transaction>(transactionForAdd));
}

void TransactionRepository::add(std::shared_ptr<Transaction> transactionForAdd)
{
	repository.insert(transactionForAdd);
}

void TransactionRepository::remove(std::shared_ptr<Transaction> transactionForRemove)
{
	repository.erase(transactionForRemove);
}

size_t TransactionRepository::size() const
{
	return repository.size();
}

void TransactionRepository::clear()
{
	repository.clear();
}

TransactionRepositoryIterator TransactionRepository::find(std::shared_ptr<Transaction> transactionForFind) const
{
	return repository.find(transactionForFind);
}

TransactionRepositoryIterator TransactionRepository::begin() const
{
	return repository.begin();
}

TransactionRepositoryIterator TransactionRepository::end() const
{
	return repository.end();
}