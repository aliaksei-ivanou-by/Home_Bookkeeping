#include "home_bookkeeping/3_GUI/Window_Main.h"

Window_Main::Window_Main(
  Point xy,
  int w,
  int h,
  const std::string& title,
  std::shared_ptr<FinanceRepository> ptrFinanceRepositoryForAdd):
  Window{ xy, w, h, title },
  menuAddTransaction{ Point(0, 0), buttonSizeWidth / 3, buttonSizeHeight, Menu::horizontal, "figures" },
  menuMain{ Point(0, buttonSizeHeight), buttonSizeWidth, buttonSizeHeight, Menu::vertical, "figures" },
  menuStatistics{ Point(0, 250), buttonSizeWidth - 150, buttonSizeHeight, Menu::vertical, "figures" },
  menuStatisticsText{ Point(buttonSizeWidth - 150, 250), buttonSizeWidth - 150, buttonSizeHeight, Menu::vertical, "figures" },
  menuFooter{ Point(0, h - buttonSizeHeight), w / 7, buttonSizeHeight, Menu::horizontal, "figures" },
  button_pushed(false),
  buttonQuit(Point(x_max() - 70, 0), 70, 20, "Quit", cbQuit),
  ptrFinanceRepository{ ptrFinanceRepositoryForAdd }
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
  menuStatistics.attach(new Button(Point(0, 0), 0, 0, "Expenses This Month", cbMenuStatisticsExpensesThisMonth));
  menuStatistics.attach(new Button(Point(0, 0), 0, 0, "Income This Month", cbMenuStatisticsIncomeThisMonth));
  attach(menuStatistics);

  menuStatisticsText.attach(new Button(Point(0, 0), 0, 0, "Net Worth", cbMenuStatisticsTextNetWorth));
  menuStatisticsText.attach(new Button(Point(0, 0), 0, 0, "Liabilities", cbMenuStatisticsTextLiabilities));
  menuStatisticsText.attach(new Button(Point(0, 0), 0, 0, "Expenses Today", cbMenuStatisticsTextExpensesToday));
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

  Window_Main::menuStatisticsNetWorth();
  Window_Main::menuStatisticsLiabilities();
  Window_Main::menuStatisticsExpensesToday();
  Window_Main::menuStatisticsExpensesThisMonth();
  Window_Main::menuStatisticsIncomeThisMonth();
}

void Window_Main::menuMainAddTransactionExpense()
{
  Window_AddTransactionExpense addTransactionExpense("Add Expense", ptrFinanceRepository);
  addTransactionExpense.wait_for_button();
  Window_Main::menuStatisticsNetWorth();
  Window_Main::menuStatisticsLiabilities();
  Window_Main::menuStatisticsExpensesToday();
  Window_Main::menuStatisticsExpensesThisMonth();
  Window_Main::menuStatisticsIncomeThisMonth();
}

void Window_Main::menuMainAddTransactionIncome()
{
  Window_AddTransactionIncome addTransactionIncome("Add Income", ptrFinanceRepository);
  addTransactionIncome.wait_for_button();
  Window_Main::menuStatisticsNetWorth();
  Window_Main::menuStatisticsLiabilities();
  Window_Main::menuStatisticsExpensesToday();
  Window_Main::menuStatisticsExpensesThisMonth();
  Window_Main::menuStatisticsIncomeThisMonth();
}

void Window_Main::menuMainAddTransactionTransfer()
{
  Window_AddTransactionTransfer addTransactionTransfer("Add Transfer", ptrFinanceRepository);
  addTransactionTransfer.wait_for_button();
  Window_Main::menuStatisticsNetWorth();
  Window_Main::menuStatisticsLiabilities();
  Window_Main::menuStatisticsExpensesToday();
  Window_Main::menuStatisticsExpensesThisMonth();
  Window_Main::menuStatisticsIncomeThisMonth();
}

void Window_Main::menuMainTransactions()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Transactions\n";
}

void Window_Main::menuMainAccounts()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Accounts\n";
}

void Window_Main::menuMainPlanned()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Planned\n";
}

void Window_Main::menuMainReports()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Reports\n";
}

void Window_Main::menuMainBudget()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Budget\n";
}

void Window_Main::menuMainStatistics()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Statistics\n";
}

void Window_Main::menuStatisticsNetWorth()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Statistics Net Worth\n";
}

void Window_Main::menuStatisticsLiabilities()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Statistics Liablilities\n";
}

void Window_Main::menuStatisticsExpensesToday()
{
  menuStatisticsText.selection[2].hide();
  double sum = ptrFinanceRepository->SumExpensesToday();
  std::ostringstream sumStream;
  sumStream << std::fixed << std::setprecision(2) << sum;
  std::string sumString = sumStream.str();
  menuStatisticsText.selection[2].label = sumString;
  menuStatisticsText.selection[2].show();
}

void Window_Main::menuStatisticsExpensesThisMonth()
{
  menuStatisticsText.selection[3].hide();
  double sum = ptrFinanceRepository->SumExpensesThisMonth();
  std::ostringstream sumStream;
  sumStream << std::fixed << std::setprecision(2) << sum;
  std::string sumString = sumStream.str();
  menuStatisticsText.selection[3].label = sumString;
  menuStatisticsText.selection[3].show();
}

void Window_Main::menuStatisticsIncomeThisMonth()
{
  menuStatisticsText.selection[4].hide();
  double sum = ptrFinanceRepository->SumIncomesThisMonth();
  std::ostringstream sumStream;
  sumStream << std::fixed << std::setprecision(2) << sum;
  std::string sumString = sumStream.str();
  menuStatisticsText.selection[4].label = sumString;
  menuStatisticsText.selection[4].show();
}

void Window_Main::menuStatisticsTextNetWorth()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Statistics Text Net Worth\n";
}

void Window_Main::menuStatisticsTextLiabilities()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Statistics Text Liabilities\n";
}

void Window_Main::menuStatisticsTextExpensesToday()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Statistics Text Expenses Today\n";
}

void Window_Main::menuStatisticsTextExpensesThisMonth()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Statistics Text Expenses This Month\n";
}

void Window_Main::menuStatisticsTextIncomeThisMonth()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Statistics Text Income This Month\n";
}

void Window_Main::menuFooterAddAccount()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Add Account\n";
}

void Window_Main::menuFooterAddAccountGroup()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Add Account Group\n";
}

void Window_Main::menuFooterAddBudget()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Add Budget\n";
}

void Window_Main::menuFooterImport()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Import\n";
}

void Window_Main::menuFooterExport()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Export\n";
}

void Window_Main::menuFooterSettings()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Settings\n";
}

void Window_Main::menuFooterHelp()
{
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Help\n";
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
  std::cout << Time() << " : SYSTEM : Window -> Main Window : Button -> Quit\n";
  hide();
}
