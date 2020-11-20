#pragma once

#ifndef TRANSACTIONSTATUSE_H
#define TRANSACTIONSTATUSE_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

enum class status
{
	Cleared,
	Reconciled,
	Void,
	None
};

class TransactionStatus
{
private:
	status transaction_status;
public:
	void set_transaction_status(status&& i)
	{
		this->transaction_status = i;
	}
	status get_transaction_status() const
	{
		return this->transaction_status;
	}
	TransactionStatus() : transaction_status{ status::None } {}
};

#endif