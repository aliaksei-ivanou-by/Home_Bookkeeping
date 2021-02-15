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
	TransactionType(const TransactionTypeEnum& transactionTypeForAdd);
	void setTransactionType(const TransactionTypeEnum& transactionTypeForUpdate);
	TransactionTypeEnum getTransactionType() const;
	friend bool operator<(const TransactionType& leftTransactionType, const TransactionType& rightTransactionType);
};