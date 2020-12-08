#include "TransactionStatus.h"

TransactionStatus::TransactionStatus():
	transactionStatus{ TransactionStatusEnum::None }
{}

void TransactionStatus::setTransactionStatus(TransactionStatusEnum&& transactionStatusNew)
{
	transactionStatus = std::move(transactionStatusNew);
}

TransactionStatusEnum TransactionStatus::getTransactionStatus() const
{
	return transactionStatus;
}