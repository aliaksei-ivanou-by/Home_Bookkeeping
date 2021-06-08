#include "home_bookkeeping/3_GUI/Window_Main.h"

int main()
{
  FinanceRepository a;

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

  // Window_Main win(Point(100, 100), 600, 600, "Finance System", std::make_shared<FinanceRepository>(a));
  // return gui_main();
}