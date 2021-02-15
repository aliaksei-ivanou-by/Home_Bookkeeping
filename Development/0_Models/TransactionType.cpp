#include "TransactionType.h"

TransactionType::TransactionType():
	transactionType{ TransactionTypeEnum::Expence }
{}

TransactionType::TransactionType(const TransactionTypeEnum& transactionTypeForAdd):
	transactionType{ transactionTypeForAdd }
{}

void TransactionType::setTransactionType(const TransactionTypeEnum& transactionTypeForUpdate)
{
	transactionType = transactionTypeForUpdate;
}

TransactionTypeEnum TransactionType::getTransactionType() const
{
	return transactionType;
}

bool operator<(const TransactionType& leftTransactionType, const TransactionType& rightTransactionType)
{
	return leftTransactionType.getTransactionType() < rightTransactionType.getTransactionType();
}