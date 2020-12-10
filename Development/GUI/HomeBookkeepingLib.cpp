#include "HomeBookkeepingLib.h"

BookkkeepingMainWindow::BookkkeepingMainWindow(Point xy, int w, int h, const std::string& title) :
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

void BookkkeepingMainWindow::menuMainAddTransactionExpense()
{
	std::cout << "menuMainAddTransactionExpense\n";
}

void BookkkeepingMainWindow::menuMainAddTransactionIncome()
{
	std::cout << "menuMainAddTransactionIncome\n";
}

void BookkkeepingMainWindow::menuMainAddTransactionTransfer()
{
	std::cout << "menuMainAddTransactionTransfer\n";
}

void BookkkeepingMainWindow::menuMainTransactions()
{
	std::cout << "menuMainTransactions\n";
}

void BookkkeepingMainWindow::menuMainAccounts()
{
	std::cout << "menuMainAccounts\n";
}

void BookkkeepingMainWindow::menuMainPlanned()
{
	std::cout << "menuMainPlanned\n";
}

void BookkkeepingMainWindow::menuMainReports()
{
	std::cout << "menuMainReports\n";
}

void BookkkeepingMainWindow::menuMainBudget()
{
	std::cout << "menuMainBudget\n";
}

void BookkkeepingMainWindow::menuMainStatistics()
{
	std::cout << "menuMainStatistics\n";
}

void BookkkeepingMainWindow::menuStatisticsNetWorth()
{
	std::cout << "menuStatisticsNetWorth\n";
}

void BookkkeepingMainWindow::menuStatisticsLiabilities()
{
	std::cout << "menuStatisticsLiabilities\n";
}

void BookkkeepingMainWindow::menuStatisticsExpensesToday()
{
	std::cout << "menuStatisticsExpensesToday\n";
}

void BookkkeepingMainWindow::menuStatisticsExpensesThisWeek()
{
	std::cout << "menuStatisticsExpensesThisWeek\n";
}

void BookkkeepingMainWindow::menuStatisticsExpensesThisMonth()
{
	std::cout << "menuStatisticsExpensesThisMonth\n";
}

void BookkkeepingMainWindow::menuStatisticsIncomeThisMonth()
{
	std::cout << "menuStatisticsIncomeThisMonth\n";
}

void BookkkeepingMainWindow::menuStatisticsTextNetWorth()
{
	std::cout << "menuStatisticsTextNetWorth\n";
}

void BookkkeepingMainWindow::menuStatisticsTextLiabilities()
{
	std::cout << "menuStatisticsTextLiabilities\n";
}

void BookkkeepingMainWindow::menuStatisticsTextExpensesToday()
{
	std::cout << "menuStatisticsTextExpensesToday\n";
}

void BookkkeepingMainWindow::menuStatisticsTextExpensesThisWeek()
{
	std::cout << "menuStatisticsTextExpensesThisWeek\n";
}

void BookkkeepingMainWindow::menuStatisticsTextExpensesThisMonth()
{
	std::cout << "menuStatisticsTextExpensesThisMonth\n";
}

void BookkkeepingMainWindow::menuStatisticsTextIncomeThisMonth()
{
	std::cout << "menuStatisticsTextIncomeThisMonth\n";
}

void Graph_lib::BookkkeepingMainWindow::menuFooterAddAccount()
{
	std::cout << "menuFooterAddAccount\n";
}

void Graph_lib::BookkkeepingMainWindow::menuFooterAddAccountGroup()
{
	std::cout << "menuFooterAddAccountGroup\n";
}

void Graph_lib::BookkkeepingMainWindow::menuFooterAddBudget()
{
	std::cout << "menuFooterAddBudget\n";
}

void Graph_lib::BookkkeepingMainWindow::menuFooterImport()
{
	std::cout << "menuFooterImport\n";
}

void Graph_lib::BookkkeepingMainWindow::menuFooterExport()
{
	std::cout << "menuFooterExport\n";
}

void Graph_lib::BookkkeepingMainWindow::menuFooterSettings()
{
	std::cout << "menuFooterSettings\n";
}

void Graph_lib::BookkkeepingMainWindow::menuFooterHelp()
{
	std::cout << "menuFooterHelp\n";
}

void BookkkeepingMainWindow::cbMenuMainAddTransactionExpense(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuMainAddTransactionExpense();
}

void BookkkeepingMainWindow::cbMenuMainAddTransactionIncome(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuMainAddTransactionIncome();
}

void BookkkeepingMainWindow::cbMenuMainAddTransactionTransfer(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuMainAddTransactionTransfer();
}

void BookkkeepingMainWindow::cbMenuMainTransactions(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuMainTransactions();
}

void BookkkeepingMainWindow::cbMenuMainAccounts(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuMainAccounts();
}

void BookkkeepingMainWindow::cbMenuMainPlanned(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuMainPlanned();
}

void BookkkeepingMainWindow::cbMenuMainReports(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuMainReports();
}

void BookkkeepingMainWindow::cbMenuMainBudget(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuMainBudget();
}

void BookkkeepingMainWindow::cbMenuMainStatistics(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuMainStatistics();
}

void BookkkeepingMainWindow::cbMenuStatisticsNetWorth(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuStatisticsNetWorth();
}

void BookkkeepingMainWindow::cbMenuStatisticsLiabilities(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuStatisticsLiabilities();
}

void BookkkeepingMainWindow::cbMenuStatisticsExpensesToday(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuStatisticsExpensesToday();
}

void BookkkeepingMainWindow::cbMenuStatisticsExpensesThisWeek(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuStatisticsExpensesThisWeek();
}

void BookkkeepingMainWindow::cbMenuStatisticsExpensesThisMonth(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuStatisticsExpensesThisMonth();
}

void BookkkeepingMainWindow::cbMenuStatisticsIncomeThisMonth(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuStatisticsIncomeThisMonth();
}

void BookkkeepingMainWindow::cbMenuStatisticsTextNetWorth(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuStatisticsTextNetWorth();
}

void BookkkeepingMainWindow::cbMenuStatisticsTextLiabilities(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuStatisticsTextLiabilities();
}

void BookkkeepingMainWindow::cbMenuStatisticsTextExpensesToday(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuStatisticsTextExpensesToday();
}

void BookkkeepingMainWindow::cbMenuStatisticsTextExpensesThisWeek(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuStatisticsTextExpensesThisWeek();
}

void BookkkeepingMainWindow::cbMenuStatisticsTextExpensesThisMonth(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuStatisticsTextExpensesThisMonth();
}

void BookkkeepingMainWindow::cbMenuStatisticsTextIncomeThisMonth(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuStatisticsTextIncomeThisMonth();
}

void Graph_lib::BookkkeepingMainWindow::cbMenuFooterAddAccount(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuFooterAddAccount();
}

void Graph_lib::BookkkeepingMainWindow::cbMenuFooterAddAccountGroup(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuFooterAddAccountGroup();
}

void Graph_lib::BookkkeepingMainWindow::cbMenuFooterAddBudget(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuFooterAddBudget();
}

void Graph_lib::BookkkeepingMainWindow::cbMenuFooterImport(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuFooterImport();
}

void Graph_lib::BookkkeepingMainWindow::cbMenuFooterExport(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuFooterExport();
}

void Graph_lib::BookkkeepingMainWindow::cbMenuFooterSettings(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuFooterSettings();
}

void Graph_lib::BookkkeepingMainWindow::cbMenuFooterHelp(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).menuFooterHelp();
}

bool BookkkeepingMainWindow::wait_for_button()
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

void BookkkeepingMainWindow::cbQuit(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).quit();
}

void BookkkeepingMainWindow::quit()
{
	button_pushed = true;
	std::cout << "quit\n";
	hide();
}