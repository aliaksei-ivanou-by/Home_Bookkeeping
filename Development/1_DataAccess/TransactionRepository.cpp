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

size_t TransactionRepository::sizeTransactionRepository()
{
	return transactionRepository.size();
}

void TransactionRepository::clearTransactionRepository()
{
	transactionRepository.clear();
}

TransactionRepositoryIterator TransactionRepository::findTransactionRepository(Transaction&& transactionForFind)
{
	return transactionRepository.find(std::move(transactionForFind));
}