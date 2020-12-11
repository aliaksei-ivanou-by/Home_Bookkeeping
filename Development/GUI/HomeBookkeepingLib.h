#pragma once

#include "../include/stdafx.h"
#include "../include/FLTK.h"
#include "../include/Graphics.h"
#include "../include/DataAccess.h"

namespace Graph_lib
{
	class Window_Main : public Window
	{
	public:
		Window_Main(Point xy, int w, int h, const std::string& title);
		bool wait_for_button();
		Button buttonQuit;
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
		static void cbMenuStatisticsExpensesThisWeek(Address, Address);
		static void cbMenuStatisticsExpensesThisMonth(Address, Address);
		static void cbMenuStatisticsIncomeThisMonth(Address, Address);

		static void cbMenuStatisticsTextNetWorth(Address, Address);
		static void cbMenuStatisticsTextLiabilities(Address, Address);
		static void cbMenuStatisticsTextExpensesToday(Address, Address);
		static void cbMenuStatisticsTextExpensesThisWeek(Address, Address);
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
		void menuStatisticsExpensesThisWeek();
		void menuStatisticsExpensesThisMonth();
		void menuStatisticsIncomeThisMonth();

		void menuStatisticsTextNetWorth();
		void menuStatisticsTextLiabilities();
		void menuStatisticsTextExpensesToday();
		void menuStatisticsTextExpensesThisWeek();
		void menuStatisticsTextExpensesThisMonth();
		void menuStatisticsTextIncomeThisMonth();

		void menuFooterAddAccount();
		void menuFooterAddAccountGroup();
		void menuFooterAddBudget();
		void menuFooterImport();
		void menuFooterExport();
		void menuFooterSettings();
		void menuFooterHelp();

		//friend Window_AddTransactionExpense;
	};

	class Window_AddTransactionExpense : public Window
	{
	public:
		Window_AddTransactionExpense(const std::string& title, Point xy = Point{ 150, 150 }, int w = 400, int h = 400);
		Button buttonOK;
		Button buttonCancel;
		bool wait_for_button();
	private:
		int elementSizeWidth = 200;
		int elementSizeHeight = 30;

		bool button_pushed;

		In_box textAccountForAdd;
		In_box textAmountForAdd;
		In_box textDesctiptionForAdd;
		In_box textPayeeForAdd;
		In_box textCategoryForAdd;
		In_box textCategorySubForAdd;
		In_box textCommentForAdd;
		In_box textTagForAdd;

		static void cbWindow_AddTransactionExpense_OK(Address, Address);
		static void cbWindow_AddTransactionExpense_Cancel(Address, Address);

		void Window_AddTransactionExpense_OK();
		void Window_AddTransactionExpense_Cancel();

		friend Window_Main;
	};

	class Window_AddTransactionIncome : public Window
	{
	public:
		Window_AddTransactionIncome(const std::string& title, Point xy = Point{ 150, 150 }, int w = 400, int h = 400);
		Button buttonOK;
		Button buttonCancel;
		bool wait_for_button();
	private:
		int elementSizeWidth = 200;
		int elementSizeHeight = 30;

		bool button_pushed;

		In_box textAccountForAdd;
		In_box textAmountForAdd;
		In_box textDesctiptionForAdd;
		In_box textPayeeForAdd;
		In_box textCategoryForAdd;
		In_box textCategorySubForAdd;
		In_box textCommentForAdd;
		In_box textTagForAdd;

		static void cbOK(Address, Address);
		static void cbCancel(Address, Address);

		void OK();
		void Cancel();
	};

	class Window_AddTransactionTransfer : public Window
	{
	public:
		Window_AddTransactionTransfer(const std::string& title, Point xy = Point{ 150, 150 }, int w = 400, int h = 400);
		Button buttonOK;
		Button buttonCancel;
		bool wait_for_button();
	private:
		int elementSizeWidth = 200;
		int elementSizeHeight = 30;

		bool button_pushed;

		In_box textAccountFromForAdd;
		In_box textAccountToForAdd;
		In_box textAmountForAdd;
		In_box textDesctiptionForAdd;
		In_box textCategoryForAdd;
		In_box textCommentForAdd;
		In_box textTagForAdd;

		static void cbOK(Address, Address);
		static void cbCancel(Address, Address);

		void OK();
		void Cancel();
	};
}