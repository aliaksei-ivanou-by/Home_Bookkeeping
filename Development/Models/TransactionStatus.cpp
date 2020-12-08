#include "TransactionStatus.h"

TransactionStatus::TransactionStatus():
	transactionStatus{ TransactionStatusEnum::None }
{}

TransactionStatus::TransactionStatus(TransactionStatusEnum transactionStatusToAdd):
	transactionStatus{ transactionStatusToAdd }
{}

void TransactionStatus::setTransactionStatus(TransactionStatusEnum&& transactionStatusForUpdate)
{
	transactionStatus = std::move(transactionStatusForUpdate);
}

TransactionStatusEnum TransactionStatus::getTransactionStatus() const
{
	return transactionStatus;
}