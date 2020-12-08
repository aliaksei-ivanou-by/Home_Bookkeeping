#pragma once

#include "../include/stdafx.h"

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
	TransactionStatus();
	void setTransactionStatus(TransactionStatusEnum&& transactionStatusNew);
	TransactionStatusEnum getTransactionStatus() const;
};