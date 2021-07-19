#ifndef HOMEBOOKKEEPING_3GUI_WINDOWMAIN_H_
#define HOMEBOOKKEEPING_3GUI_WINDOWMAIN_H_

#include "lib/graph/FLTK.h"
#include "lib/graph/Point.h"
#include "lib/graph/Graph.h"
#include "lib/graph/Graph_Additional.h"
#include "lib/graph/GUI.h"
#include "lib/graph/Simple_window.h"
#include "lib/graph/Window.h"

#include "include/2_BusinessLogic/FinanceRepository.h"

#include "include/3_GUI/Window_AddAccount.h"
#include "include/3_GUI/Window_AddTransactionExpense.h"
#include "include/3_GUI/Window_AddTransactionIncome.h"
#include "include/3_GUI/Window_AddTransactionTransfer.h"

namespace Graph_lib
{
  class Window_Main : public Window
  {
  public:
    Window_Main(Point xy, int w, int h, const std::string& title, std::shared_ptr<FinanceRepository> ptrFinanceRepository);
    bool wait_for_button();
    Button buttonQuit;
    std::shared_ptr<FinanceRepository> ptrFinanceRepository;
  private:
    int buttonSizeWidth = 300;
    int buttonSizeHeight = 30;

    Menu menuAddTransaction;
    Menu menuMain;
    Menu menuStatistics;
    Menu menuStatisticsText;
    Menu menuFooter;

    bool button_pushed;

    static void cbQuit(Address, Address);
    void quit();

    static void cbMenuMainAddTransactionExpense(Address, Address);
    static void cbMenuMainAddTransactionIncome(Address, Address);
    static void cbMenuMainAddTransactionTransfer(Address, Address);
    static void cbMenuMainTransactions(Address, Address);
    static void cbMenuMainAccounts(Address, Address);
    static void cbMenuMainPlanned(Address, Address);
    static void cbMenuMainReports(Address, Address);
    static void cbMenuMainBudget(Address, Address);
    static void cbMenuMainStatistics(Address, Address);

    static void cbMenuStatisticsNetWorth(Address, Address);
    static void cbMenuStatisticsLiabilities(Address, Address);
    static void cbMenuStatisticsExpensesToday(Address, Address);
    static void cbMenuStatisticsExpensesThisMonth(Address, Address);
    static void cbMenuStatisticsIncomeThisMonth(Address, Address);

    static void cbMenuStatisticsTextNetWorth(Address, Address);
    static void cbMenuStatisticsTextLiabilities(Address, Address);
    static void cbMenuStatisticsTextExpensesToday(Address, Address);
    static void cbMenuStatisticsTextExpensesThisMonth(Address, Address);
    static void cbMenuStatisticsTextIncomeThisMonth(Address, Address);

    static void cbMenuFooterAddAccount(Address, Address);
    static void cbMenuFooterAddAccountGroup(Address, Address);
    static void cbMenuFooterAddBudget(Address, Address);
    static void cbMenuFooterImport(Address, Address);
    static void cbMenuFooterExport(Address, Address);
    static void cbMenuFooterSettings(Address, Address);
    static void cbMenuFooterHelp(Address, Address);

    void menuMainAddTransactionExpense();
    void menuMainAddTransactionIncome();
    void menuMainAddTransactionTransfer();
    void menuMainTransactions();
    void menuMainAccounts();
    void menuMainPlanned();
    void menuMainReports();
    void menuMainBudget();
    void menuMainStatistics();

    void menuStatisticsNetWorth();
    void menuStatisticsLiabilities();
    void menuStatisticsExpensesToday();
    void menuStatisticsExpensesThisMonth();
    void menuStatisticsIncomeThisMonth();

    void menuStatisticsTextNetWorth();
    void menuStatisticsTextLiabilities();
    void menuStatisticsTextExpensesToday();
    void menuStatisticsTextExpensesThisMonth();
    void menuStatisticsTextIncomeThisMonth();

    void menuFooterAddAccount();
    void menuFooterAddAccountGroup();
    void menuFooterAddBudget();
    void menuFooterImport();
    void menuFooterExport();
    void menuFooterSettings();
    void menuFooterHelp();
  };
}

#endif  //  HOMEBOOKKEEPING_3GUI_WINDOWMAIN_H_
