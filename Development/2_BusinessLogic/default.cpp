#include "home_bookkeeping/2_BusinessLogic/FinanceRepository.h"

//  Class member function
//  Add default accounts to account repository
void FinanceRepository::AddDefaultAccounts()
{
  AddAccount({ "BYN Cash" });
  AddAccount({ "BYN Card" });
  AddAccount({ "USD Card" });
  AddAccount({ "USD Cash" });
  PLOG_INFO << "Add to repository of Accounts default Accounts";
  SaveToDatabaseAccounts();
  PLOG_INFO << "Add to database of Accounts default Accounts";
}

//  Class member function
//  Add default categories to category repository
void FinanceRepository::AddDefaultCategories()
{
  AddCategory({ "Bills" });
  AddCategory({ "Financial Expenses" });
  AddCategory({ "Housing" });
  AddCategory({ "Food & Dining" });
  AddCategory({ "Life" });
  AddCategory({ "Transportation" });
  AddCategory({ "Vehicle" });
  AddCategory({ "Shopping" });
  PLOG_INFO << "Add to repository of Categories default Categories";
  SaveToDatabaseCategories();
  PLOG_INFO << "Add to database of Categories default Categories";
}

//  Class member function
//  Add default currencies to currency repository
void FinanceRepository::AddDefaultCurrencies()
{
  AddCurrency({ "BYN", "BYN", true });
  AddCurrency({ "USD", "USD", false });
  AddCurrency({ "EURO", "EURO", false });
  PLOG_INFO << "Add to repository of Currencies default Currencies";
  SaveToDatabaseCurrencies();
  PLOG_INFO << "Add to database of Currencies default Currencies";
}
