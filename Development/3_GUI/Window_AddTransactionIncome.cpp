#include "home_bookkeeping/3_GUI/Window_AddTransactionIncome.h"

Window_AddTransactionIncome::Window_AddTransactionIncome(
  const std::string& title,
  std::shared_ptr<FinanceRepository> ptrFinanceRepositoryForAdd, Point xy, int w, int h):
  Window{ xy, w, h, title },
  buttonOK{ Point(x_max() - 250, 350), 100, 20, "OK", cbOK },
  buttonCancel{ Point(x_max() - 150, 350), 100, 20, "Cancel", cbCancel },
  button_pushed{ false },
  textAccountForAdd{ Point(x_max() - 280, y_max() - 390), elementSizeWidth, elementSizeHeight, "Account: " },
  textAmountForAdd{ Point(x_max() - 280, y_max() - 360), elementSizeWidth, elementSizeHeight, "Amount: " },
  textDesctiptionForAdd{ Point(x_max() - 280, y_max() - 330), elementSizeWidth, elementSizeHeight, "Description: " },
  textPayeeForAdd{ Point(x_max() - 280, y_max() - 300), elementSizeWidth, elementSizeHeight, "Payee: " },
  textCategoryForAdd{ Point(x_max() - 280, y_max() - 270), elementSizeWidth, elementSizeHeight, "Category: " },
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
  attach(textCommentForAdd);
  attach(textTagForAdd);
}

bool Window_AddTransactionIncome::wait_for_button()
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

void Window_AddTransactionIncome::cbOK(Address, Address pw)
{
  reference_to<Window_AddTransactionIncome>(pw).OK();
}

void Window_AddTransactionIncome::cbCancel(Address, Address pw)
{
  reference_to<Window_AddTransactionIncome>(pw).Cancel();
}

void Window_AddTransactionIncome::OK()
try
{
  Account account(textAccountForAdd.get_string());
  Category category(textCategoryForAdd.get_string());
  double amount(std::stod(textAmountForAdd.get_string()));
  Comment comment(textCommentForAdd.get_string());
  Description description(textDesctiptionForAdd.get_string());
  Payee payee(textPayeeForAdd.get_string());
  Tag tag(textTagForAdd.get_string());
  Status transactionStatus(kEnumStatus::Void);
  Type transactionType(kEnumType::Income);
  Transaction transaction(account, category, amount, comment, { "" }, description, payee, tag,
    transactionStatus, transactionType);
  ptrFinanceRepository->AddTransaction(transaction);
  std::cout << Time() << " : REPOSITORY : Operation -> Transaction added\n";
  button_pushed = true;
  hide();
}
catch (...)
{
  std::cout << Time() << " : SYSTEM : Error -> Transaction no added\n";
  button_pushed = true;
  hide();
}

void Window_AddTransactionIncome::Cancel()
{
  button_pushed = true;
  hide();
}
