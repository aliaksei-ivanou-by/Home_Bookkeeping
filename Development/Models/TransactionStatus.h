#pragma once

#ifndef TRANSACTIONSTATUSE_H
#define TRANSACTIONSTATUSE_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif
class TransactionStatus
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