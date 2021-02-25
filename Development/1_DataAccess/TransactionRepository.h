#pragma once
#include "../include/stdafx.h"
#include "../include/1_DataAccess_Additional.h"

/*
Class TransactionRepository
Includes repository of transactions.
Transactions can be repeated;

Constructors:
	Default

Class member functions:
	Add transaction to repository
	Add shared pointer to transaction to repository
	Remove shared pointer to transaction from repository
	Calculate size of repository
	Clear repository
	Find shared pointer to transaction in repository
	Find begin iterator of repository
	Find end iterator of repository
*/

using TransactionRepositoryIterator = std::multiset<std::shared_ptr<Transaction>>::iterator;

class TransactionRepository
{
private:
	std::multiset<std::shared_ptr<Transaction>> repository;
public:
	TransactionRepository();

	void add(Transaction transactionForAdd);
	void add(std::shared_ptr<Transaction> transactionForAdd);

	void remove(std::shared_ptr<Transaction> transactionForRemove);

	size_t size() const;

	void clear();

	TransactionRepositoryIterator find(std::shared_ptr<Transaction> transactionForFind) const;

	TransactionRepositoryIterator begin() const;
	TransactionRepositoryIterator end() const;
};