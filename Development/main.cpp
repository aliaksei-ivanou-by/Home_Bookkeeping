#include "home_bookkeeping/3_GUI/Window_Main.h"

int main()
{
  FinanceRepository a;

  a.ClearTablesInDatabase();

  Payee payee_default;
  Payee payee_1("Payee_1");
  Payee payee_2("Payee_2");
  a.AddPayee(Payee());
  a.AddPayee(std::move(payee_default));
  a.AddPayee(std::move(payee_1));
  a.AddPayee(std::move(payee_2));
  PayeeRepository payee_repository;
  payee_repository.Add(payee_default);
  payee_repository.Add(payee_1);
  payee_repository.Add(payee_2);
  a.AddPayees(std::move(payee_repository));
  bool payee_find;
  int payee_id;
  Payee payee_payee;
  int payee_counter;
  std::tie(payee_find, payee_id, payee_payee, payee_counter) = a.FindPayee("Payee_1");
  std::tie(payee_find, payee_id, payee_payee, payee_counter) = a.FindPayee("Payee");

  Comment comment_default;
  Comment comment_1("Comment_1");
  Comment comment_2("Comment_2");
  a.AddComment(Comment());
  a.AddComment(std::move(comment_default));
  a.AddComment(std::move(comment_1));
  a.AddComment(std::move(comment_2));
  CommentRepository comment_repository;
  comment_repository.Add(comment_default);
  comment_repository.Add(comment_1);
  comment_repository.Add(comment_2);
  a.AddComments(std::move(comment_repository));
  bool com_find;
  int com_id;
  Comment com_com;
  int com_counter;
  std::tie(com_find, com_id, com_com, com_counter) = a.FindComment("Comment_1");
  std::tie(com_find, com_id, com_com, com_counter) = a.FindComment("Comment");

  Tag tag_default;
  Tag tag_1("Tag_1");
  Tag tag_2("Tag_2");
  a.AddTag(Tag());
  a.AddTag(std::move(tag_default));
  a.AddTag(std::move(tag_1));
  a.AddTag(std::move(tag_2));
  TagRepository tag_repository;
  tag_repository.Add(tag_default);
  tag_repository.Add(tag_1);
  tag_repository.Add(tag_2);
  a.AddTags(std::move(tag_repository));
  bool tag_find;
  int tag_id;
  Tag tag_tag;
  int tag_counter;
  std::tie(tag_find, tag_id, tag_tag, tag_counter) = a.FindTag("Tag_1");
  std::tie(tag_find, tag_id, tag_tag, tag_counter) = a.FindTag("Tag");

  Description description_default;
  Description description_1("Description_1");
  Description description_2("Description_2");
  a.AddDescription(Description());
  a.AddDescription(std::move(description_default));
  a.AddDescription(std::move(description_1));
  a.AddDescription(std::move(description_2));
  DescriptionRepository description_repository;
  description_repository.Add(description_default);
  description_repository.Add(description_1);
  description_repository.Add(description_2);
  a.AddDescriptions(std::move(description_repository));
  bool desc_find;
  int desc_id;
  Description desc_desc;
  int desc_counter;
  std::tie(desc_find, desc_id, desc_desc, desc_counter) = a.FindDescription("Description_1");
  std::tie(desc_find, desc_id, desc_desc, desc_counter) = a.FindDescription("Description");

  Category category_default;
  Category category_1("Category_1");
  Category category_2("Category_2");
  a.AddCategory(Category());
  a.AddCategory(std::move(category_default));
  a.AddCategory(std::move(category_1));
  a.AddCategory(std::move(category_2));
  CategoryRepository category_repository;
  category_repository.Add(category_default);
  category_repository.Add(category_1);
  category_repository.Add(category_2);
  a.AddCategories(std::move(category_repository));
  bool cat_find;
  int cat_id;
  Category cat_cat;
  int cat_counter;
  std::tie(cat_find, cat_id, cat_cat, cat_counter) = a.FindCategory("Category_1");
  std::tie(cat_find, cat_id, cat_cat, cat_counter) = a.FindCategory("Category");

  Account account_default;
  Account account_1("Account_1");
  Account account_2("Account_2");
  a.AddAccount(Account());
  a.AddAccount(std::move(account_default));
  a.AddAccount(std::move(account_1));
  a.AddAccount(std::move(account_2));
  AccountRepository account_repository;
  account_repository.Add(account_default);
  account_repository.Add(account_1);
  account_repository.Add(account_2);
  a.AddAccounts(std::move(account_repository));
  bool acc_find;
  int acc_id;
  Account acc_acc;
  std::tie(acc_find, acc_id, acc_acc) = a.FindAccount("Account_1");
  std::tie(acc_find, acc_id, acc_acc) = a.FindAccount("Account_2");
  a.SetAccountName("Account_1", "New_Account_1");
  a.SetAccountAmount("New_Account_1", 255.0);

  Currency currency_default;
  Currency currency_1("Currency_1");
  Currency currency_2("Currency_2");
  a.AddCurrency(Currency());
  a.AddCurrency(std::move(currency_default));
  a.AddCurrency(std::move(currency_1));
  a.AddCurrency(std::move(currency_2));
  CurrencyRepository currency_repository;
  currency_repository.Add(currency_default);
  currency_repository.Add(currency_1);
  currency_repository.Add(currency_2);
  a.AddCurrencies(std::move(currency_repository));
  bool cur_find;
  int cur_id;
  Currency cur_cur;
  std::tie(cur_find, cur_id, cur_cur) = a.FindCurrencyByName("Currency_1");
  std::tie(cur_find, cur_id, cur_cur) = a.FindCurrencyByName("Currency_2");

  // Window_Main win(Point(100, 100), 600, 600, "Finance System", std::make_shared<FinanceRepository>(a));
  // return gui_main();
}