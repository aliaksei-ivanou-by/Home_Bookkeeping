#include "Window_Main.h"
#include "Window_AddTransactionExpense.h"

Window_AddTransactionExpense::Window_AddTransactionExpense(const std::string& title,
	std::shared_ptr<FinanceRepository> ptrFinanceRepositoryForAdd, Point xy, int w, int h) :
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
	textTagForAdd{ Point(x_max() - 280, y_max() - 180), elementSizeWidth, elementSizeHeight, "Tag: " },
	ptrFinanceRepository{ ptrFinanceRepositoryForAdd }
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
	ptrFinanceRepository->addTransaction(transaction);
	std::cout << Time() << " : REPOSITORY : Operation -> Transaction added\n";
	button_pushed = true;
	std::cout << Time() << " : SYSTEM : Window -> Add Transaction Expense : Button -> OK\n";
	hide();
}
catch (...)
{
	std::cout << Time() << " : SYSTEM : Error -> Transaction no added\n";
	std::cout << Time() << " : SYSTEM : Window -> Add Transaction Expense : Button -> OK\n";
	button_pushed = true;
	hide();
}

void Window_AddTransactionExpense::Window_AddTransactionExpense_Cancel()
{
	button_pushed = true;
	std::cout << Time() << " : SYSTEM : Window -> Add Transaction Expense : Button -> Cancel\n";
	hide();
}