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
	Window_AddTransactionExpense addTransactionExpence("Add Expense");
	addTransactionExpence.wait_for_button();
	std::cout << "menuMainAddTransactionExpense\n";
}

void Window_Main::menuMainAddTransactionIncome()
{
	Window_AddTransactionIncome addTransactionIncome("Add Income");
	addTransactionIncome.wait_for_button();
	std::cout << "menuMainAddTransactionIncome\n";
}

void Window_Main::menuMainAddTransactionTransfer()
{
	Window_AddTransactionTransfer addTransactionTransfer("Add Transfer");
	addTransactionTransfer.wait_for_button();
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

Window_AddTransactionExpense::Window_AddTransactionExpense(const std::string& title, Point xy, int w, int h):
	Window{ xy, w, h, title },
	buttonOK{ Point(x_max() - 250, 350), 100, 20, "OK", cbWindow_AddTransactionExpense_OK },
	buttonCancel{ Point(x_max() - 150, 350), 100, 20, "Cancel", cbWindow_AddTransactionExpense_Cancel },
	button_pushed{ false },
	textAccountForAdd{ Point(x_max() - 280, y_max() - 390), elementSizeWidth, elementSizeHeight, "Account: " },
	textAmountForAdd{ Point(x_max() - 280, y_max() - 360), elementSizeWidth, elementSizeHeight, "Amount: " },
	textDesctiptionForAdd{ Point(x_max() - 280, y_max() - 330), elementSizeWidth, elementSizeHeight, "Description: " },
	textPayeeForAdd{ Point(x_max() - 280, y_max() - 300), elementSizeWidth, elementSizeHeight, "Payee: " },
	textCategoryForAdd{ Point(x_max() - 280, y_max() - 270), elementSizeWidth, elementSizeHeight, "Category: " },
	textCategorySubForAdd{ Point(x_max() - 280, y_max() - 240), elementSizeWidth, elementSizeHeight, "CategorySub: " },
	textCommentForAdd{ Point(x_max() - 280, y_max() - 210), elementSizeWidth, elementSizeHeight, "Comment: " },
	textTagForAdd{ Point(x_max() - 280, y_max() - 180), elementSizeWidth, elementSizeHeight, "Tag: " }
{
	attach(buttonOK);
	attach(buttonCancel);
	attach(textAccountForAdd);
	attach(textAmountForAdd);
	attach(textDesctiptionForAdd);
	attach(textPayeeForAdd);
	attach(textCategoryForAdd);
	attach(textCategorySubForAdd);
	attach(textCommentForAdd);
	attach(textTagForAdd);
}

bool Window_AddTransactionExpense::wait_for_button()
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

void Window_AddTransactionExpense::cbWindow_AddTransactionExpense_OK(Address, Address pw)
{
	reference_to<Window_AddTransactionExpense>(pw).Window_AddTransactionExpense_OK();
}

void Window_AddTransactionExpense::cbWindow_AddTransactionExpense_Cancel(Address, Address pw)
{
	reference_to<Window_AddTransactionExpense>(pw).Window_AddTransactionExpense_Cancel();
}

void Window_AddTransactionExpense::Window_AddTransactionExpense_OK()
try
{
	Account account(std::string(textAccountForAdd.get_string()));
	Category category(std::string(textCategoryForAdd.get_string()));
	CategorySub categorySub(std::string(textCategorySubForAdd.get_string()));
	double amount = std::stod((textAmountForAdd.get_string()));
	Comment comment(std::string(textCommentForAdd.get_string()));
	Description description(std::string(textDesctiptionForAdd.get_string()));
	Payee payee(std::string(textPayeeForAdd.get_string()));
	Tag tag(std::string(textTagForAdd.get_string()));
	TransactionStatus transactionStatus(TransactionStatusEnum::Void);
	TransactionType transactionType(TransactionTypeEnum::Expence);
	Transaction transaction(account, category, categorySub, amount, comment, { "" }, { "" }, description, payee, tag,
		transactionStatus, transactionType);
	std::cout << "REPOSITORY : Operation -> Transaction added\n";
	button_pushed = true;
	std::cout << "SYSTEM : Window -> Add Transaction Expense : Button -> OK\n";
	hide();
}
catch (...)
{
	Time time;
	std::cout << time << " : SYSTEM : Error -> Transaction no added\n";
	std::cout << time << " : SYSTEM : Window -> Add Transaction Expense : Button -> OK\n";
	button_pushed = true;
	hide();
}

void Window_AddTransactionExpense::Window_AddTransactionExpense_Cancel()
{
	button_pushed = true;
	Time time;
	std::cout << time << " : SYSTEM : Window -> Add Transaction Expense : Button -> Cancel\n";
	hide();
}

Window_AddTransactionIncome::Window_AddTransactionIncome(const std::string& title, Point xy, int w, int h) :
	Window{ xy, w, h, title },
	buttonOK{ Point(x_max() - 250, 350), 100, 20, "OK", cbOK },
	buttonCancel{ Point(x_max() - 150, 350), 100, 20, "Cancel", cbCancel },
	button_pushed{ false },
	textAccountForAdd{ Point(x_max() - 280, y_max() - 390), elementSizeWidth, elementSizeHeight, "Account: " },
	textAmountForAdd{ Point(x_max() - 280, y_max() - 360), elementSizeWidth, elementSizeHeight, "Amount: " },
	textDesctiptionForAdd{ Point(x_max() - 280, y_max() - 330), elementSizeWidth, elementSizeHeight, "Description: " },
	textPayeeForAdd{ Point(x_max() - 280, y_max() - 300), elementSizeWidth, elementSizeHeight, "Payee: " },
	textCategoryForAdd{ Point(x_max() - 280, y_max() - 270), elementSizeWidth, elementSizeHeight, "Category: " },
	textCategorySubForAdd{ Point(x_max() - 280, y_max() - 240), elementSizeWidth, elementSizeHeight, "CategorySub: " },
	textCommentForAdd{ Point(x_max() - 280, y_max() - 210), elementSizeWidth, elementSizeHeight, "Comment: " },
	textTagForAdd{ Point(x_max() - 280, y_max() - 180), elementSizeWidth, elementSizeHeight, "Tag: " }
{
	attach(buttonOK);
	attach(buttonCancel);
	attach(textAccountForAdd);
	attach(textAmountForAdd);
	attach(textDesctiptionForAdd);
	attach(textPayeeForAdd);
	attach(textCategoryForAdd);
	attach(textCategorySubForAdd);
	attach(textCommentForAdd);
	attach(textTagForAdd);
}

bool Window_AddTransactionIncome::wait_for_button()
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

void Window_AddTransactionIncome::cbOK(Address, Address pw)
{
	reference_to<Window_AddTransactionIncome>(pw).OK();
}

void Window_AddTransactionIncome::cbCancel(Address, Address pw)
{
	reference_to<Window_AddTransactionIncome>(pw).Cancel();
}

void Window_AddTransactionIncome::OK()
try
{
	Account account(textAccountForAdd.get_string());
	Category category(textCategoryForAdd.get_string());
	CategorySub categorySub(textCategorySubForAdd.get_string());
	double amount(std::stod(textAmountForAdd.get_string()));
	Comment comment(textCommentForAdd.get_string());
	Description description(textDesctiptionForAdd.get_string());
	Payee payee(textPayeeForAdd.get_string());
	Tag tag(textTagForAdd.get_string());
	TransactionStatus transactionStatus(TransactionStatusEnum::Void);
	TransactionType transactionType(TransactionTypeEnum::Income);
	Transaction transaction(account, category, categorySub, amount, comment, { "" }, { "" }, description, payee, tag,
		transactionStatus, transactionType);
	std::cout << "REPOSITORY : Operation -> Transaction added\n";
	button_pushed = true;
	std::cout << "SYSTEM : Window -> Add Transaction Income : Button -> OK\n";
	hide();
}
catch (...)
{
	std::cout << "SYSTEM : ERROR : Input Error\n";
	button_pushed = true;
	hide();
}

void Window_AddTransactionIncome::Cancel()
{
	std::cout << "SYSTEM : Error -> Transaction no added\n";
	std::cout << "SYSTEM : Window -> Add Transaction Income : Button -> Cancel\n";
	button_pushed = true;
	hide();
}

Window_AddTransactionTransfer::Window_AddTransactionTransfer(const std::string& title, Point xy, int w, int h) :
	Window{ xy, w, h, title },
	buttonOK{ Point(x_max() - 250, 350), 100, 20, "OK", cbOK },
	buttonCancel{ Point(x_max() - 150, 350), 100, 20, "Cancel", cbCancel },
	button_pushed{ false },
	textAccountFromForAdd{ Point(x_max() - 280, y_max() - 390), elementSizeWidth, elementSizeHeight, "Account From: " },
	textAccountToForAdd{ Point(x_max() - 280, y_max() - 360), elementSizeWidth, elementSizeHeight, "Account To: " },
	textAmountForAdd{ Point(x_max() - 280, y_max() - 330), elementSizeWidth, elementSizeHeight, "Amount: " },
	textDesctiptionForAdd{ Point(x_max() - 280, y_max() - 300), elementSizeWidth, elementSizeHeight, "Description: " },
	textCategoryForAdd{ Point(x_max() - 280, y_max() - 270), elementSizeWidth, elementSizeHeight, "Category: " },
	textCommentForAdd{ Point(x_max() - 280, y_max() - 240), elementSizeWidth, elementSizeHeight, "Comment: " },
	textTagForAdd{ Point(x_max() - 280, y_max() - 210), elementSizeWidth, elementSizeHeight, "Tag: " }
{
	attach(buttonOK);
	attach(buttonCancel);
	attach(textAccountFromForAdd);
	attach(textAccountToForAdd);
	attach(textAmountForAdd);
	attach(textDesctiptionForAdd);
	attach(textCategoryForAdd);
	attach(textCommentForAdd);
	attach(textTagForAdd);
}

bool Window_AddTransactionTransfer::wait_for_button()
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

void Window_AddTransactionTransfer::cbOK(Address, Address pw)
{
	reference_to<Window_AddTransactionTransfer>(pw).OK();
}

void Window_AddTransactionTransfer::cbCancel(Address, Address pw)
{
	reference_to<Window_AddTransactionTransfer>(pw).Cancel();
}

void Window_AddTransactionTransfer::OK()
try
{
	Account accountFrom(textAccountFromForAdd.get_string());
	Account accountTo(textAccountToForAdd.get_string());
	Category category(textCategoryForAdd.get_string());
	double amount(std::stod(textAmountForAdd.get_string()));
	Comment comment(textCommentForAdd.get_string());
	Description description(textDesctiptionForAdd.get_string());
	Tag tag(textTagForAdd.get_string());
	TransactionStatus transactionStatus(TransactionStatusEnum::Void);
	TransactionType transactionType(TransactionTypeEnum::Income);
	Transaction transaction(accountFrom, category, {}, amount, comment, { "" }, { "" }, description, {}, tag,
		transactionStatus, transactionType);
	std::cout << "REPOSITORY : Add Transaction Transfer: \n" << transaction << '\n';
	button_pushed = true;
	std::cout << "SYSTEM : Window : Window_AddTransactionTransfer_OK\n";
	hide();
}
catch (...)
{
	std::cout << "SYSTEM : ERROR : Input Error\n";
	button_pushed = true;
	hide();
}

void Window_AddTransactionTransfer::Cancel()
{
	std::cout << "SYSTEM : Error -> Transaction no added\n";
	std::cout << "SYSTEM : Window -> Add Transaction Transfer : Button -> Cancel\n";
	button_pushed = true;
	hide();
}
