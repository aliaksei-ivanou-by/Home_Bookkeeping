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
	void setTransactionType(TransactionTypeEnum&& transactionTypeNew);
	TransactionTypeEnum getTransactionType();
};