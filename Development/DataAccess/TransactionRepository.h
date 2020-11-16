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
	std::set<Transaction> repository;
public:
	TransactionRepository() {}
	void add_account(Account name)
	{
		this->account_repository.add(name);
	}
	void add_currency(Currency name)
	{
		this->currency_repository.add(name);
	}
	void add_category(Category name)
	{
		this->category_repository.add(name);
	}
	AccountRepository get_accounts()
	{
		return this->account_repository;
	}
	CurrencyRepository get_currencies()
	{
		return this->currency_repository;
	}
	CategoryRepository get_categories()
	{
		return this->category_repository;
	}
};

#endif