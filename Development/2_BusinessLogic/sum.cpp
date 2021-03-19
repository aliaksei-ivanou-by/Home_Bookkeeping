#include "home_bookkeeping/2_BusinessLogic/FinanceRepository.h"

//  Class member function
//  Calculate sum of today expenses
double FinanceRepository::SumExpensesToday() const
{
  double result = 0;
  for (auto i = BeginTransactionRepository(); i != EndTransactionRepository(); ++i)
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

//  Class member function
//  Calculate sum of this month expenses
double FinanceRepository::SumExpensesThisMonth() const
{
  double result = 0;
  for (auto i = BeginTransactionRepository(); i != EndTransactionRepository(); ++i)
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

//  Class member function
//  Calculate sum of all time expenses
double FinanceRepository::SumExpensesAllTime() const
{
  double result = 0;
  for (auto i = BeginTransactionRepository(); i != EndTransactionRepository(); ++i)
  {
    if ((**i).GetType().GetType() == kEnumType::Expense)
    {
      result += (**i).GetAmount();
    }
  }
  return result;
}

//  Class member function
//  Calculate sum of today incomes
double FinanceRepository::SumIncomesToday() const
{
  double result = 0;
  for (auto i = BeginTransactionRepository(); i != EndTransactionRepository(); ++i)
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

//  Class member function
//  Calculate sum of this month incomes
double FinanceRepository::SumIncomesThisMonth() const
{
  double result = 0;
  for (auto i = BeginTransactionRepository(); i != EndTransactionRepository(); ++i)
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

//  Class member function
//  Calculate sum of all time incomes
double FinanceRepository::SumIncomesAllTime() const
{
  double result = 0;
  for (auto i = BeginTransactionRepository(); i != EndTransactionRepository(); ++i)
  {
    if ((**i).GetType().GetType() == kEnumType::Income)
    {
      result += (**i).GetAmount();
    }
  }
  return result;
}
