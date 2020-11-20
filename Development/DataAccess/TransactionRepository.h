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
#include "../include/DataAccess1.h"
#endif

#ifndef DATAACCESS2_H
#include "../include/DataAccess2.h"
#endif

class TransactionRepository
{
private:
	std::multiset<Transaction> repository;
public:
	TransactionRepository() {}
	void add(Transaction name)
	{
		repository.insert(name);
	}
	void remove(Transaction name)
	{
		repository.erase(name);
	}
	std::multiset<Transaction> get_transaction_repository() const
	{
		return repository;
	}
};

#endif