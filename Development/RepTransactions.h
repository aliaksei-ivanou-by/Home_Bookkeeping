#ifndef REPTRANSACTIONS_H
#define REPTRANSACTIONS_H

#include "stdafx.h"
#include "BookKeeping.h"

class Rep_Transactions
{
private:
	Rep_Accounts rep_accounts;
	Rep_Currencies rep_currencies;
	Rep_Categories rep_categories;
	std::mutex mtx;
public:
	Rep_Transactions();
	void install_default_categories();
	void install_default_currencies();
	void install_default_accounts();
};

#endif