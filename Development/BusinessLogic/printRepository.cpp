#include "printRepository.h"

void printAccounts(const FinanceRepository& mainRepository)
{
	std::cout << "Accounts:\n";
	for (auto i : mainRepository.getAccounts().getAccountRepository())
	{
		std::cout << '\t' << i << '\n';
	}
}

void printCategories(const FinanceRepository& mainRepository)
{
	std::cout << "Categories:\n";
	for (auto i : mainRepository.getCategories().getCategoryRepository())
	{
		std::cout << '\t' << i << '\n';
	}
}

void printCurrencies(const FinanceRepository& mainRepository)
{
	std::cout << "Currencies:\n";
	for (auto i : mainRepository.getCurrencies().getCurrencyRepository())
	{
		std::cout << '\t' << i << '\n';
	}
}

void printTransactions(const FinanceRepository& mainRepository)
{
	std::cout << "Transactions:\n";
	for (auto item : mainRepository.getTransactions().getTransactionRepository())
	{
		std::cout << '\t' << item << '\n';
	}
}