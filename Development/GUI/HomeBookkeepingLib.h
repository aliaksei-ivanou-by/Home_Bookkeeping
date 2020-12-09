#pragma once

#include "../include/stdafx.h"
#include "../include/FLTK.h"
#include "../include/Graphics.h"

namespace Graph_lib
{
	class BookkkeepingMainWindow : public Simple_window
	{
	public:
		BookkkeepingMainWindow(Point xy, int w, int h, const std::string& title);
	private:
		Menu mymenu;

		static void cbTransactions(Address, Address);
		static void cbAccounts(Address, Address);
		static void cbPlanned(Address, Address);
		static void cbReports(Address, Address);
		static void cbBudget(Address, Address);
		static void cbStatistics(Address, Address);

		void transactions();
		void accounts();
		void planned();
		void reports();
		void budget();
		void statistics();
	};
}