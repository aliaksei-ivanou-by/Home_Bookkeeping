#include "Home_Bookkeeping/0_Models/Transaction.h"

//  Constructor
//  With account from setting, category setting, amount setting, comment setting, currency setting,
//  description setting, payee setting, tag setting,
//  transaction status setting, transaction type setting
//  (income / expense)
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

//  Constructor
//  With account from setting, account to setting, category setting, amount setting, comment setting,
//  currency setting, description setting, payee setting, tag setting,
//  transaction status setting, transaction type setting
//  (transfer)
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

//  Constructor
//  With account from setting, category setting, amount setting
//  (income / expense)
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

//  Constructor
//  With account from setting, account to setting, category setting, amount setting
//  (transfer)
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

//  Constructor
//  Copy
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

//  Class member function
//  Get time
TimeDate Transaction::GetTime() const
{
  return time_;
}

//  Class member function
//  Get time in string format
std::string Transaction::GetStringTime() const
{
  return time_.GetStringTime();
}

//  Class member function
//  Get account from
Account Transaction::GetAccountFrom() const
{
  return *account_from_;
}

//  Class member function
//  Get account to
Account Transaction::GetAccountTo() const
{
  return *account_to_;
}

//  Class member function
//  Get category
Category Transaction::GetCategory() const
{
  return *category_;
}

//  Class member function
//  Get amount
NUM Transaction::GetAmount() const
{
  return amount_;
}

//  Class member function
//  Get amount of the account from
NUM Transaction::GetAmountAccountFrom() const
{
  return amount_account_from_;
}

//  Class member function
//  Get amount of the account to
NUM Transaction::GetAmountAccountTo() const
{
  return amount_account_to_;
}

//  Class member function
//  Get lastest amount of the account from
NUM Transaction::GetAmountLastestAccountFrom() const
{
  return (*account_from_).GetAmount();
}

//  Class member function
//  Get lastest amount of the account to
NUM Transaction::GetAmountLastestAccountTo() const
{
  return (*account_to_).GetAmount();
}

//  Class member function
//  Get comment
Comment Transaction::GetComment() const
{
  return *comment_;
}

//  Class member function
//  Get currency
Currency Transaction::GetCurrency() const
{
  return *currency_;
}

//  Class member function
//  Get description
Description Transaction::GetDescription() const
{
  return *description_;
}

//  Class member function
//  Get payee
Payee Transaction::GetPayee() const
{
  return *payee_;
}

//  Class member function
//  Get tag
Tag Transaction::GetTag() const
{
  return *tag_;
}

//  Class member function
//  Get status
Status Transaction::GetStatus() const
{
  return *status_;
}

//  Class member function
//  Get type
Type Transaction::GetType() const
{
  return *type_;
}

//  Class member function
//  Get account from (shared pointer)
std::shared_ptr<Account> Transaction::GetAccountFromPtr() const
{
  return account_from_;
}

//  Class member function
//  Get account to (shared pointer)
std::shared_ptr<Account> Transaction::GetAccountToPtr() const
{
  return account_to_;
}

//  Class member function
//  Get category (shared pointer)
std::shared_ptr<Category> Transaction::GetCategoryPtr() const
{
  return category_;
}

//  Class member function
//  Get comment (shared pointer)
std::shared_ptr<Comment> Transaction::GetCommentPtr() const
{
  return comment_;
}

//  Class member function
//  Get currency (shared pointer)
std::shared_ptr<Currency> Transaction::GetCurrencyPtr() const
{
  return currency_;
}

//  Class member function
//  Get description (shared pointer)
std::shared_ptr<Description> Transaction::GetDescriptionPtr() const
{
  return description_;
}

//  Class member function
//  Get payee (shared pointer)
std::shared_ptr<Payee> Transaction::GetPayeePtr() const
{
  return payee_;
}

//  Class member function
//  Get tag (shared pointer)
std::shared_ptr<Tag> Transaction::GetTagPtr() const
{
  return tag_;
}

//  Class member function
//  Get status (shared pointer)
std::shared_ptr<Status> Transaction::GetStatusPtr() const
{
  return status_;
}

//  Class member function
//  Get type (shared pointer)
std::shared_ptr<Type> Transaction::GetTypePtr() const
{
  return type_;
}

//  Class member function
//  Set time
void Transaction::SetTime(const TimeDate& time)
{
  time_ = time;
  PLOG_INFO << "Set new daytime";
}

//  Class member function
//  Set account from
void Transaction::SetAccountFrom(const Account& account_from)
{
  *account_from_ = account_from;
  PLOG_INFO << "Set new account from";
}

//  Class member function
//  Set account to
void Transaction::SetAccountTo(const Account& account_to)
{
  *account_to_ = account_to;
  PLOG_INFO << "Set new account to";
}

//  Class member function
//  Set category
void Transaction::SetCategory(const Category& category)
{
  *category_ = category;
  PLOG_INFO << "Set new category";
}

//  Class member function
//  Set amount
void Transaction::SetAmount(const NUM amount)
{
  amount_ = amount;
  PLOG_INFO << "Set new amount";
}

//  Class member function
//  Set amount of the account from
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

//  Class member function
//  Set lastest amount of the account to
void Transaction::SetAmountLastestAccountTo(const NUM amount)
{
  (*account_to_).SetAmount(amount);
  PLOG_INFO << "Set new lastest amount for account to";
}

//  Class member function
//  Set comment
void Transaction::SetComment(const Comment& comment)
{
  *comment_ = comment;
  PLOG_INFO << "Set new comment";
}

//  Class member function
//  Set currency
void Transaction::SetCurrency(const Currency& currency)
{
  *currency_ = currency;
  PLOG_INFO << "Set new currency";
}

//  Class member function
//  Set description
void Transaction::SetDescription(const Description& description)
{
  *description_ = description;
  PLOG_INFO << "Set new description";
}

//  Class member function
//  Set payee
void Transaction::SetPayee(const Payee& payee)
{
  *payee_ = payee;
  PLOG_INFO << "Set new payee";
}

//  Class member function
//  Set tag
void Transaction::SetTag(const Tag& tag)
{
  *tag_ = tag;
  PLOG_INFO << "Set new tag";
}

//  Class member function
//  Set status
void Transaction::SetStatus(const Status& status)
{
  *status_ = status;
  PLOG_INFO << "Set new status";
}

//  Class member function
//  Set type
void Transaction::SetType(const Type& type)
{
  *type_ = type;
  PLOG_INFO << "Set new type";
}

//  Class member function
//  Set account from (shared pointer)
void Transaction::SetAccountFromPtr(std::shared_ptr<Account> account_from)
{
  account_from_ = account_from;
  PLOG_INFO << "Set new account from";
}

//  Class member function
//  Set account to (shared pointer)
void Transaction::SetAccountToPtr(std::shared_ptr<Account> account_to)
{
  account_to_ = account_to;
  PLOG_INFO << "Set new account to";
}

//  Class member function
//  Set category (shared pointer)
void Transaction::SetCategoryPtr(std::shared_ptr<Category> category)
{
  category_ = category;
  PLOG_INFO << "Set new category";
}

//  Class member function
//  Set comment (shared pointer)
void Transaction::SetCommentPtr(std::shared_ptr<Comment> comment)
{
  comment_ = comment;
  PLOG_INFO << "Set new comment";
}

//  Class member function
//  Set currency (shared pointer)
void Transaction::SetCurrencyPtr(std::shared_ptr<Currency> currency)
{
  currency_ = currency;
  PLOG_INFO << "Set new currency";
}

//  Class member function
//  Set description (shared pointer)
void Transaction::SetDescriptionPtr(std::shared_ptr<Description> description)
{
  description_ = description;
  PLOG_INFO << "Set new description";
}

//  Class member function
//  Set payee (shared pointer)
void Transaction::SetPayeePtr(std::shared_ptr<Payee> payee)
{
  payee_ = payee;
  PLOG_INFO << "Set new payee";
}

//  Class member function
//  Set tag (shared pointer)
void Transaction::SetTagPtr(std::shared_ptr<Tag> tag)
{
  tag_ = tag;
  PLOG_INFO << "Set new tag";
}

//  Class member function
//  Set status (shared pointer)
void Transaction::SetStatusPtr(std::shared_ptr<Status> status)
{
  status_ = status;
  PLOG_INFO << "Set new status";
}

//  Class member function
//  Set type (shared pointer)
void Transaction::SetTypePtr(std::shared_ptr<Type> type)
{
  type_ = type;
  PLOG_INFO << "Set new type";
}

//  Class member function
//  Copy assignment operator
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

//  Friend class member function
//  Operator < for sorting models (by time)
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

//  Friend class member function
//  Output model (time \t account from \t category \t amount \t currency)
std::ostream& operator<<(std::ostream& output_stream, const Transaction& transaction)
{
  return output_stream << transaction.GetTime() << '\t' <<
                          transaction.GetAccountFrom() << '\t' <<
                          transaction.GetCategory() << '\t' <<
                          transaction.GetAmount() << ' ' <<
                          transaction.GetCurrency().GetName();
}
