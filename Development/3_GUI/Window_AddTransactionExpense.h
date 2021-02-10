#pragma once

#include "../include/stdafx.h"
#include "../include/FLTK.h"
#include "../include/3_GUI.h"
#include "../include/1_DataAccess.h"

namespace Graph_lib
{
	class Window_AddTransactionExpense : public Window
	{
	public:
		Window_AddTransactionExpense(
			const std::string& title,
			std::shared_ptr<FinanceRepository> ptrFinanceRepository,
			Point xy = Point{ 150, 150 }, int w = 400, int h = 400);
		Button buttonOK;
		Button buttonCancel;
		bool wait_for_button();
		std::shared_ptr<FinanceRepository> ptrFinanceRepository;
	private:
		int elementSizeWidth = 200;
		int elementSizeHeight = 30;

		bool button_pushed;

		In_box textAccountForAdd;
		In_box textAmountForAdd;
		In_box textDesctiptionForAdd;
		In_box textPayeeForAdd;
		In_box textCategoryForAdd;
		In_box textCommentForAdd;
		In_box textTagForAdd;

		static void cbWindow_AddTransactionExpense_OK(Address, Address);
		static void cbWindow_AddTransactionExpense_Cancel(Address, Address);

		void Window_AddTransactionExpense_OK();
		void Window_AddTransactionExpense_Cancel();
	};
}