#pragma once

#ifndef TRANSACTIONSFUNCTIONS_H
#define TRANSACTIONSFUNCTIONS_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

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

void default_currencies(TransactionRepository& transaction_repository)
{
	transaction_repository.add_currency({ "BYN", "BYN", true });
	transaction_repository.add_currency({ "USD", "USD", false });
	transaction_repository.add_currency({ "EURO", "EURO", false });
}

void default_accounts(TransactionRepository& transaction_repository)
{
	transaction_repository.add_account({ "BYN Cash" });
	transaction_repository.add_account({ "BYN Card" });
	transaction_repository.add_account({ "USD Card" });
	transaction_repository.add_account({ "USD Cash" });
}

void default_categories(TransactionRepository& transaction_repository)
{
	transaction_repository.add_category({ "Bills" });
	transaction_repository.add_category({ "Financial Expenses" });
	transaction_repository.add_category({ "Housing" });
	transaction_repository.add_category({ "Food & Dining" });
	transaction_repository.add_category({ "Life" });
	transaction_repository.add_category({ "Transportation" });
	transaction_repository.add_category({ "Vehicle" });
	transaction_repository.add_category({ "Shopping" });
}

void default_transaction_repository(TransactionRepository& transaction_repository)
{
	default_accounts(transaction_repository);
	default_currencies(transaction_repository);
	default_categories(transaction_repository);
}

void print_categories(TransactionRepository& transaction_repository)
{
	std::cout << "CATEGORIES:\n";
	for (auto i : transaction_repository.get_categories().get_category_repository())
	{
		std::cout << '\t' << i << '\n';
	}
}

void print_currencies(TransactionRepository& transaction_repository)
{
	std::cout << "CURRENCIES:\n";
	for (auto i : transaction_repository.get_currencies().get_currency_repository())
	{
		std::cout << '\t' << i << '\n';
	}
}

#endif