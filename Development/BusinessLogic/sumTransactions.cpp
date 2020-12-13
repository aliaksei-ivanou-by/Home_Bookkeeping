#include "sumTransactions.h"

double sumTransactionsByTransactionTypeFullTime(const FinanceRepository& mainRepository, TransactionType transactionType)
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

double sumTransactionsByTransactionTypeToday(const FinanceRepository& mainRepository, TransactionType transactionType, Time time)
{
	double result = 0;
	for (auto item : mainRepository.getTransactions().getTransactionRepository())
	{
		if (item.getTransactionType().getTransactionType() == transactionType.getTransactionType() && 
			item.getTransactionTime().getDay() == Time().getDay() && 
			item.getTransactionTime().getMonth() == Time().getMonth() &&
			item.getTransactionTime().getYear() == Time().getYear())
		{
			result += item.getTransactionAmount();
		}
	}
	return result;
}

double sumTransactionsByTransactionTypeThisMonth(const FinanceRepository& mainRepository, TransactionType transactionType, Time time)
{
	double result = 0;
	for (auto item : mainRepository.getTransactions().getTransactionRepository())
	{
		if (item.getTransactionType().getTransactionType() == transactionType.getTransactionType() &&
			item.getTransactionTime().getMonth() == Time().getMonth() &&
			item.getTransactionTime().getYear() == Time().getYear())
		{
			result += item.getTransactionAmount();
		}
	}
	return result;
}