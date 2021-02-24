#include "TransactionStatus.h"

// Default constructor
TransactionStatus::TransactionStatus():
	transactionStatus{ TransactionStatusEnum::None }
{}

// Constructor with the setting of the status of the transaction status
TransactionStatus::TransactionStatus(const TransactionStatusEnum& transactionStatusToAdd):
	transactionStatus{ transactionStatusToAdd }
{}

// Class member function. Get the status of the transaction status
TransactionStatusEnum TransactionStatus::getTransactionStatus() const
{
	return transactionStatus;
}

// Class member function. Set the status of the transaction status
void TransactionStatus::setTransactionStatus(const TransactionStatusEnum& transactionStatusForUpdate)
{
	transactionStatus = transactionStatusForUpdate;
}

// Class member function. Operator < for sorting transaction statuses
bool operator<(const TransactionStatus& leftTransactionStatus, const TransactionStatus& rightTransactionStatus)
{
	return leftTransactionStatus.getTransactionStatus() < rightTransactionStatus.getTransactionStatus();
}
