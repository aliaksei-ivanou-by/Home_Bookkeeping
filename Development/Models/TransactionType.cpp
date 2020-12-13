#include "TransactionType.h"

TransactionType::TransactionType():
	transactionType{ TransactionTypeEnum::Expence }
{}

TransactionType::TransactionType(TransactionTypeEnum transactionTypeForAdd):
	transactionType{ transactionTypeForAdd }
{}

void TransactionType::setTransactionType(TransactionTypeEnum&& transactionTypeForUpdate)
{
	transactionType = std::move(transactionTypeForUpdate);
}

TransactionTypeEnum TransactionType::getTransactionType() const
{
	return transactionType;
}

bool operator<(const TransactionType& leftTransactionType, const TransactionType& rightTransactionType)
{
	return leftTransactionType.getTransactionType() < rightTransactionType.getTransactionType();
}