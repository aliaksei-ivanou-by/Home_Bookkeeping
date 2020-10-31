#ifndef TRANSACTIONTYPES_H
#define TRANSACTIONTYPES_H

#include "stdafx.h"
#include "RepTransactions.h"

class TransactionTypes
{
public:
	enum class type
	{
		Income,
		Expences,
		Transfer
	};
};

#endif