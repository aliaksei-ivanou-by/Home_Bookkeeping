#pragma once

#include "../include/stdafx.h"
#include "../include/DataAccess.h"

class TransactionRepository
{
private:
	std::multiset<Transaction> transactionRepository;
public:
	TransactionRepository()
	{}
	void addTransaction(Transaction transactionForAdd)
	{
		transactionRepository.insert(transactionForAdd);
	}
	void removeTransaction(Transaction transactionForRemove)
	{
		transactionRepository.erase(transactionForRemove);
	}
	std::multiset<Transaction> getTransactionRepository() const
	{
		return transactionRepository;
	}
	void setTransactionRepository(std::multiset<Transaction>&& transactionsForAdd)
	{
		transactionRepository = transactionsForAdd;
	}
};