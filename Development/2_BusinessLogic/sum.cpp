#include "FinanceRepository.h"

double FinanceRepository::sumExpencesToday() const
{
	double result = 0;
	for (auto i = beginTransactionRepository(); i != endTransactionRepository(); ++i)
	{
		if ((*i).getTransactionType().getTransactionType() == TransactionTypeEnum::Expence &&
			(*i).getTransactionTime().getDay() == Time().getDay() &&
			(*i).getTransactionTime().getMonth() == Time().getMonth() &&
			(*i).getTransactionTime().getYear() == Time().getYear())
		{
			result += (*i).getTransactionAmount();
		}
	}
	return result;
}

double FinanceRepository::sumExpencesThisMonth() const
{
	double result = 0;
	for (auto i = beginTransactionRepository(); i != endTransactionRepository(); ++i)
	{
		if ((*i).getTransactionType().getTransactionType() == TransactionTypeEnum::Expence &&
			(*i).getTransactionTime().getMonth() == Time().getMonth() &&
			(*i).getTransactionTime().getYear() == Time().getYear())
		{
			result += (*i).getTransactionAmount();
		}
	}
	return result;
}

double FinanceRepository::sumExpencesAllTime() const
{
	double result = 0;
	for (auto i = beginTransactionRepository(); i != endTransactionRepository(); ++i)
	{
		if ((*i).getTransactionType().getTransactionType() == TransactionTypeEnum::Expence)
		{
			result += (*i).getTransactionAmount();
		}
	}
	return result;
}