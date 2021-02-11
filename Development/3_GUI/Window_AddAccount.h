/*#pragma once

#include "../include/stdafx.h"
#include "../include/FLTK.h"
#include "../include/3_GUI.h"
#include "../include/1_DataAccess.h"

namespace Graph_lib
{
	class Window_AddAccount : public Window
	{
	public:
		Window_AddAccount(
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

		static void cbOK(Address, Address);
		static void cbCancel(Address, Address);

		void OK();
		void Cancel();
	};
}*/