#include "home_bookkeeping/2_BusinessLogic/FinanceRepository.h"

//  Constructor
//  Default
FinanceRepository::FinanceRepository()
{
  //  const std::string logfile_name = "log_" + Time().GetStringTime() + ".txt";
  //  const char* logfile_name_char = const_cast<char*>(logfile_name.c_str());
  //  plog::init(plog::debug, ("log" + Time().GetStringTime() + ".txt").c_str());
  plog::init(plog::verbose, "log.txt");
  PLOG_INFO << "Logger init";
  database_manager_ = new DatabaseManager();
}

//  Destructor
//  Default
FinanceRepository::~FinanceRepository()
{}

//  Class member function
//  Find begin iterator of transaction repository
TransactionRepositoryIterator FinanceRepository::BeginTransactionRepository() const
{
  return transaction_repository_.Begin();
}

//  Class member function
//  Find begin iterator of account repository
AccountRepositoryIterator FinanceRepository::BeginAccountRepository() const
{
  return account_repository_.Begin();
}

//  Class member function
//  Find begin iterator of category repository
CategoryRepositoryIterator FinanceRepository::BeginCategoryRepository() const
{
  return category_repository_.Begin();
}

//  Class member function
//  Find begin iterator of currency repository
CurrencyRepositoryIterator FinanceRepository::BeginCurrencyRepository() const
{
  return currency_repository_.Begin();
}

//  Class member function
//  Find begin iterator of description repository
DescriptionRepositoryIterator FinanceRepository::BeginDescriptionRepository() const
{
  return description_repository_.Begin();
}

//  Class member function
//  Find begin iterator of payee repository
PayeeRepositoryIterator FinanceRepository::BeginPayeeRepository() const
{
  return payee_repository_.Begin();
}

//  Class member function
//  Find begin iterator of comment repository
CommentRepositoryIterator FinanceRepository::BeginCommentRepository() const
{
  return comment_repository_.Begin();
}

//  Class member function
//  Find begin iterator of tag repository
TagRepositoryIterator FinanceRepository::BeginTagRepository() const
{
  return tag_repository_.Begin();
}

//  Class member function
//  Find end iterator of transaction repository
TransactionRepositoryIterator FinanceRepository::EndTransactionRepository() const
{
  return transaction_repository_.End();
}

//  Class member function
//  Find end iterator of account repository
AccountRepositoryIterator FinanceRepository::EndAccountRepository() const
{
  return account_repository_.End();
}

//  Class member function
//  Find end iterator of category repository
CategoryRepositoryIterator FinanceRepository::EndCategoryRepository() const
{
  return category_repository_.End();
}

//  Class member function
//  Find end iterator of currency repository
CurrencyRepositoryIterator FinanceRepository::EndCurrencyRepository() const
{
  return currency_repository_.End();
}

//  Class member function
//  Find end iterator of description repository
DescriptionRepositoryIterator FinanceRepository::EndDescriptionRepository() const
{
	return description_repository_.End();
}

//  Class member function
//  Find end iterator of payee repository
PayeeRepositoryIterator FinanceRepository::EndPayeeRepository() const
{
	return payee_repository_.End();
}

//  Class member function
//  Find end iterator of comment repository
CommentRepositoryIterator FinanceRepository::EndCommentRepository() const
{
	return comment_repository_.End();
}

//  Class member function
//  Find end iterator of tag repository
TagRepositoryIterator FinanceRepository::EndTagRepository() const
{
  return tag_repository_.End();
}

//  Class member function
//  Add transaction to transaction repository
void FinanceRepository::AddTransaction(Transaction&& transaction)
{
  UpdateAccountRepository(transaction);
  UpdateAccountAmount(transaction);
  UpdateCategoryRepository(transaction);
  UpdateCurrencyRepository(transaction);
  UpdateDescriptionRepository(transaction);
  UpdatePayeeRepository(transaction);
  UpdateCommentRepository(transaction);
  UpdateTagRepository(transaction);
  transaction_repository_.Add(transaction);
  PLOG_INFO << "Add transaction to repository";
  database_manager_->SaveToDatabaseTransactions(transaction_repository_);
}

//  Class member function
//  Add account (default) to account repository
void FinanceRepository::AddAccount()
{
  account_repository_.Add();
  PLOG_INFO << "Add Account to repository";
}

//  Class member function
//  Add account to account repository
void FinanceRepository::AddAccount(const Account& account)
{
  account_repository_.Add(account);
  PLOG_INFO << "Add Account to repository";
}

//  Class member function
//  Add category (default) to category repository
void FinanceRepository::AddCategory()
{
  category_repository_.Add();
  PLOG_INFO << "Add Category to repository";
}

//  Class member function
//  Add category to category repository
void FinanceRepository::AddCategory(const Category& category)
{
  category_repository_.Add(category);
  PLOG_INFO << "Add Category to repository";
}

//  Class member function
//  Add currency (default) to currency repository
void FinanceRepository::AddCurrency()
{
  currency_repository_.Add();
  PLOG_INFO << "Add Currency to repository";
}

//  Class member function
//  Add currency to currency repository
void FinanceRepository::AddCurrency(const Currency& currency)
{
  currency_repository_.Add(currency);
  PLOG_INFO << "Add Currency to repository";
}

//  Class member function
//  Add description (default) to description repository
void FinanceRepository::AddDescription()
{
  description_repository_.Add();
  PLOG_INFO << "Add Description to repository";
}

//  Class member function
//  Add description to description repository
void FinanceRepository::AddDescription(const Description& description)
{
  description_repository_.Add(description);
  PLOG_INFO << "Add Description to repository";
}

//  Class member function
//  Add payee (default) to payee repository
void FinanceRepository::AddPayee()
{
  payee_repository_.Add();
  PLOG_INFO << "Add Payee to repository";
}

//  Class member function
//  Add payee to payee repository
void FinanceRepository::AddPayee(const Payee& payee)
{
  payee_repository_.Add(payee);
  PLOG_INFO << "Add Payee to repository";
}

//  Class member function
//  Add comment (default) to comment repository
void FinanceRepository::AddComment()
{
  comment_repository_.Add();
  PLOG_INFO << "Add Comment to repository";
}

//  Class member function
//  Add comment to comment repository
void FinanceRepository::AddComment(const Comment& comment)
{
  comment_repository_.Add(comment);
  PLOG_INFO << "Add Comment to repository";
}

//  Class member function
//  Add tag (default) to tag repository
void FinanceRepository::AddTag()
{
  tag_repository_.Add();
  PLOG_INFO << "Add Tag to repository";
}

//  Class member function
//  Add tag to tag repository
void FinanceRepository::AddTag(const Tag& tag)
{
  tag_repository_.Add(tag);
  PLOG_INFO << "Add Tag to repository";
}

//  Class member function
//  Remove transaction (shared pointer) from transaction repository
void FinanceRepository::RemoveTransaction(std::shared_ptr<Transaction> transaction)
{
  transaction_repository_.Remove(transaction);
  PLOG_INFO << "Remove Transaction from repository";
}

//  Class member function
//  Remove account (shared pointer) from account repository
void FinanceRepository::RemoveAccount(std::shared_ptr<Account> account)
{
  account_repository_.Remove(account);
  PLOG_INFO << "Remove Account from repository";
}

//  Class member function
//  Remove category (shared pointer) from category repository
void FinanceRepository::RemoveCategory(std::shared_ptr<Category> category)
{
  category_repository_.Remove(category);
  PLOG_INFO << "Remove Category from repository";
}

//  Class member function
//  Remove currency (shared pointer) from currency repository
void FinanceRepository::RemoveCurrency(std::shared_ptr<Currency> currency)
{
  currency_repository_.Remove(currency);
  PLOG_INFO << "Remove Currency from repository";
}

//  Class member function
//  Remove description (shared pointer) from description repository
void FinanceRepository::RemoveDescription(std::shared_ptr<Description> description)
{
  description_repository_.Remove(description);
  PLOG_INFO << "Remove Description from repository";
}

//  Class member function
//  Remove payee (shared pointer) from payee repository
void FinanceRepository::RemovePayee(std::shared_ptr<Payee> payee)
{
  payee_repository_.Remove(payee);
  PLOG_INFO << "Remove Payee from repository";
}

//  Class member function
//  Remove comment (shared pointer) from comment repository
void FinanceRepository::RemoveComment(std::shared_ptr<Comment> comment)
{
  comment_repository_.Remove(comment);
  PLOG_INFO << "Remove Comment from repository";
}

//  Class member function
//  Remove tag (shared pointer) from tag repository
void FinanceRepository::RemoveTag(std::shared_ptr<Tag> tag)
{
  tag_repository_.Remove(tag);
  PLOG_INFO << "Remove Tag from repository";
}

//  Class member function
//  Get name of account from repository
std::string FinanceRepository::GetAccountName(AccountRepositoryIterator account) const
{
  return (**account).GetName();
}

//  Class member function
//  Get amount of account from repository
double FinanceRepository::GetAccountAmount(AccountRepositoryIterator account) const
{
  return (**account).GetAmount();
}

//  Class member function
//  Get name of category from repositor
std::string FinanceRepository::GetCategoryName(CategoryRepositoryIterator category) const
{
  return (**category).GetName();
}

//  Class member function
//  Get name of currency from repositor
std::string FinanceRepository::GetCurrencyName(CurrencyRepositoryIterator currency) const
{
  return (**currency).GetName();
}

//  Class member function
//  Get code of currency from repositor
std::string FinanceRepository::GetCurrencyCode(CurrencyRepositoryIterator currency) const
{
  return (**currency).GetCode();
}

//  Class member function
//  Get activity of currency from repositor
bool FinanceRepository::GetCurrencyActivity(CurrencyRepositoryIterator currency) const
{
  return (**currency).GetActivity();
}

//  Class member function
//  Get name of description from repositor
std::string FinanceRepository::GetDescriptionName(DescriptionRepositoryIterator description) const
{
  return (**description).GetName();
}

//  Class member function
//  Get name of payee from repository
std::string FinanceRepository::GetPayeeName(PayeeRepositoryIterator payee) const
{
  return (**payee).GetName();
}

//  Class member function
//  Get name of comment from repository
std::string FinanceRepository::GetCommentName(CommentRepositoryIterator comment) const
{
  return (**comment).GetName();
}

//  Class member function
//  Get name of tag from repository
std::string FinanceRepository::GetTagName(TagRepositoryIterator tag) const
{
  return (**tag).GetName();
}

//  Class member function
//  Set name of account from repository
void FinanceRepository::SetAccountName(AccountRepositoryIterator account, const std::string& name)
{
  (**account).SetName(name);
  PLOG_INFO << "Update name of Account in repository";
}

//  Class member function
//  Set amount of account from repository
void FinanceRepository::SetAccountAmount(AccountRepositoryIterator account, const double amount)
{
  (**account).SetAmount(amount);
  PLOG_INFO << "Update amount of Account in repository";
}

//  Class member function
//  Set name of category from repository
void FinanceRepository::SetCategoryName(CategoryRepositoryIterator category, const std::string& name)
{
  (**category).SetName(name);
  PLOG_INFO << "Update name of Category in repository";
}

//  Class member function
//  Set name of currency from repository
void FinanceRepository::SetCurrencyName(CurrencyRepositoryIterator currency, const std::string& name)
{
  (**currency).SetName(name);
  PLOG_INFO << "Update name of Currency in repository";
}

//  Class member function
//  Set code of currency from repository
void FinanceRepository::SetCurrencyCode(CurrencyRepositoryIterator currency, const std::string& code)
{
  (**currency).SetCode(code);
  PLOG_INFO << "Update code of Currency in repository";
}

//  Class member function
//  Set activity of currency from repository
void FinanceRepository::SetCurrencyActivity(CurrencyRepositoryIterator currency, const bool activity)
{
  (**currency).SetActivity(activity);
  PLOG_INFO << "Update activity of Currency in repository";
}

//  Class member function
//  Switch activity of currency from repository
void FinanceRepository::SwitchCurrencyActivity(CurrencyRepositoryIterator currency)
{
  (**currency).Switch();
  PLOG_INFO << "Switch activity of Currency in repository";
}

//  Class member function
//  Switch on activity of currency from repository
void FinanceRepository::SwitchOnCurrencyActivity(CurrencyRepositoryIterator currency)
{
  (**currency).SwitchOn();
  PLOG_INFO << "Switch on activity of Currency in repository";
}

//  Class member function
//  Switch off activity of currency from repository
void FinanceRepository::SwitchOffCurrencyActivity(CurrencyRepositoryIterator currency)
{
  (**currency).SwitchOff();
  PLOG_INFO << "Switch off activity of Currency in repository";
}

//  Class member function
//  Set name of description from repository
void FinanceRepository::SetDescriptionName(DescriptionRepositoryIterator description, const std::string& name)
{
  (**description).SetName(name);
  PLOG_INFO << "Update name of Description in repository";
}

//  Class member function
//  Set name of payee from repository
void FinanceRepository::SetPayeeName(PayeeRepositoryIterator payee, const std::string& name)
{
  (**payee).SetName(name);
  PLOG_INFO << "Update name of Payee in repository";
}

//  Class member function
//  Set name of comment from repository
void FinanceRepository::SetCommentName(CommentRepositoryIterator comment, const std::string& name)
{
  (**comment).SetName(name);
  PLOG_INFO << "Update name of Comment in repository";
}

//  Class member function
//  Set name of tag from repository
void FinanceRepository::SetTagName(TagRepositoryIterator tag, const std::string& name)
{
  (**tag).SetName(name);
  PLOG_INFO << "Update name of Tag in repository";
}

//  Class member function
//  Number of transactions in transaction repository
size_t FinanceRepository::GetTransactionsNumber() const
{
  return transaction_repository_.Size();
}

//  Class member function
//  Number of accounts in account repository
size_t FinanceRepository::GetAccountsNumber() const
{
  return account_repository_.Size();
}

//  Class member function
//  Number of categories in category repository
size_t FinanceRepository::GetCategoriesNumber() const
{
  return category_repository_.Size();
}

//  Class member function
//  Number of currencies in currency repository
size_t FinanceRepository::GetCurrenciesNumber() const
{
  return currency_repository_.Size();
}

//  Class member function
//  Number of descriptions in description repository
size_t FinanceRepository::GetDescriptionsNumber() const
{
  return description_repository_.Size();
}

//  Class member function
//  Number of payees in payee repository
size_t FinanceRepository::GetPayeesNumber() const
{
  return payee_repository_.Size();
}

//  Class member function
//  Number of comments in comment repository
size_t FinanceRepository::GetCommentsNumber() const
{
  return comment_repository_.Size();
}

//  Class member function
//  Number of tags in tag repository
size_t FinanceRepository::GetTagsNumber() const
{
  return tag_repository_.Size();
}

//  Class member function
//  Clear transaction repository
void FinanceRepository::ClearTransactions()
{
  transaction_repository_.Clear();
  PLOG_INFO << "Clear repository of Transactions";
}

//  Class member function
//  Clear account repository
void FinanceRepository::ClearAccounts()
{
  account_repository_.Clear();
  PLOG_INFO << "Clear repository of Accounts";
}

//  Class member function
//  Clear category repository
void FinanceRepository::ClearCategories()
{
  category_repository_.Clear();
  PLOG_INFO << "Clear repository of Categories";
}

//  Class member function
//  Clear currency repository
void FinanceRepository::ClearCurrencies()
{
  currency_repository_.Clear();
  PLOG_INFO << "Clear repository of Currencies";
}

//  Class member function
//  Clear description repository
void FinanceRepository::ClearDescriptions()
{
  description_repository_.Clear();
  PLOG_INFO << "Clear repository of Descriptions";
}

//  Class member function
//  Clear payee repository
void FinanceRepository::ClearPayees()
{
  payee_repository_.Clear();
  PLOG_INFO << "Clear repository of Payees";
}

//  Class member function
//  Clear comment repository
void FinanceRepository::ClearComments()
{
  comment_repository_.Clear();
  PLOG_INFO << "Clear repository of Comments";
}

//  Class member function
//  Clear tag repository
void FinanceRepository::ClearTags()
{
  tag_repository_.Clear();
  PLOG_INFO << "Clear repository of Tags";
}

//  Class member function
//  Print transaction repository
void FinanceRepository::PrintTransactions(const std::string& delimeter, std::ostream& output_stream) const
{
  auto i = BeginTransactionRepository();
  while (i != EndTransactionRepository())
  {
    output_stream << **i;
    ++i;
    if (i != EndTransactionRepository())
    {
      output_stream << delimeter;
    }
  }
}

//  Class member function
//  Print account repository
void FinanceRepository::PrintAccounts(const std::string& delimeter, std::ostream& output_stream) const
{
  auto i = BeginAccountRepository();
  while (i != EndAccountRepository())
  {
    output_stream << **i;
    ++i;
    if (i != EndAccountRepository())
    {
      output_stream << delimeter;
    }
  }
}

//  Class member function
//  Print category repository
void FinanceRepository::PrintCategories(const std::string& delimeter, std::ostream& output_stream) const
{
  auto i = BeginCategoryRepository();
  while (i != EndCategoryRepository())
  {
    output_stream << *i;
    ++i;
    if (i != EndCategoryRepository())
    {
      output_stream << delimeter;
    }
  }
}

//  Class member function
//  Print currency repository
void FinanceRepository::PrintCurrencies(const std::string& delimeter, std::ostream& output_stream) const
{
  auto i = BeginCurrencyRepository();
  while (i != EndCurrencyRepository())
  {
    output_stream << *i;
    ++i;
    if (i != EndCurrencyRepository())
    {
      output_stream << delimeter;
    }
  }
}

//  Class member function
//  Print description repository
void FinanceRepository::PrintDescriptions(const std::string& delimeter, std::ostream& output_stream) const
{
  auto i = BeginDescriptionRepository();
  while (i != EndDescriptionRepository())
  {
    output_stream << *i;
    ++i;
    if (i != EndDescriptionRepository())
    {
      output_stream << delimeter;
    }
  }
}

//  Class member function
//  Print payee repository
void FinanceRepository::PrintPayees(const std::string& delimeter, std::ostream& output_stream) const
{
  auto i = BeginPayeeRepository();
  while (i != EndPayeeRepository())
  {
    output_stream << *i;
    ++i;
    if (i != EndPayeeRepository())
    {
      output_stream << delimeter;
    }
  }
}

//  Class member function
//  Print comment repository
void FinanceRepository::PrintComments(const std::string& delimeter, std::ostream& output_stream) const
{
  auto i = BeginCommentRepository();
  while (i != EndCommentRepository())
  {
    output_stream << *i;
    ++i;
    if (i != EndCommentRepository())
    {
      output_stream << delimeter;
    }
  }
}

//  Class member function
//  Print tag repository
void FinanceRepository::PrintTags(const std::string& delimeter, std::ostream& output_stream) const
{
  auto i = BeginTagRepository();
  while (i != EndTagRepository())
  {
    output_stream << *i;
    ++i;
    if (i != EndTagRepository())
    {
      output_stream << delimeter;
    }
  }
}

//  Class member function
//  Find account with definite name in account repository
AccountRepositoryIterator FinanceRepository::FindAccount(std::string name) const
{
  return account_repository_.Find(name);
}

//  Class member function
//  Find account with definite amoune in account repository
AccountRepositoryIterator FinanceRepository::FindAccount(double amount) const
{
  return account_repository_.Find(amount);
}

//  Class member function
//  Find category with definite name in category repository
CategoryRepositoryIterator FinanceRepository::FindCategory(std::string name) const
{
  return category_repository_.Find(name);
}

//  Class member function
//  Find currency with definite name in category repository
CurrencyRepositoryIterator FinanceRepository::FindCurrencyName(std::string name) const
{
  return currency_repository_.FindName(name);
}

//  Class member function
//  Find currency with definite code in category repository
CurrencyRepositoryIterator FinanceRepository::FindCurrencyCode(std::string code) const
{
  return currency_repository_.FindCode(code);
}

//  Class member function
//  Find description with definite name in description repository
DescriptionRepositoryIterator FinanceRepository::FindDescription(std::string name) const
{
  return description_repository_.Find(name);
}

//  Class member function
//  Find payee with definite name in payee repository
PayeeRepositoryIterator FinanceRepository::FindPayee(std::string name) const
{
  return payee_repository_.Find(name);
}

//  Class member function
//  Find comment with definite name in comment repository
CommentRepositoryIterator FinanceRepository::FindComment(std::string name) const
{
  return comment_repository_.Find(name);
}

//  Class member function
//  Find tag with definite name in tag repository
TagRepositoryIterator FinanceRepository::FindTag(std::string name) const
{
  return tag_repository_.Find(name);
}

//  Class member function
//  Find transaction (shared pointer) in transaction repository
TransactionRepositoryIterator FinanceRepository::FindTransaction(std::shared_ptr<Transaction> transaction) const
{
  return transaction_repository_.Find(transaction);
}

//  Class member function
//  Find account (shared pointer) in account repository
AccountRepositoryIterator FinanceRepository::FindAccount(std::shared_ptr<Account> account) const
{
  return account_repository_.Find(account);
}

//  Class member function
//  Find category (shared pointer) in category repository
CategoryRepositoryIterator FinanceRepository::FindCategory(std::shared_ptr<Category> category) const
{
  return category_repository_.Find(category);
}

//  Class member function
//  Find currency (shared pointer) in currency repository
CurrencyRepositoryIterator FinanceRepository::FindCurrency(std::shared_ptr<Currency> currency) const
{
  return currency_repository_.Find(currency);
}

//  Class member function
//  Find description (shared pointer) in description repository
DescriptionRepositoryIterator FinanceRepository::FindDescription(std::shared_ptr<Description> description) const
{
  return description_repository_.Find(description);
}

//  Class member function
//  Find payee (shared pointer) in payee repository
PayeeRepositoryIterator FinanceRepository::FindPayee(std::shared_ptr<Payee> payee) const
{
  return payee_repository_.Find(payee);
}

//  Class member function
//  Find comment (shared pointer) in comment repository
CommentRepositoryIterator FinanceRepository::FindComment(std::shared_ptr<Comment> comment) const
{
  return comment_repository_.Find(comment);
}

//  Class member function
//  Find tag (shared pointer) in tag repository
TagRepositoryIterator FinanceRepository::FindTag(std::shared_ptr<Tag> tag) const
{
  return tag_repository_.Find(tag);
}

//  Class member function
//  Update last amount of account in account repository with adding new transaction
void FinanceRepository::UpdateAccountAmount(Transaction& transaction)
{
  if (transaction.GetType() == Type(kEnumType::Expense))
  {
    auto amount = transaction.GetAmountLastestAccountFrom() - transaction.GetAmount();
    transaction.SetAmountLastestAccountFrom(amount);
    PLOG_INFO << "Update Lastest Amount of Account From in repository";
    transaction.SetAmountLastestAccountTo(amount);
    PLOG_INFO << "Update Lastest Amount of Account To in repository";
    transaction.SetAmountAccountFrom(amount);
    PLOG_INFO << "Update Amount of Account From in repository";
    transaction.SetAmountAccountTo(amount);
    PLOG_INFO << "Update Amount of Account To in repository";
  }
  if (transaction.GetType() == Type(kEnumType::Income))
  {
    auto amount = transaction.GetAmountLastestAccountFrom() + transaction.GetAmount();
    transaction.SetAmountLastestAccountFrom(amount);
    PLOG_INFO << "Update Lastest Amount of Account From in repository";
    transaction.SetAmountLastestAccountTo(amount);
    PLOG_INFO << "Update Lastest Amount of Account To in repository";
    transaction.SetAmountAccountFrom(amount);
    PLOG_INFO << "Update Amount of Account From in repository";
    transaction.SetAmountAccountTo(amount);
    PLOG_INFO << "Update Amount of Account To in repository";
  }
  if (transaction.GetType() == Type(kEnumType::Transfer))
  {
    auto amount_from = transaction.GetAmountLastestAccountFrom() - transaction.GetAmount();
    transaction.SetAmountLastestAccountFrom(amount_from);
    PLOG_INFO << "Update Lastest Amount of Account From in repository";
    transaction.SetAmountAccountFrom(amount_from);
    PLOG_INFO << "Update Amount of Account From in repository";
    auto amount_to = transaction.GetAmountLastestAccountTo() + transaction.GetAmount();
    transaction.SetAmountLastestAccountTo(amount_to);
    PLOG_INFO << "Update Lastest Amount of Account To in repository";
    transaction.SetAmountAccountTo(amount_to);
    PLOG_INFO << "Update Amount of Account To in repository";
  }
}

//  Class member function
//  Update account repository with adding new transaction
void FinanceRepository::UpdateAccountRepository(Transaction& transaction)
{
  if (account_repository_.Size() == 0)
  {
    account_repository_.Add(transaction.GetAccountFromPtr());
  }
	else
  {
    bool keyFrom = false;
    for (auto i = account_repository_.Begin(); i != account_repository_.End(); ++i)
    {
      if ((**i).GetName() == transaction.GetAccountFrom().GetName())
      {
        keyFrom = true;
        transaction.SetAccountFromPtr(*i);
        break;
      }
    }
    if (!keyFrom)
    {
      account_repository_.Add(transaction.GetAccountFromPtr());
    }
    bool keyTo = false;
    for (auto i = account_repository_.Begin(); i != account_repository_.End(); ++i)
    {
      if ((**i).GetName() == transaction.GetAccountTo().GetName())
      {
        keyTo = true;
        transaction.SetAccountToPtr(*i);
        break;
      }
    }
    if (!keyTo)
    {
      account_repository_.Add(transaction.GetAccountToPtr());
    }
  }
}

//  Class member function
//  Update category repository with adding new transaction
void FinanceRepository::UpdateCategoryRepository(Transaction& transaction)
{
  if (category_repository_.Size() == 0)
  {
    category_repository_.Add(transaction.GetCategoryPtr());
  }
  else
  {
    bool keyFrom = false;
    for (auto i = category_repository_.Begin(); i != category_repository_.End(); ++i)
    {
      if ((**i).GetName() == transaction.GetCategory().GetName())
      {
        keyFrom = true;
        transaction.SetCategoryPtr(*i);
        break;
      }
    }
    if (!keyFrom)
    {
      category_repository_.Add(transaction.GetCategory());
    }
    bool keyTo = false;
    for (auto i = category_repository_.Begin(); i != category_repository_.End(); ++i)
    {
      if ((**i).GetName() == transaction.GetCategory().GetName())
      {
        keyTo = true;
        transaction.SetCategoryPtr(*i);
        break;
      }
    }
    if (!keyTo)
    {
      category_repository_.Add(transaction.GetCategoryPtr());
    }
  }
}

//  Class member function
//  Update currency repository with adding new transaction
void FinanceRepository::UpdateCurrencyRepository(Transaction& transaction)
{
  if (currency_repository_.Size() == 0)
  {
    currency_repository_.Add(transaction.GetCurrencyPtr());
  }
  else
  {
    bool keyFrom = false;
    for (auto i = currency_repository_.Begin(); i != currency_repository_.End(); ++i)
    {
      if ((**i).GetName() == transaction.GetCurrency().GetName())
      {
        keyFrom = true;
        transaction.SetCurrencyPtr(*i);
        break;
      }
    }
    if (!keyFrom)
    {
      currency_repository_.Add(transaction.GetCurrency());
    }
    bool keyTo = false;
    for (auto i = currency_repository_.Begin(); i != currency_repository_.End(); ++i)
    {
      if ((**i).GetName() == transaction.GetCurrency().GetName())
      {
        keyTo = true;
        transaction.SetCurrencyPtr(*i);
        break;
      }
    }
    if (!keyTo)
    {
      currency_repository_.Add(transaction.GetCurrencyPtr());
    }
  }
}

//  Class member function
//  Update description repository with adding new transaction
void FinanceRepository::UpdateDescriptionRepository(Transaction& transaction)
{
  if (description_repository_.Size() == 0)
  {
    description_repository_.Add(transaction.GetDescriptionPtr());
  }
  else
  {
    bool keyFrom = false;
    for (auto i = description_repository_.Begin(); i != description_repository_.End(); ++i)
    {
      if ((**i).GetName() == transaction.GetDescription().GetName())
      {
        keyFrom = true;
        transaction.SetDescriptionPtr(*i);
        break;
      }
    }
    if (!keyFrom)
    {
      description_repository_.Add(transaction.GetDescription());
    }
    bool keyTo = false;
    for (auto i = description_repository_.Begin(); i != description_repository_.End(); ++i)
    {
      if ((**i).GetName() == transaction.GetDescription().GetName())
      {
        keyTo = true;
        transaction.SetDescriptionPtr(*i);
        break;
      }
    }
    if (!keyTo)
    {
      description_repository_.Add(transaction.GetDescriptionPtr());
    }
  }
}

//  Class member function
//  Update payee repository with adding new transaction
void FinanceRepository::UpdatePayeeRepository(Transaction& transaction)
{
  if (payee_repository_.Size() == 0)
  {
    payee_repository_.Add(transaction.GetPayeePtr());
  }
  else
  {
    bool keyFrom = false;
    for (auto i = payee_repository_.Begin(); i != payee_repository_.End(); ++i)
    {
      if ((**i).GetName() == transaction.GetPayee().GetName())
      {
        keyFrom = true;
        transaction.SetPayeePtr(*i);
        break;
      }
    }
    if (!keyFrom)
    {
      payee_repository_.Add(transaction.GetPayee());
    }
    bool keyTo = false;
    for (auto i = payee_repository_.Begin(); i != payee_repository_.End(); ++i)
    {
      if ((**i).GetName() == transaction.GetPayee().GetName())
      {
        keyTo = true;
        transaction.SetPayeePtr(*i);
        break;
      }
    }
    if (!keyTo)
    {
      payee_repository_.Add(transaction.GetPayeePtr());
    }
  }
}

//  Class member function
//  Update comment repository with adding new transaction
void FinanceRepository::UpdateCommentRepository(Transaction& transaction)
{
  if (comment_repository_.Size() == 0)
  {
    comment_repository_.Add(transaction.GetCommentPtr());
  }
  else
  {
    bool keyFrom = false;
    for (auto i = comment_repository_.Begin(); i != comment_repository_.End(); ++i)
    {
      if ((**i).GetName() == transaction.GetComment().GetName())
      {
        keyFrom = true;
        transaction.SetCommentPtr(*i);
        break;
      }
    }
    if (!keyFrom)
    {
      comment_repository_.Add(transaction.GetComment());
    }
    bool keyTo = false;
    for (auto i = comment_repository_.Begin(); i != comment_repository_.End(); ++i)
    {
      if ((**i).GetName() == transaction.GetComment().GetName())
      {
        keyTo = true;
        transaction.SetCommentPtr(*i);
        break;
      }
    }
    if (!keyTo)
    {
      comment_repository_.Add(transaction.GetCommentPtr());
    }
  }
}

//  Class member function
//  Update tag repository with adding new transaction
void FinanceRepository::UpdateTagRepository(Transaction& transaction)
{
  if (tag_repository_.Size() == 0)
  {
    tag_repository_.Add(transaction.GetTagPtr());
  }
  else
  {
    bool keyFrom = false;
    for (auto i = tag_repository_.Begin(); i != tag_repository_.End(); ++i)
    {
      if ((**i).GetName() == transaction.GetTag().GetName())
      {
        keyFrom = true;
        transaction.SetTagPtr(*i);
        break;
      }
    }
    if (!keyFrom)
    {
      tag_repository_.Add(transaction.GetTag());
    }
    bool keyTo = false;
    for (auto i = tag_repository_.Begin(); i != tag_repository_.End(); ++i)
    {
      if ((**i).GetName() == transaction.GetTag().GetName())
      {
        keyTo = true;
        transaction.SetTagPtr(*i);
        break;
      }
    }
    if (!keyTo)
    {
      tag_repository_.Add(transaction.GetTagPtr());
    }
  }
}
