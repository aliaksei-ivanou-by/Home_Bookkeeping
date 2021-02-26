#include "FinanceRepository.h"

// Class member function. Calculate sum of today expenses
double FinanceRepository::sumExpencesToday() const
{
	double result = 0;
	for (auto i = beginTransactionRepository(); i != endTransactionRepository(); ++i)
	{
		if ((**i).getTransactionType().getTransactionType() == TransactionTypeEnum::Expence &&
			(**i).getTransactionTime().getDay() == Time().getDay() &&
			(**i).getTransactionTime().getMonth() == Time().getMonth() &&
			(**i).getTransactionTime().getYear() == Time().getYear())
		{
			result += (**i).getTransactionAmount();
		}
	}
	return result;
}

// Class member function. Calculate sum of this month expenses
double FinanceRepository::sumExpencesThisMonth() const
{
	double result = 0;
	for (auto i = beginTransactionRepository(); i != endTransactionRepository(); ++i)
	{
		if ((**i).getTransactionType().getTransactionType() == TransactionTypeEnum::Expence &&
			(**i).getTransactionTime().getMonth() == Time().getMonth() &&
			(**i).getTransactionTime().getYear() == Time().getYear())
		{
			result += (**i).getTransactionAmount();
		}
	}
	return result;
}

// Class member function. Calculate sum of all time expenses
double FinanceRepository::sumExpencesAllTime() const
{
	double result = 0;
	for (auto i = beginTransactionRepository(); i != endTransactionRepository(); ++i)
	{
		if ((**i).getTransactionType().getTransactionType() == TransactionTypeEnum::Expence)
		{
			result += (**i).getTransactionAmount();
		}
	}
	return result;
}

// Class member function. Calculate sum of today incomes
double FinanceRepository::sumIncomesToday() const
{
	double result = 0;
	for (auto i = beginTransactionRepository(); i != endTransactionRepository(); ++i)
	{
		if ((**i).getTransactionType().getTransactionType() == TransactionTypeEnum::Income &&
			(**i).getTransactionTime().getDay() == Time().getDay() &&
			(**i).getTransactionTime().getMonth() == Time().getMonth() &&
			(**i).getTransactionTime().getYear() == Time().getYear())
		{
			result += (**i).getTransactionAmount();
		}
	}
	return result;
}

// Class member function. Calculate sum of this month incomes
double FinanceRepository::sumIncomesThisMonth() const
{
	double result = 0;
	for (auto i = beginTransactionRepository(); i != endTransactionRepository(); ++i)
	{
		if ((**i).getTransactionType().getTransactionType() == TransactionTypeEnum::Income &&
			(**i).getTransactionTime().getMonth() == Time().getMonth() &&
			(**i).getTransactionTime().getYear() == Time().getYear())
		{
			result += (**i).getTransactionAmount();
		}
	}
	return result;
}

// Class member function. Calculate sum of all time incomes
double FinanceRepository::sumIncomesAllTime() const
{
	double result = 0;
	for (auto i = beginTransactionRepository(); i != endTransactionRepository(); ++i)
	{
		if ((**i).getTransactionType().getTransactionType() == TransactionTypeEnum::Income)
		{
			result += (**i).getTransactionAmount();
		}
	}
	return result;
}