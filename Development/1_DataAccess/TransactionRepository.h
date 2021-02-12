#pragma once

#include "../include/stdafx.h"
#include "../include/1_DataAccess_Additional.h"

using TransactionRepositoryIterator = std::set<Transaction>::iterator;

class TransactionRepository
{
private:
	std::set<Transaction> transactionRepository;
public:
	TransactionRepository();
	void addTransaction(Transaction transactionForAdd);
	void removeTransaction(Transaction transactionForRemove);
	size_t sizeTransactionRepository() const;
	void clearTransactionRepository();
	TransactionRepositoryIterator findTransactionRepository(Transaction&& transactionForFind) const;
};