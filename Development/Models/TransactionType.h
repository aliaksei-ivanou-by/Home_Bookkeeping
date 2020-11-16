#pragma once

#ifndef TRANSACTIONTYPE_H
#define TRANSACTIONTYPE_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class TransactionType
{
public:
	enum class type
	{
		Income,
		Expence,
		Transfer
	};
	type get_transaction_type()
	{
		return this->transaction_type;
	}
	TransactionType() : transaction_type{ TransactionType::type::Expence } {}
private:
	type transaction_type;
};

#endif