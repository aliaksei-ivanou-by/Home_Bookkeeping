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

void default_currencies(BookKeepingRepository& repository)
{
	repository.add_currency({ "BYN", "BYN", true });
	repository.add_currency({ "USD", "USD", false });
	repository.add_currency({ "EURO", "EURO", false });
}

void default_accounts(BookKeepingRepository& repository)
{
	repository.add_account({ "BYN Cash" });
	repository.add_account({ "BYN Card" });
	repository.add_account({ "USD Card" });
	repository.add_account({ "USD Cash" });
}

void default_categories(BookKeepingRepository& repository)
{
	repository.add_category({ "Bills" });
	repository.add_category({ "Financial Expenses" });
	repository.add_category({ "Housing" });
	repository.add_category({ "Food & Dining" });
	repository.add_category({ "Life" });
	repository.add_category({ "Transportation" });
	repository.add_category({ "Vehicle" });
	repository.add_category({ "Shopping" });
}

void default_book_keeping(BookKeepingRepository& repository)
{
	default_accounts(repository);
	default_categories(repository);
	default_currencies(repository);
}

void print_accounts(BookKeepingRepository& repository)
{
	std::cout << "ACCOUNTS:\n";
	for (auto i : repository.get_accounts().get_account_repository())
	{
		std::cout << '\t' << i << '\n';
	}
}

void print_categories(BookKeepingRepository& repository)
{
	std::cout << "CATEGORIES:\n";
	for (auto i : repository.get_categories().get_category_repository())
	{
		std::cout << '\t' << i << '\n';
	}
}

void print_currencies(BookKeepingRepository& repository)
{
	std::cout << "CURRENCIES:\n";
	for (auto i : repository.get_currencies().get_currency_repository())
	{
		std::cout << '\t' << i << '\n';
	}
}

void print_transactions(BookKeepingRepository& repository)
{
	std::cout << "TRANSACTIONS:\n";
	for (auto i : repository.get_transactions().get_transaction_repository())
	{
		std::cout << '\t' << i << '\n';
	}
}

#endif