#include "Window_Main.h"
#include "Window_AddAccount.h"

void Window_AddAccount::OK()
try
{
	Account account(textAccountForAdd.get_string());
	ptrFinanceRepository->addAccount(account);
	std::cout << Time() << " : REPOSITORY : Add Account: \n" << account << '\n';
	button_pushed = true;
	hide();
}
catch (...)
{
	std::cout << Time() << " : SYSTEM : Error -> Account no added\n";
	button_pushed = true;
	hide();
}

void Window_AddAccount::Cancel()
{
	button_pushed = true;
	hide();
}
