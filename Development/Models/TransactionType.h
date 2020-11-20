#pragma once

#ifndef TRANSACTIONTYPE_H
#define TRANSACTIONTYPE_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

enum class type
{
	Income,
	Expence,
	Transfer
};

class TransactionType
{
private:
	type transaction_type;
public:
	void set_transaction_type(type&& i)
	{
		this->transaction_type = i;
	}
	type get_transaction_type()
	{
		return this->transaction_type;
	}
	TransactionType() : transaction_type{ type::Expence } {}
	friend std::ostream& operator<<(std::ostream& os, const TransactionType& i)
	{
		return os << i;
	}
};


#endif