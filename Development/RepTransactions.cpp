#include "RepTransactions.h"
#include "BookKeeping.h"

Rep_Transactions::Rep_Transactions()
{
	this->install_default_categories();
	this->install_default_currencies();
	this->install_default_accounts();
}

void Rep_Transactions::install_default_categories()
{
	Rep_Categories categories;
	this->rep_categories = categories;
	this->rep_categories.add("Bills");
	this->rep_categories.add("Financial Expenses");
	this->rep_categories.add("Housing");
	this->rep_categories.add("Food & Dining");
	this->rep_categories.add("Life");
	this->rep_categories.add("Transportation");
	this->rep_categories.add("Vehicle");
	this->rep_categories.add("Shopping");
	this->rep_categories.print();
}

void Rep_Transactions::install_default_currencies()
{
	Rep_Currencies currencies;
	this->rep_currencies = currencies;
	this->rep_currencies.add("BYN");
	this->rep_currencies.add("USD");
	this->rep_currencies.print();
}

void Rep_Transactions::install_default_accounts()
{
	Rep_Accounts accounts;
	this->rep_accounts = accounts;
	this->rep_accounts.add("BYN Cash");
	this->rep_accounts.add("BYN Card");
	this->rep_accounts.add("USD Card");
	this->rep_accounts.add("USD Cash");
	this->rep_accounts.print();
}
