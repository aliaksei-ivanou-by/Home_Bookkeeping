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