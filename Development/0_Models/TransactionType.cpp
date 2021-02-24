#include "TransactionType.h"

// Default constructor
TransactionType::TransactionType():
	transactionType{ TransactionTypeEnum::Expence }
{}

// Constructor with the setting of the type of the transaction type
TransactionType::TransactionType(const TransactionTypeEnum& transactionTypeForAdd):
	transactionType{ transactionTypeForAdd }
{}

// Class member function. Get the type of the transaction type
TransactionTypeEnum TransactionType::getTransactionType() const
{
	return transactionType;
}

// Class member function. Set the type of the transaction type
void TransactionType::setTransactionType(const TransactionTypeEnum& transactionTypeForUpdate)
{
	transactionType = transactionTypeForUpdate;
}

// Class member function. Operator == for comparing transaction types
bool TransactionType::operator==(const TransactionType& other) const
{
	return transactionType == other.transactionType;
}

// Class member function. Operator != for comparing transaction types
bool TransactionType::operator!=(const TransactionType& other) const
{
	return !(*this == other);
}

// Class member function. Operator < for sorting transaction type
bool operator<(const TransactionType& leftTransactionType, const TransactionType& rightTransactionType)
{
	return leftTransactionType.getTransactionType() < rightTransactionType.getTransactionType();
}