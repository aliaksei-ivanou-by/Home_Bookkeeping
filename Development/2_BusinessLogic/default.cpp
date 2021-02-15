#include "FinanceRepository.h"

void FinanceRepository::setDefaultCategories()
{
	addCategory({ "Bills" });
	addCategory({ "Financial Expenses" });
	addCategory({ "Housing" });
	addCategory({ "Food & Dining" });
	addCategory({ "Life" });
	addCategory({ "Transportation" });
	addCategory({ "Vehicle" });
	addCategory({ "Shopping" });
}

void FinanceRepository::setDefaultAccounts()
{
	addAccount({ "BYN Cash" });
	addAccount({ "BYN Card" });
	addAccount({ "USD Card" });
	addAccount({ "USD Cash" });
}

void FinanceRepository::setDefaultCurrencies()
{
	addCurrency({ "BYN", "BYN", true });
	addCurrency({ "USD", "USD", false });
	addCurrency({ "EURO", "EURO", false });
}