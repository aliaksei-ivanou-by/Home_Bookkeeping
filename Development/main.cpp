#include "include/stdafx.h"
#include "include/constants.h"
#include "include/1_DataAccess_Additional.h"
#include "include/1_DataAccess_Main.h"
#include "include/2_BusinessLogic.h"
#include "include/3_GUI.h"

int main()
{
	FinanceRepository a;
	a.addCategory({ "Bills" });
	return 0;
}