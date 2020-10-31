#ifndef REPTRANSACTIONS_H
#define REPTRANSACTIONS_H

#include "stdafx.h"

class Transactions
{
private:
	std::string Account;
	std::string TransactionType;
	std::string TransactionStatus;
	std::string Description;
	std::string Payee;
	double Amount;
	std::string Currency;
	std::string Category;
	std::string SubCategory;
	std::string Comment;
	std::string Tag;
public:
	void set_tagg(std::string name);
};

#endif