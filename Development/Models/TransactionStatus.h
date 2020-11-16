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
	status get_transaction_status()
	{
		return this->transaction_status;
	}
	TransactionStatus() : transaction_status{ TransactionStatus::status::None } {}
private:
	status transaction_status;
};

#endif