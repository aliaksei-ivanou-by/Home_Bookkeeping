#include "Window_Main.h"
#include "Window_AddTransactionTransfer.h"

Window_AddTransactionTransfer::Window_AddTransactionTransfer(const std::string& title,
	std::shared_ptr<FinanceRepository> ptrFinanceRepositoryForAdd, Point xy, int w, int h) :
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
	textTagForAdd{ Point(x_max() - 280, y_max() - 210), elementSizeWidth, elementSizeHeight, "Tag: " },
	ptrFinanceRepository{ ptrFinanceRepositoryForAdd }
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
	ptrFinanceRepository->addTransaction(transaction);
	std::cout << Time() << " : REPOSITORY : Operation -> Transaction added\n";
	button_pushed = true;
	std::cout << Time() << " : SYSTEM : Window -> Add Transaction Transfer : Button -> OK\n";
	hide();
}
catch (...)
{
	std::cout << Time() << " : SYSTEM : Error -> Transaction no added\n";
	std::cout << Time() << " : SYSTEM : Window -> Add Transaction Transfer : Button -> OK\n";
	button_pushed = true;
	hide();
}

void Window_AddTransactionTransfer::Cancel()
{
	button_pushed = true;
	std::cout << Time() << " : SYSTEM : Window -> Add Transaction Transfer : Button -> Cancel\n";
	hide();
}