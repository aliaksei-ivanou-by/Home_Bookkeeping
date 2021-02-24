#pragma once
#include "../include/stdafx.h"

/*
Class TransactionType
Includes enum class TransactionTypeEnum, type.

Constructors:
	Default (status of the transaction type is expence)
	With the setting of the type of the transaction type

Class member functions:
	Get the type of the transaction type
	Set the type of the transaction type
	Operator == for comparing transaction types
	Operator != for comparing transaction types
	Operator < for sorting transaction type
*/

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

	TransactionTypeEnum getTransactionType() const;

	void setTransactionType(const TransactionTypeEnum& transactionTypeForUpdate);

	bool operator==(const TransactionType& other) const;
	bool operator!=(const TransactionType& other) const;
	friend bool operator<(const TransactionType& leftTransactionType, const TransactionType& rightTransactionType);};