#pragma once

#include "../include/stdafx.h"
#include "../include/FLTK.h"
#include "../include/Graphics.h"
#include "../include/DataAccess.h"

namespace Graph_lib
{
	class Window_AddTransactionIncome : public Window
	{
	public:
		Window_AddTransactionIncome(
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

		static void cbOK(Address, Address);
		static void cbCancel(Address, Address);

		void OK();
		void Cancel();
	};
}