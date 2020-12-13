#include "sumTransactions.h"

double sumTransactionsByTransactionType(const FinanceRepository& mainRepository, TransactionType transactionType)
{
	double result = 0;
	for (auto item : mainRepository.getTransactions().getTransactionRepository())
	{
		if (item.getTransactionType().getTransactionType() == transactionType.getTransactionType())
		{
			result += item.getTransactionAmount();
		}
	}
	return result;
}