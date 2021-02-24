#pragma once
#include "../include/stdafx.h"

/*
Class TransactionStatus
Includes enum class TransactionStatusEnum, status.

Constructors:
	Default (status of the transaction status is none)
	With the setting of the status of the transaction status

Class member functions:
	Get the status of the transaction status
	Set the status of the transaction status
	Operator < for sorting transaction statuses
*/

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
	TransactionStatus(const TransactionStatusEnum& transactionStatusToAdd);

	TransactionStatusEnum getTransactionStatus() const;
	
	void setTransactionStatus(const TransactionStatusEnum& transactionStatusForUpdate);

	friend bool operator<(const TransactionStatus& leftTransactionStatus, const TransactionStatus& rightTransactionStatus);
};