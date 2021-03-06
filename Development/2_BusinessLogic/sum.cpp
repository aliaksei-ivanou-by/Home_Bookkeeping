#include "FinanceRepository.h"

// Class member function. Calculate sum of today expenses
double FinanceRepository::sumExpensesToday() const
{
	double result = 0;
	for (auto i = beginTransactionRepository(); i != endTransactionRepository(); ++i)
	{
		if ((**i).getTransactionType().GetType() == kEnumTransactionType::Expense &&
			(**i).getTransactionTime().GetDay() == Time().GetDay() &&
			(**i).getTransactionTime().GetMonth() == Time().GetMonth() &&
			(**i).getTransactionTime().GetYear() == Time().GetYear())
		{
			result += (**i).getTransactionAmount();
		}
	}
	return result;
}

// Class member function. Calculate sum of this month expenses
double FinanceRepository::sumExpensesThisMonth() const
{
	double result = 0;
	for (auto i = beginTransactionRepository(); i != endTransactionRepository(); ++i)
	{
		if ((**i).getTransactionType().GetType() == kEnumTransactionType::Expense &&
			(**i).getTransactionTime().GetMonth() == Time().GetMonth() &&
			(**i).getTransactionTime().GetYear() == Time().GetYear())
		{
			result += (**i).getTransactionAmount();
		}
	}
	return result;
}

// Class member function. Calculate sum of all time expenses
double FinanceRepository::sumExpensesAllTime() const
{
	double result = 0;
	for (auto i = beginTransactionRepository(); i != endTransactionRepository(); ++i)
	{
		if ((**i).getTransactionType().GetType() == kEnumTransactionType::Expense)
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
		if ((**i).getTransactionType().GetType() == kEnumTransactionType::Income &&
			(**i).getTransactionTime().GetDay() == Time().GetDay() &&
			(**i).getTransactionTime().GetMonth() == Time().GetMonth() &&
			(**i).getTransactionTime().GetYear() == Time().GetYear())
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
		if ((**i).getTransactionType().GetType() == kEnumTransactionType::Income &&
			(**i).getTransactionTime().GetMonth() == Time().GetMonth() &&
			(**i).getTransactionTime().GetYear() == Time().GetYear())
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
		if ((**i).getTransactionType().GetType() == kEnumTransactionType::Income)
		{
			result += (**i).getTransactionAmount();
		}
	}
	return result;
}