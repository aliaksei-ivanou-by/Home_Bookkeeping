#include "TransactionRepository.h"

TransactionRepository::TransactionRepository()
{}

void TransactionRepository::addTransaction(Transaction transactionForAdd)
{
	transactionRepository.insert(transactionForAdd);
}

void TransactionRepository::removeTransaction(Transaction transactionForRemove)
{
	transactionRepository.erase(transactionForRemove);
}

size_t TransactionRepository::sizeTransactionRepository() const
{
	return transactionRepository.size();
}

void TransactionRepository::clearTransactionRepository()
{
	transactionRepository.clear();
}

TransactionRepositoryIterator TransactionRepository::findTransactionRepository(Transaction&& transactionForFind) const
{
	return transactionRepository.find(std::move(transactionForFind));
}