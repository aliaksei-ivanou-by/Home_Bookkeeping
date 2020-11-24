#pragma once

#ifndef TRANSACTIONSTATUSE_H
#define TRANSACTIONSTATUSE_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

enum class TransactionStatusEnum
{
	Cleared,
	Reconciled,
	Void,
	None
};

class TransactionStatus
{
private:
	TransactionStatusEnum transactionStatus;
public:
	TransactionStatus()
		: transactionStatus{ TransactionStatusEnum::None }
	{}
	void setTransactionStatus(TransactionStatusEnum&& transactionStatus)
	{
		this->transactionStatus = transactionStatus;
	}
	TransactionStatusEnum getTransactionStatus() const
	{
		return this->transactionStatus;
	}
};

#endif