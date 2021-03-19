#include "home_bookkeeping/2_BusinessLogic/FinanceRepository.h"

//  Class member function
//  Set default account repository
void FinanceRepository::SetDefaultAccounts()
{
  AddAccount({ "BYN Cash" });
  AddAccount({ "BYN Card" });
  AddAccount({ "USD Card" });
  AddAccount({ "USD Cash" });
}

//  Class member function
//  Set default category repository
void FinanceRepository::SetDefaultCategories()
{
  AddCategory({ "Bills" });
  AddCategory({ "Financial Expenses" });
  AddCategory({ "Housing" });
  AddCategory({ "Food & Dining" });
  AddCategory({ "Life" });
  AddCategory({ "Transportation" });
  AddCategory({ "Vehicle" });
  AddCategory({ "Shopping" });
}

//  Class member function
//  Set default currency repository
void FinanceRepository::SetDefaultCurrencies()
{
  AddCurrency({ "BYN", "BYN", true });
  AddCurrency({ "USD", "USD", false });
  AddCurrency({ "EURO", "EURO", false });
}
