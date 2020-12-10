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
	TransactionStatus(TransactionStatusEnum transactionStatusToAdd);
	void setTransactionStatus(TransactionStatusEnum&& transactionStatusForUpdate);
	TransactionStatusEnum getTransactionStatus() const;
	friend bool operator<(const TransactionStatus& leftTransactionStatus, const TransactionStatus& rightTransactionStatus);
};