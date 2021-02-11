#pragma once

#include "../include/stdafx.h"
#include "../include/1_DataAccess_Additional.h"

class TransactionRepository
{
private:
	std::set<Transaction> transactionRepository;
public:
	TransactionRepository()
	{}
	void addTransaction(Transaction transactionForAdd) {
		transactionRepository.insert(transactionForAdd);
	}
	void removeTransaction(Transaction transactionForRemove)
	{
		transactionRepository.erase(transactionForRemove);
	}
};