#pragma once

#include "../include/stdafx.h"
#include "../include/1_DataAccess_Additional.h"

using TransactionRepositoryIterator = std::multiset<Transaction>::iterator;

class TransactionRepository
{
private:
	std::multiset<Transaction> repository;
public:
	TransactionRepository();
	void add(Transaction transactionForAdd);
	void remove(Transaction transactionForRemove);
	size_t size() const;
	void clear();
	TransactionRepositoryIterator find(const Transaction& transactionForFind) const;
	TransactionRepositoryIterator begin() const;
	TransactionRepositoryIterator end() const;
};