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

void default_currencies(FinanceRepository& mainRepository)
{
	mainRepository.addCurrency({ "BYN", "BYN", true });
	mainRepository.addCurrency({ "USD", "USD", false });
	mainRepository.addCurrency({ "EURO", "EURO", false });
}

void default_accounts(FinanceRepository& mainRepository)
{
	mainRepository.addAccount({ "BYN Cash" });
	mainRepository.addAccount({ "BYN Card" });
	mainRepository.addAccount({ "USD Card" });
	mainRepository.addAccount({ "USD Cash" });
}

void default_categories(FinanceRepository& mainRepository)
{
	mainRepository.addCategory({ "Bills" });
	mainRepository.addCategory({ "Financial Expenses" });
	mainRepository.addCategory({ "Housing" });
	mainRepository.addCategory({ "Food & Dining" });
	mainRepository.addCategory({ "Life" });
	mainRepository.addCategory({ "Transportation" });
	mainRepository.addCategory({ "Vehicle" });
	mainRepository.addCategory({ "Shopping" });
}

void default_book_keeping(FinanceRepository& mainRepository)
{
	default_accounts(mainRepository);
	default_categories(mainRepository);
	default_currencies(mainRepository);
}

void print_accounts(FinanceRepository& mainRepository)
{
	std::cout << "ACCOUNTS:\n";
	for (auto i : mainRepository.getAccounts().getAccountRepository())
	{
		std::cout << '\t' << i << '\n';
	}
}

void print_categories(FinanceRepository& mainRepository)
{
	std::cout << "CATEGORIES:\n";
	for (auto i : mainRepository.getCategories().getCategoryRepository())
	{
		std::cout << '\t' << i << '\n';
	}
}

void print_currencies(FinanceRepository& mainRepository)
{
	std::cout << "CURRENCIES:\n";
	for (auto i : mainRepository.getCurrencies().getCurrencyRepository())
	{
		std::cout << '\t' << i << '\n';
	}
}

void print_transactions(FinanceRepository& mainRepository)
{
	std::cout << "TRANSACTIONS:\n";
	for (auto i : mainRepository.getTransactions().getTransactionRepository())
	{
		std::cout << '\t' << i << '\n';
	}
}

#endif