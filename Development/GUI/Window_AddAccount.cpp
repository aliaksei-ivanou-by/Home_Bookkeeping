#include "Window_Main.h"
#include "Window_AddAccount.h"

void Window_AddAccount::OK()
try
{
	Account account(textAccountForAdd.get_string());
	ptrFinanceRepository->addAccount(account);
	std::cout << Time() << " : REPOSITORY : Add Account: \n" << account << '\n';
	button_pushed = true;
	std::cout << Time() << " : SYSTEM : Window : Add Account : Button -> OK\n";
	hide();
}
catch (...)
{
	std::cout << Time() << " : SYSTEM : Error -> Account no added\n";
	std::cout << Time() << " : SYSTEM : Window -> Add Account : Button -> OK\n";
	button_pushed = true;
	hide();
}

void Window_AddAccount::Cancel()
{
	button_pushed = true;
	std::cout << Time() << " : SYSTEM : Window -> Add Account : Button -> Cancel\n";
	hide();
}
