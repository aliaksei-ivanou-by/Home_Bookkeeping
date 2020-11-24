#pragma once

#ifndef TRANSACTIONTYPE_H
#define TRANSACTIONTYPE_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

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
	TransactionType()
		: transactionType{ TransactionTypeEnum::Expence }
	{}
	void setTransactionType(TransactionTypeEnum&& transactionType)
	{
		this->transactionType = transactionType;
	}
	TransactionTypeEnum getTransactionType()
	{
		return this->transactionType;
	}
};

#endif