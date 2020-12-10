#pragma once

#include "../include/stdafx.h"
#include "../include/DataAccess.h"

class TransactionRepository
{
private:
	std::set<Transaction> transactionRepository;
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
	std::set<Transaction> getTransactionRepository() const
	{
		return transactionRepository;
	}
	void setTransactionRepository(std::set<Transaction>&& transactionsForAdd)
	{
		transactionRepository = transactionsForAdd;
	}
};