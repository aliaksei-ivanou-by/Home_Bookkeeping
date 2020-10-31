#ifndef TRANSACTIONSTATUSES_H
#define TRANSACTIONSTATUSES_H

#include "stdafx.h"

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