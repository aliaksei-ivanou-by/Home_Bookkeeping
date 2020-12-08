#include "TransactionType.h"

TransactionType::TransactionType():
	transactionType{ TransactionTypeEnum::Expence }
{}

void TransactionType::setTransactionType(TransactionTypeEnum&& transactionTypeNew)
{
	transactionType = std::move(transactionTypeNew);
}

TransactionTypeEnum TransactionType::getTransactionType()
{
	return transactionType;
}