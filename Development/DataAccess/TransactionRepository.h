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

class TransactionRepository
{
private:
	AccountRepository rep_accounts;
	CurrencyRepository rep_currencies;
	CategoryRepository rep_categories;
public:
	TransactionRepository()
	{
		this->install_default_categories();
		this->install_default_currencies();
		this->install_default_accounts();
	}
	AccountRepository get_accounts()
	{
		return this->rep_accounts;
	}
	CurrencyRepository get_currencies()
	{
		return this->rep_currencies;
	}
	CategoryRepository get_categories()
	{
		return this->rep_categories;
	}
	void install_default_categories()
	{
		this->rep_categories.add("Bills");
		this->rep_categories.add("Financial Expenses");
		this->rep_categories.add("Housing");
		this->rep_categories.add("Food & Dining");
		this->rep_categories.add("Life");
		this->rep_categories.add("Transportation");
		this->rep_categories.add("Vehicle");
		this->rep_categories.add("Shopping");
	}
	void install_default_currencies()
	{
		this->rep_currencies.add("BYN");
		this->rep_currencies.add("USD");
	}
	void install_default_accounts()
	{
		this->rep_accounts.add("BYN Cash");
		this->rep_accounts.add("BYN Card");
		this->rep_accounts.add("USD Card");
		this->rep_accounts.add("USD Cash");
	}
};

#endif