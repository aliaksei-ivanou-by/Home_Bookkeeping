#include "HomeBookkeepingLib.h"

Window_Main::Window_Main(Point xy, int w, int h, const std::string& title) :
	Window{ xy, w, h, title },
	menuAddTransaction{ Point(0, 0), buttonSizeWidth / 3, buttonSizeHeight, Menu::horizontal, "figures" },
	menuMain{ Point(0, buttonSizeHeight), buttonSizeWidth, buttonSizeHeight, Menu::vertical, "figures" },
	menuStatistics{ Point(0, 250), buttonSizeWidth - 150, buttonSizeHeight, Menu::vertical, "figures" }, 
	menuStatisticsText{ Point(buttonSizeWidth - 150, 250), buttonSizeWidth - 150, buttonSizeHeight, Menu::vertical, "figures" },
	menuFooter{ Point(0, h - buttonSizeHeight), w / 7, buttonSizeHeight, Menu::horizontal, "figures" },
	button_pushed(false),
	buttonQuit(Point(x_max() - 70, 0), 70, 20, "Quit", cbQuit)
{
	attach(buttonQuit);

	menuAddTransaction.attach(new Button(Point(0, 0), 0, 0, "+ expense", cbMenuMainAddTransactionExpense));
	menuAddTransaction.attach(new Button(Point(0, 0), 0, 0, "+ income", cbMenuMainAddTransactionIncome));
	menuAddTransaction.attach(new Button(Point(0, 0), 0, 0, "+ transfer", cbMenuMainAddTransactionTransfer));
	attach(menuAddTransaction);

	menuMain.attach(new Button(Point(0, 0), 0, 0, "Transactions", cbMenuMainTransactions));
	menuMain.attach(new Button(Point(0, 0), 0, 0, "Accounts", cbMenuMainAccounts));
	menuMain.attach(new Button(Point(0, 0), 0, 0, "Planned", cbMenuMainPlanned));
	menuMain.attach(new Button(Point(0, 0), 0, 0, "Reports", cbMenuMainReports));
	menuMain.attach(new Button(Point(0, 0), 0, 0, "Budget", cbMenuMainBudget));
	menuMain.attach(new Button(Point(0, 0), 0, 0, "Statistics", cbMenuMainStatistics));
	attach(menuMain);

	menuStatistics.attach(new Button(Point(0, 0), 0, 0, "Net Worth", cbMenuStatisticsNetWorth));
	menuStatistics.attach(new Button(Point(0, 0), 0, 0, "Liabilities", cbMenuStatisticsLiabilities));
	menuStatistics.attach(new Button(Point(0, 0), 0, 0, "Expenses Today", cbMenuStatisticsExpensesToday));
	menuStatistics.attach(new Button(Point(0, 0), 0, 0, "Expenses This Week", cbMenuStatisticsExpensesThisWeek));
	menuStatistics.attach(new Button(Point(0, 0), 0, 0, "Expenses This Month", cbMenuStatisticsExpensesThisMonth));
	menuStatistics.attach(new Button(Point(0, 0), 0, 0, "Income This Month", cbMenuStatisticsIncomeThisMonth));
	attach(menuStatistics);

	menuStatisticsText.attach(new Button(Point(0, 0), 0, 0, "Net Worth", cbMenuStatisticsTextNetWorth));
	menuStatisticsText.attach(new Button(Point(0, 0), 0, 0, "Liabilities", cbMenuStatisticsTextLiabilities));
	menuStatisticsText.attach(new Button(Point(0, 0), 0, 0, "Expenses Today", cbMenuStatisticsTextExpensesToday));
	menuStatisticsText.attach(new Button(Point(0, 0), 0, 0, "Expenses This Week", cbMenuStatisticsTextExpensesThisWeek));
	menuStatisticsText.attach(new Button(Point(0, 0), 0, 0, "Expenses This Month", cbMenuStatisticsTextExpensesThisMonth));
	menuStatisticsText.attach(new Button(Point(0, 0), 0, 0, "Income This Month", cbMenuStatisticsTextIncomeThisMonth));
	attach(menuStatisticsText);

	menuFooter.attach(new Button(Point(0, 0), 0, 0, "Add Account", cbMenuFooterAddAccount));
	menuFooter.attach(new Button(Point(0, 0), 0, 0, "Add Account Group", cbMenuFooterAddAccountGroup));
	menuFooter.attach(new Button(Point(0, 0), 0, 0, "Add Budget", cbMenuFooterAddBudget));
	menuFooter.attach(new Button(Point(0, 0), 0, 0, "Import", cbMenuFooterImport));
	menuFooter.attach(new Button(Point(0, 0), 0, 0, "Exporth", cbMenuFooterExport));
	menuFooter.attach(new Button(Point(0, 0), 0, 0, "Settings", cbMenuFooterSettings));
	menuFooter.attach(new Button(Point(0, 0), 0, 0, "Help", cbMenuFooterHelp));
	attach(menuFooter);
}

void Window_Main::menuMainAddTransactionExpense()
{
	std::cout << "menuMainAddTransactionExpense\n";
}

void Window_Main::menuMainAddTransactionIncome()
{
	std::cout << "menuMainAddTransactionIncome\n";
}

void Window_Main::menuMainAddTransactionTransfer()
{
	std::cout << "menuMainAddTransactionTransfer\n";
}

void Window_Main::menuMainTransactions()
{
	std::cout << "menuMainTransactions\n";
}

void Window_Main::menuMainAccounts()
{
	std::cout << "menuMainAccounts\n";
}

void Window_Main::menuMainPlanned()
{
	std::cout << "menuMainPlanned\n";
}

void Window_Main::menuMainReports()
{
	std::cout << "menuMainReports\n";
}

void Window_Main::menuMainBudget()
{
	std::cout << "menuMainBudget\n";
}

void Window_Main::menuMainStatistics()
{
	std::cout << "menuMainStatistics\n";
}

void Window_Main::menuStatisticsNetWorth()
{
	std::cout << "menuStatisticsNetWorth\n";
}

void Window_Main::menuStatisticsLiabilities()
{
	std::cout << "menuStatisticsLiabilities\n";
}

void Window_Main::menuStatisticsExpensesToday()
{
	std::cout << "menuStatisticsExpensesToday\n";
}

void Window_Main::menuStatisticsExpensesThisWeek()
{
	std::cout << "menuStatisticsExpensesThisWeek\n";
}

void Window_Main::menuStatisticsExpensesThisMonth()
{
	std::cout << "menuStatisticsExpensesThisMonth\n";
}

void Window_Main::menuStatisticsIncomeThisMonth()
{
	std::cout << "menuStatisticsIncomeThisMonth\n";
}

void Window_Main::menuStatisticsTextNetWorth()
{
	std::cout << "menuStatisticsTextNetWorth\n";
}

void Window_Main::menuStatisticsTextLiabilities()
{
	std::cout << "menuStatisticsTextLiabilities\n";
}

void Window_Main::menuStatisticsTextExpensesToday()
{
	std::cout << "menuStatisticsTextExpensesToday\n";
}

void Window_Main::menuStatisticsTextExpensesThisWeek()
{
	std::cout << "menuStatisticsTextExpensesThisWeek\n";
}

void Window_Main::menuStatisticsTextExpensesThisMonth()
{
	std::cout << "menuStatisticsTextExpensesThisMonth\n";
}

void Window_Main::menuStatisticsTextIncomeThisMonth()
{
	std::cout << "menuStatisticsTextIncomeThisMonth\n";
}

void Window_Main::menuFooterAddAccount()
{
	Window_AddTransactionExpense addTransactionExpence(Point(100, 100), 400, 400, "Add account");
	addTransactionExpence.wait_for_button();
	std::cout << "New Window - addTransactionExpence\n";
}

void Window_Main::menuFooterAddAccountGroup()
{
	std::cout << "menuFooterAddAccountGroup\n";
}

void Window_Main::menuFooterAddBudget()
{
	std::cout << "menuFooterAddBudget\n";
}

void Window_Main::menuFooterImport()
{
	std::cout << "menuFooterImport\n";
}

void Window_Main::menuFooterExport()
{
	std::cout << "menuFooterExport\n";
}

void Window_Main::menuFooterSettings()
{
	std::cout << "menuFooterSettings\n";
}

void Window_Main::menuFooterHelp()
{
	std::cout << "menuFooterHelp\n";
}

void Window_Main::cbMenuMainAddTransactionExpense(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuMainAddTransactionExpense();
}

void Window_Main::cbMenuMainAddTransactionIncome(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuMainAddTransactionIncome();
}

void Window_Main::cbMenuMainAddTransactionTransfer(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuMainAddTransactionTransfer();
}

void Window_Main::cbMenuMainTransactions(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuMainTransactions();
}

void Window_Main::cbMenuMainAccounts(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuMainAccounts();
}

void Window_Main::cbMenuMainPlanned(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuMainPlanned();
}

void Window_Main::cbMenuMainReports(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuMainReports();
}

void Window_Main::cbMenuMainBudget(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuMainBudget();
}

void Window_Main::cbMenuMainStatistics(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuMainStatistics();
}

void Window_Main::cbMenuStatisticsNetWorth(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuStatisticsNetWorth();
}

void Window_Main::cbMenuStatisticsLiabilities(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuStatisticsLiabilities();
}

void Window_Main::cbMenuStatisticsExpensesToday(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuStatisticsExpensesToday();
}

void Window_Main::cbMenuStatisticsExpensesThisWeek(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuStatisticsExpensesThisWeek();
}

void Window_Main::cbMenuStatisticsExpensesThisMonth(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuStatisticsExpensesThisMonth();
}

void Window_Main::cbMenuStatisticsIncomeThisMonth(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuStatisticsIncomeThisMonth();
}

void Window_Main::cbMenuStatisticsTextNetWorth(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuStatisticsTextNetWorth();
}

void Window_Main::cbMenuStatisticsTextLiabilities(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuStatisticsTextLiabilities();
}

void Window_Main::cbMenuStatisticsTextExpensesToday(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuStatisticsTextExpensesToday();
}

void Window_Main::cbMenuStatisticsTextExpensesThisWeek(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuStatisticsTextExpensesThisWeek();
}

void Window_Main::cbMenuStatisticsTextExpensesThisMonth(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuStatisticsTextExpensesThisMonth();
}

void Window_Main::cbMenuStatisticsTextIncomeThisMonth(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuStatisticsTextIncomeThisMonth();
}

void Window_Main::cbMenuFooterAddAccount(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuFooterAddAccount();
}

void Window_Main::cbMenuFooterAddAccountGroup(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuFooterAddAccountGroup();
}

void Window_Main::cbMenuFooterAddBudget(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuFooterAddBudget();
}

void Window_Main::cbMenuFooterImport(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuFooterImport();
}

void Window_Main::cbMenuFooterExport(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuFooterExport();
}

void Window_Main::cbMenuFooterSettings(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuFooterSettings();
}

void Window_Main::cbMenuFooterHelp(Address, Address pw)
{
	reference_to<Window_Main>(pw).menuFooterHelp();
}

bool Window_Main::wait_for_button()
{
	show();
	button_pushed = false;
#if 1
	while (!button_pushed) Fl::wait();
	Fl::redraw();
#else
	Fl::run();
#endif
	return button_pushed;
}

void Window_Main::cbQuit(Address, Address pw)
{
	reference_to<Window_Main>(pw).quit();
}

void Window_Main::quit()
{
	button_pushed = true;
	std::cout << "quit\n";
	hide();
}

Window_AddTransactionExpense::Window_AddTransactionExpense(Point xy, int w, int h, const std::string& title):
	Window{ xy, w, h, title },
	buttonOK(Point(x_max() - 70, 0), 70, 20, "OK", cbOK),
	buttonCancel(Point(x_max() - 70, 0), 70, 20, "Cancel", cbCancel),

	textAccountForAdd{ Point(0, 0), x_max() - 100, 30, "Account: " },
	textAmountForAdd{ Point(80, 40), x_max() - 100, 30, "Amount: " },
	textDesctiptionForAdd{ Point(80, 40), x_max() - 100, 30, "Description: " },
	textPayeeForAdd{ Point(80, 40), x_max() - 100, 30, "Payee: " },
	textCategoryForAdd{ Point(80, 40), x_max() - 100, 30, "Category: " },
	textTimeForAdd{ Point(80, 40), x_max() - 100, 30, "Time: " },
	textCommentForAdd{ Point(80, 40), x_max() - 100, 30, "Comment: " },
	textTagForAdd{ Point(80, 40), x_max() - 100, 30, "Tag: " }
{
	attach(buttonOK);
	attach(buttonCancel);
	attach(textAccountForAdd);
	attach(textAmountForAdd);
	attach(textDesctiptionForAdd);
	attach(textPayeeForAdd);
	attach(textCategoryForAdd);
	attach(textTimeForAdd);
	attach(textCommentForAdd);
	attach(textTagForAdd);
}

bool Graph_lib::Window_AddTransactionExpense::wait_for_button()
{
	show();
	button_pushed = false;
#if 1
	while (!button_pushed) Fl::wait();
	Fl::redraw();
#else
	Fl::run();
#endif
	return button_pushed;
}

void Window_AddTransactionExpense::cbOK(Address, Address pw)
{
	reference_to<Window_AddTransactionExpense>(pw).OK();
}

void Window_AddTransactionExpense::cbCancel(Address, Address pw)
{
	reference_to<Window_AddTransactionExpense>(pw).Cancel();
}

void Window_AddTransactionExpense::OK()
{
	button_pushed = true;
	std::cout << "quit OK\n";
	hide();
}

void Window_AddTransactionExpense::Cancel()
{
	button_pushed = true;
	std::cout << "quit Cancel\n";
	hide();
}
