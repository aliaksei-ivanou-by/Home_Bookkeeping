#include "FinanceRepository.h"

// Class member function. Set default accounts repository
void FinanceRepository::setDefaultAccounts()
{
	addAccount({ "BYN Cash" });
	addAccount({ "BYN Card" });
	addAccount({ "USD Card" });
	addAccount({ "USD Cash" });
}

// Class member function. Set default categories repository
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

// Class member function. Set default currencies repository
void FinanceRepository::setDefaultCurrencies()
{
	addCurrency({ "BYN", "BYN", true });
	addCurrency({ "USD", "USD", false });
	addCurrency({ "EURO", "EURO", false });
}