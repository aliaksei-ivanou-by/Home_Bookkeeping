#pragma once

#include "../include/stdafx.h"

enum class TransactionTypeEnum
{
	Income,
	Expence,
	Transfer
};

class TransactionType
{
private:
	TransactionTypeEnum transactionType;
public:
	TransactionType();
	TransactionType(TransactionTypeEnum transactionTypeForAdd);
	void setTransactionType(TransactionTypeEnum&& transactionTypeForUpdate);
	TransactionTypeEnum getTransactionType() const;
	friend bool operator<(const TransactionType& leftTransactionType, const TransactionType& rightTransactionType);
};