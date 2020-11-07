#ifndef TRANSACTIONTYPESSTATUSES_H
#define TRANSACTIONTYPESSTATUSES_H

#include "stdafx.h"

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

class TransactionStatuses
{
public:
	enum class status
	{
		Cleared,
		Reconciled,
		Void,
		None
	};
};

#endif