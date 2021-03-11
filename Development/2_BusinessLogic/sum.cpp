#include "FinanceRepository.h"

// Class member function. Calculate sum of today expenses
double FinanceRepository::sumExpensesToday() const
{
	double result = 0;
	for (auto i = beginTransactionRepository(); i != endTransactionRepository(); ++i)
	{
		if ((**i).GetType().GetType() == kEnumType::Expense &&
			(**i).GetTime().GetDay() == Time().GetDay() &&
			(**i).GetTime().GetMonth() == Time().GetMonth() &&
			(**i).GetTime().GetYear() == Time().GetYear())
		{
			result += (**i).GetAmount();
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
		if ((**i).GetType().GetType() == kEnumType::Expense &&
			(**i).GetTime().GetMonth() == Time().GetMonth() &&
			(**i).GetTime().GetYear() == Time().GetYear())
		{
			result += (**i).GetAmount();
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
		if ((**i).GetType().GetType() == kEnumType::Expense)
		{
			result += (**i).GetAmount();
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
		if ((**i).GetType().GetType() == kEnumType::Income &&
			(**i).GetTime().GetDay() == Time().GetDay() &&
			(**i).GetTime().GetMonth() == Time().GetMonth() &&
			(**i).GetTime().GetYear() == Time().GetYear())
		{
			result += (**i).GetAmount();
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
		if ((**i).GetType().GetType() == kEnumType::Income &&
			(**i).GetTime().GetMonth() == Time().GetMonth() &&
			(**i).GetTime().GetYear() == Time().GetYear())
		{
			result += (**i).GetAmount();
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
		if ((**i).GetType().GetType() == kEnumType::Income)
		{
			result += (**i).GetAmount();
		}
	}
	return result;
}