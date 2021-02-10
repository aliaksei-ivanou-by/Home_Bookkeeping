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

bool operator<(const TransactionStatus& leftTransactionStatus, const TransactionStatus& rightTransactionStatus)
{
	return leftTransactionStatus.getTransactionStatus() < rightTransactionStatus.getTransactionStatus();
}
