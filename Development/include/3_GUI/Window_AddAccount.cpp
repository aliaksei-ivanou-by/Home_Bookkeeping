#include "include/3_GUI/Window_AddAccount.h"

void Window_AddAccount::OK()
try
{
  Account account(textAccountForAdd.get_string());
  ptrFinanceRepository->AddAccount(std::move(account));
  button_pushed = true;
  hide();
}
catch (...)
{
  PLOG_ERROR << "Account no added";
  button_pushed = true;
  hide();
}

void Window_AddAccount::Cancel()
{
  button_pushed = true;
  hide();
}
