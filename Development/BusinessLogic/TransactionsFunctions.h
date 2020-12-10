#pragma once

#include "../include/stdafx.h"
#include "../include/DataAccess.h"

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

void print_accounts(const FinanceRepository& mainRepository)
{
	std::cout << "ACCOUNTS:\n";
	for (auto i : mainRepository.getAccounts().getAccountRepository())
	{
		std::cout << '\t' << i << '\n';
	}
}

void print_categories(const FinanceRepository& mainRepository)
{
	std::cout << "CATEGORIES:\n";
	for (auto i : mainRepository.getCategories().getCategoryRepository())
	{
		std::cout << '\t' << i << '\n';
	}
}

void print_currencies(const FinanceRepository& mainRepository)
{
	std::cout << "CURRENCIES:\n";
	for (auto i : mainRepository.getCurrencies().getCurrencyRepository())
	{
		std::cout << '\t' << i << '\n';
	}
}

void print_transactions(const FinanceRepository& mainRepository)
{
	std::cout << "TRANSACTIONS:\n";
	for (auto i : mainRepository.getTransactions().getTransactionRepository())
	{
		std::cout << '\t' << i << '\n';
	}
}