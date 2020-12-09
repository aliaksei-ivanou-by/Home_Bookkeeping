#include "HomeBookkeepingLib.h"

BookkkeepingMainWindow::BookkkeepingMainWindow(Point xy, int w, int h, const std::string& title) :
	Simple_window{ xy, w, h, title },
	mymenu{ Point(0, 70), 70, 30, Menu::vertical, "figures" }
{
	mymenu.attach(new Button(Point(0, 0), 0, 0, "Transactions", cbTransactions));
	mymenu.attach(new Button(Point(0, 0), 0, 0, "Accounts", cbAccounts));
	mymenu.attach(new Button(Point(0, 0), 0, 0, "Planned", cbPlanned));
	mymenu.attach(new Button(Point(0, 0), 0, 0, "Reports", cbReports));
	mymenu.attach(new Button(Point(0, 0), 0, 0, "Budget", cbBudget));
	mymenu.attach(new Button(Point(0, 0), 0, 0, "Statistics", cbStatistics));
	attach(mymenu);
}

void BookkkeepingMainWindow::transactions()
{
	std::cout << "transactions\n";
}

void BookkkeepingMainWindow::accounts()
{
	std::cout << "accounts\n";
}

void BookkkeepingMainWindow::planned()
{
	std::cout << "planned\n";
}

void BookkkeepingMainWindow::reports()
{
	std::cout << "reports\n";
}

void BookkkeepingMainWindow::budget()
{
	std::cout << "budget\n";
}

void BookkkeepingMainWindow::statistics()
{
	std::cout << "statistics\n";
}

void BookkkeepingMainWindow::cbTransactions(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).transactions();
}

void BookkkeepingMainWindow::cbAccounts(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).accounts();
}

void BookkkeepingMainWindow::cbPlanned(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).planned();
}

void BookkkeepingMainWindow::cbReports(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).reports();
}

void BookkkeepingMainWindow::cbBudget(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).budget();
}

void BookkkeepingMainWindow::cbStatistics(Address, Address pw)
{
	reference_to<BookkkeepingMainWindow>(pw).statistics();
}