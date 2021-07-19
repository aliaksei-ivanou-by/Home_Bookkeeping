#include "include/0_Models/Transaction.h"

Transaction::Transaction(
  const Account& account_from,
  const Category& category,
  const double amount,
  const Comment& comment,
  const Currency& currency,
  const Description& description,
  const Payee& payee,
  const Tag& tag,
  const Status& status,
  const Type& type):
  time_{ TimeDate() },
  account_from_{ std::make_shared<Account>(account_from) },
  account_to_{ account_from_ },
  category_{ std::make_shared<Category>(category) },
  amount_{ NUM(amount) },
  amount_account_from_{ NUM(0.0) },
  amount_account_to_{ NUM(0.0) },
  comment_{ std::make_shared<Comment>(comment) },
  currency_{ std::make_shared<Currency>(currency) },
  description_{ std::make_shared<Description>(description) },
  payee_{ std::make_shared<Payee>(payee) },
  tag_{ std::make_shared<Tag>(tag) },
  status_{ std::make_shared<Status>(status) },
  type_{ std::make_shared<Type>(type) }
{}

Transaction::Transaction(
  const Account& account_from,
  const Account& account_to,
  const Category& category,
  const double amount,
  const Comment& comment,
  const Currency& currency,
  const Description& description,
  const Payee& payee,
  const Tag& tag,
  const Status& status,
  const Type& type):
  time_{ TimeDate() },
  account_from_{ std::make_shared<Account>(account_from) },
  account_to_{ std::make_shared<Account>(account_to) },
  category_{ std::make_shared<Category>(category) },
  amount_{ NUM(amount) },
  amount_account_from_{ NUM(0.0) },
  amount_account_to_{ NUM(0.0) },
  comment_{ std::make_shared<Comment>(comment) },
  currency_{ std::make_shared<Currency>(currency) },
  description_{ std::make_shared<Description>(description) },
  payee_{ std::make_shared<Payee>(payee) },
  tag_{ std::make_shared<Tag>(tag) },
  status_{ std::make_shared<Status>(status) },
  type_{ std::make_shared<Type>(type) }
{}

Transaction::Transaction(
  const Account& account_from,
  const Category& category,
  const double amount):
  time_{ TimeDate() },
  account_from_{ std::make_shared<Account>(account_from) },
  account_to_{ account_from_ },
  category_{ std::make_shared<Category>(category) },
  amount_{ NUM(amount) },
  amount_account_from_{ NUM(0.0) },
  amount_account_to_{ NUM(0.0) },
  comment_{ std::make_shared<Comment>(Comment()) },
  currency_{ std::make_shared<Currency>(Currency()) },
  description_{ std::make_shared<Description>(Description()) },
  payee_{ std::make_shared<Payee>(Payee()) },
  tag_{ std::make_shared<Tag>(Tag()) },
  status_{ std::make_shared<Status>(Status()) },
  type_{ std::make_shared<Type>(Type()) }
{}

Transaction::Transaction(
  const Account& account_from,
  const Account& account_to,
  const Category& category,
  const double amount):
  time_{ TimeDate() },
  account_from_{ std::make_shared<Account>(account_from) },
  account_to_{ std::make_shared<Account>(account_to) },
  category_{ std::make_shared<Category>(category) },
  amount_{ NUM(amount) },
  amount_account_from_{ NUM(0.0) },
  amount_account_to_{ NUM(0.0) },
  comment_{ std::make_shared<Comment>(Comment()) },
  currency_{ std::make_shared<Currency>(Currency()) },
  description_{ std::make_shared<Description>(Description()) },
  payee_{ std::make_shared<Payee>(Payee()) },
  tag_{ std::make_shared<Tag>(Tag()) },
  status_{ std::make_shared<Status>(Status()) },
  type_{ std::make_shared<Type>(Type(kEnumType::Transfer)) }
{}

Transaction::Transaction(const Transaction& transaction)
{
  time_ = TimeDate();
  account_from_ = std::make_shared<Account>(transaction.GetAccountFrom());
  account_to_ = std::make_shared<Account>(transaction.GetAccountTo());
  category_ = std::make_shared<Category>(transaction.GetCategory());
  amount_ = transaction.amount_;
  amount_account_from_ = transaction.amount_account_from_;
  amount_account_to_ = transaction.amount_account_to_;
  comment_ = std::make_shared<Comment>(transaction.GetComment());
  currency_ = std::make_shared<Currency>(transaction.GetCurrency());
  description_ = std::make_shared<Description>(transaction.GetDescription());
  payee_ = std::make_shared<Payee>(transaction.GetPayee());
  tag_ = std::make_shared<Tag>(transaction.GetTag());
  status_ = std::make_shared<Status>(transaction.GetStatus());
  type_ = std::make_shared<Type>(transaction.GetType());
}

TimeDate Transaction::GetTime() const
{
  return time_;
}

std::string Transaction::GetStringTime() const
{
  return time_.GetStringTime();
}

Account Transaction::GetAccountFrom() const
{
  return *account_from_;
}

Account Transaction::GetAccountTo() const
{
  return *account_to_;
}

Category Transaction::GetCategory() const
{
  return *category_;
}

NUM Transaction::GetAmount() const
{
  return amount_;
}

NUM Transaction::GetAmountAccountFrom() const
{
  return amount_account_from_;
}

NUM Transaction::GetAmountAccountTo() const
{
  return amount_account_to_;
}

NUM Transaction::GetAmountLastestAccountFrom() const
{
  return (*account_from_).GetAmount();
}

NUM Transaction::GetAmountLastestAccountTo() const
{
  return (*account_to_).GetAmount();
}

Comment Transaction::GetComment() const
{
  return *comment_;
}

Currency Transaction::GetCurrency() const
{
  return *currency_;
}

Description Transaction::GetDescription() const
{
  return *description_;
}

Payee Transaction::GetPayee() const
{
  return *payee_;
}

Tag Transaction::GetTag() const
{
  return *tag_;
}

Status Transaction::GetStatus() const
{
  return *status_;
}

Type Transaction::GetType() const
{
  return *type_;
}

std::shared_ptr<Account> Transaction::GetAccountFromPtr() const
{
  return account_from_;
}

std::shared_ptr<Account> Transaction::GetAccountToPtr() const
{
  return account_to_;
}

std::shared_ptr<Category> Transaction::GetCategoryPtr() const
{
  return category_;
}

std::shared_ptr<Comment> Transaction::GetCommentPtr() const
{
  return comment_;
}

std::shared_ptr<Currency> Transaction::GetCurrencyPtr() const
{
  return currency_;
}

std::shared_ptr<Description> Transaction::GetDescriptionPtr() const
{
  return description_;
}

std::shared_ptr<Payee> Transaction::GetPayeePtr() const
{
  return payee_;
}

std::shared_ptr<Tag> Transaction::GetTagPtr() const
{
  return tag_;
}

std::shared_ptr<Status> Transaction::GetStatusPtr() const
{
  return status_;
}

std::shared_ptr<Type> Transaction::GetTypePtr() const
{
  return type_;
}

void Transaction::SetTime(const TimeDate& time)
{
  time_ = time;
  PLOG_INFO << "Set new daytime";
}

void Transaction::SetAccountFrom(const Account& account_from)
{
  *account_from_ = account_from;
  PLOG_INFO << "Set new account from";
}

void Transaction::SetAccountTo(const Account& account_to)
{
  *account_to_ = account_to;
  PLOG_INFO << "Set new account to";
}

void Transaction::SetCategory(const Category& category)
{
  *category_ = category;
  PLOG_INFO << "Set new category";
}

void Transaction::SetAmount(const NUM amount)
{
  amount_ = amount;
  PLOG_INFO << "Set new amount";
}

void Transaction::SetAmountAccountFrom(const NUM amount)
{
  amount_account_from_ = amount;
  PLOG_INFO << "Set new amount for account from";
}

void Transaction::SetAmountAccountTo(const NUM amount)
{
  amount_account_to_ = amount;
  PLOG_INFO << "Set new amount for account to";
}

void Transaction::SetAmountLastestAccountFrom(const NUM amount)
{
  (*account_from_).SetAmount(amount);
  PLOG_INFO << "Set new lastest amount for account from";
}

void Transaction::SetAmountLastestAccountTo(const NUM amount)
{
  (*account_to_).SetAmount(amount);
  PLOG_INFO << "Set new lastest amount for account to";
}

void Transaction::SetComment(const Comment& comment)
{
  *comment_ = comment;
  PLOG_INFO << "Set new comment";
}

void Transaction::SetCurrency(const Currency& currency)
{
  *currency_ = currency;
  PLOG_INFO << "Set new currency";
}

void Transaction::SetDescription(const Description& description)
{
  *description_ = description;
  PLOG_INFO << "Set new description";
}

void Transaction::SetPayee(const Payee& payee)
{
  *payee_ = payee;
  PLOG_INFO << "Set new payee";
}

void Transaction::SetTag(const Tag& tag)
{
  *tag_ = tag;
  PLOG_INFO << "Set new tag";
}

void Transaction::SetStatus(const Status& status)
{
  *status_ = status;
  PLOG_INFO << "Set new status";
}

void Transaction::SetType(const Type& type)
{
  *type_ = type;
  PLOG_INFO << "Set new type";
}

void Transaction::SetAccountFromPtr(std::shared_ptr<Account> account_from)
{
  account_from_ = account_from;
  PLOG_INFO << "Set new account from";
}

void Transaction::SetAccountToPtr(std::shared_ptr<Account> account_to)
{
  account_to_ = account_to;
  PLOG_INFO << "Set new account to";
}

void Transaction::SetCategoryPtr(std::shared_ptr<Category> category)
{
  category_ = category;
  PLOG_INFO << "Set new category";
}

void Transaction::SetCommentPtr(std::shared_ptr<Comment> comment)
{
  comment_ = comment;
  PLOG_INFO << "Set new comment";
}

void Transaction::SetCurrencyPtr(std::shared_ptr<Currency> currency)
{
  currency_ = currency;
  PLOG_INFO << "Set new currency";
}

void Transaction::SetDescriptionPtr(std::shared_ptr<Description> description)
{
  description_ = description;
  PLOG_INFO << "Set new description";
}

void Transaction::SetPayeePtr(std::shared_ptr<Payee> payee)
{
  payee_ = payee;
  PLOG_INFO << "Set new payee";
}

void Transaction::SetTagPtr(std::shared_ptr<Tag> tag)
{
  tag_ = tag;
  PLOG_INFO << "Set new tag";
}

void Transaction::SetStatusPtr(std::shared_ptr<Status> status)
{
  status_ = status;
  PLOG_INFO << "Set new status";
}

void Transaction::SetTypePtr(std::shared_ptr<Type> type)
{
  type_ = type;
  PLOG_INFO << "Set new type";
}

Transaction& Transaction::operator=(const Transaction& transaction)
{
  time_ = TimeDate();
  account_from_ = std::make_shared<Account>(transaction.GetAccountFrom());
  account_to_ = std::make_shared<Account>(transaction.GetAccountTo());
  category_ = std::make_shared<Category>(transaction.GetCategory());
  amount_ = transaction.amount_;
  amount_account_from_ = transaction.amount_account_from_;
  amount_account_to_ = transaction.amount_account_to_;
  comment_ = std::make_shared<Comment>(transaction.GetComment());
  currency_ = std::make_shared<Currency>(transaction.GetCurrency());
  description_ = std::make_shared<Description>(transaction.GetDescription());
  payee_ = std::make_shared<Payee>(transaction.GetPayee());
  tag_ = std::make_shared<Tag>(transaction.GetTag());
  status_ = std::make_shared<Status>(transaction.GetStatus());
  type_ = std::make_shared<Type>(transaction.GetType());
  return *this;
}

bool operator<(const Transaction& transaction_left, const Transaction& transaction_right)
{
  if (transaction_left.GetTime() < transaction_right.GetTime())
  {
    return true;
  }
  else
  {
    return false;
  }
}

std::ostream& operator<<(std::ostream& output_stream, const Transaction& transaction)
{
  return output_stream << transaction.GetTime() << '\t' <<
                          transaction.GetAccountFrom() << '\t' <<
                          transaction.GetCategory() << '\t' <<
                          transaction.GetAmount() << ' ' <<
                          transaction.GetCurrency().GetName();
}
