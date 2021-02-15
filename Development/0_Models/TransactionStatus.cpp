#include "TransactionStatus.h"

TransactionStatus::TransactionStatus():
	transactionStatus{ TransactionStatusEnum::None }
{}

TransactionStatus::TransactionStatus(const TransactionStatusEnum& transactionStatusToAdd):
	transactionStatus{ transactionStatusToAdd }
{}

void TransactionStatus::setTransactionStatus(const TransactionStatusEnum& transactionStatusForUpdate)
{
	transactionStatus = transactionStatusForUpdate;
}

TransactionStatusEnum TransactionStatus::getTransactionStatus() const
{
	return transactionStatus;
}

bool operator<(const TransactionStatus& leftTransactionStatus, const TransactionStatus& rightTransactionStatus)
{
	return leftTransactionStatus.getTransactionStatus() < rightTransactionStatus.getTransactionStatus();
}
