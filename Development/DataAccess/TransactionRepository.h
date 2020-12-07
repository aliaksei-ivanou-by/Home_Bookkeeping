#pragma once

#ifndef TRANSACTIONREPOSITORY_H
#define TRANSACTIONREPOSITORY_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

#ifndef MODELS_H
#include "../include/Models.h"
#endif

#ifndef DATAACCESS1_H
#include "../include/includeDataAccess1.h"
#endif

#ifndef DATAACCESS2_H
#include "../include/includeDataAccess2.h"
#endif

class TransactionRepository
{
private:
	std::multiset<Transaction> transactionRepository;
public:
	TransactionRepository()
	{}
	void addTransaction(Transaction transaction)
	{
		transactionRepository.insert(transaction);
	}
	void removeTransaction(Transaction transaction)
	{
		transactionRepository.erase(transaction);
	}
	std::multiset<Transaction> getTransactionRepository() const
	{
		return transactionRepository;
	}
	void setTransactionRepository(std::multiset<Transaction>&& transactions)
	{
		transactionRepository = transactions;
	}
};

#endif