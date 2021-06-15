#include "home_bookkeeping/2_BusinessLogic/FinanceRepository.h"

//  Constructor
//  Default
FinanceRepository::FinanceRepository()
{
  std::string file = "log_" + Time().GetStringTime() + ".txt";
  plog::init(plog::info, file.c_str());
  PLOG_INFO << "Logger init";
  database_manager_ = new DatabaseManager();
}

//  Destructor
//  Default
FinanceRepository::~FinanceRepository()
{
  delete database_manager_;
}

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
CategoryRepositoryConstIterator FinanceRepository::BeginCategoryRepository() const
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
DescriptionRepositoryConstIterator FinanceRepository::BeginDescriptionRepository() const
{
  return description_repository_.Begin();
}

//  Class member function
//  Find begin iterator of payee repository
PayeeRepositoryConstIterator FinanceRepository::BeginPayeeRepository() const
{
  return payee_repository_.Begin();
}

//  Class member function
//  Find begin iterator of comment repository
CommentRepositoryConstIterator FinanceRepository::BeginCommentRepository() const
{
  return comment_repository_.Begin();
}

//  Class member function
//  Find begin iterator of tag repository
TagRepositoryConstIterator FinanceRepository::BeginTagRepository() const
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
CategoryRepositoryConstIterator FinanceRepository::EndCategoryRepository() const
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
DescriptionRepositoryConstIterator FinanceRepository::EndDescriptionRepository() const
{
  return description_repository_.End();
}

//  Class member function
//  Find end iterator of payee repository
PayeeRepositoryConstIterator FinanceRepository::EndPayeeRepository() const
{
  return payee_repository_.End();
}

//  Class member function
//  Find end iterator of comment repository
CommentRepositoryConstIterator FinanceRepository::EndCommentRepository() const
{
  return comment_repository_.End();
}

//  Class member function
//  Find end iterator of tag repository
TagRepositoryConstIterator FinanceRepository::EndTagRepository() const
{
  return tag_repository_.End();
}

//  Class member function
//  Add transaction to database
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
  database_manager_->InsertAccountToTableAccountsInDatabase(std::move(transaction.GetAccountFrom()));
}

//  Class member function
//  Add account (default) to database
void FinanceRepository::AddAccount()
{
  database_manager_->InsertAccountToTableAccountsInDatabase(Account());
}

//  Class member function
//  Add account to database
void FinanceRepository::AddAccount(Account&& account)
{
  database_manager_->InsertAccountToTableAccountsInDatabase(std::move(account));
}

//  Class member function
//  Add accounts to database
void FinanceRepository::AddAccounts(AccountRepository&& accounts)
{
  database_manager_->InsertAccountsToTableAccountsInDatabase(std::move(accounts));
}

//  Class member function
//  Add category (default) to database
void FinanceRepository::AddCategory()
{
  database_manager_->InsertCategoryToTableCategoriesInDatabase(Category());
}

//  Class member function
//  Add category to database
void FinanceRepository::AddCategory(Category&& category)
{
  database_manager_->InsertCategoryToTableCategoriesInDatabase(std::move(category));
}

//  Class member function
//  Add categories to database
void FinanceRepository::AddCategories(CategoryRepository&& categories)
{
  database_manager_->InsertCategoriesToTableCategoriesInDatabase(std::move(categories));
}

//  Class member function
//  Add currency (default) to database
void FinanceRepository::AddCurrency()
{
  database_manager_->InsertCurrencyToTableCurrenciesInDatabase(Currency());
}

//  Class member function
//  Add currency to database
void FinanceRepository::AddCurrency(Currency&& currency)
{
  database_manager_->InsertCurrencyToTableCurrenciesInDatabase(std::move(currency));
}

//  Class member function
//  Add currencies to database
void FinanceRepository::AddCurrencies(CurrencyRepository&& currencies)
{
  database_manager_->InsertCurrenciesToTableCurrenciesInDatabase(std::move(currencies));
}

//  Class member function
//  Add description (default) to database
void FinanceRepository::AddDescription()
{
  database_manager_->InsertDescriptionToTableDescriptionsInDatabase(Description());
}

//  Class member function
//  Add description to database
void FinanceRepository::AddDescription(Description&& description)
{
  database_manager_->InsertDescriptionToTableDescriptionsInDatabase(std::move(description));
}

//  Class member function
//  Add descriptions to database
void FinanceRepository::AddDescriptions(DescriptionRepository&& descriptions)
{
  database_manager_->InsertDescriptionsToTableDescriptionsInDatabase(std::move(descriptions));
}

//  Class member function
//  Add payee (default) to database
void FinanceRepository::AddPayee()
{
  database_manager_->InsertPayeeToTablePayeesInDatabase(Payee());
}

//  Class member function
//  Add payee to database
void FinanceRepository::AddPayee(Payee&& payee)
{
  database_manager_->InsertPayeeToTablePayeesInDatabase(std::move(payee));
}

//  Class member function
//  Add payees to database
void FinanceRepository::AddPayees(PayeeRepository&& payees)
{
  database_manager_->InsertPayeesToTablePayeesInDatabase(std::move(payees));
}

//  Class member function
//  Add comment (default) to database
void FinanceRepository::AddComment()
{
  database_manager_->InsertCommentToTableCommentsInDatabase(Comment());
}

//  Class member function
//  Add comment to database
void FinanceRepository::AddComment(Comment&& comment)
{
  database_manager_->InsertCommentToTableCommentsInDatabase(std::move(comment));
}

//  Class member function
//  Add comments to database
void FinanceRepository::AddComments(CommentRepository&& comments)
{
  database_manager_->InsertCommentsToTableCommentsInDatabase(std::move(comments));
}

//  Class member function
//  Add tag (default) to database
void FinanceRepository::AddTag()
{
  database_manager_->InsertTagToTableTagsInDatabase(Tag());
}

//  Class member function
//  Add tag to database
void FinanceRepository::AddTag(Tag&& tag)
{
  database_manager_->InsertTagToTableTagsInDatabase(std::move(tag));
}

//  Class member function
//  Add tags to database
void FinanceRepository::AddTags(TagRepository&& tags)
{
  database_manager_->InsertTagsToTableTagsInDatabase(std::move(tags));
}

//  Class member function
//  Remove transaction (shared pointer) from transaction repository
void FinanceRepository::RemoveTransaction(std::shared_ptr<Transaction> transaction)
{
  
}

//  Class member function
//  Remove account (shared pointer) from account repository
void FinanceRepository::RemoveAccount(std::shared_ptr<Account> account)
{

}

//  Class member function
//  Remove category (shared pointer) from category repository
void FinanceRepository::RemoveCategory(std::shared_ptr<Category> category)
{

}

//  Class member function
//  Remove currency (shared pointer) from currency repository
void FinanceRepository::RemoveCurrency(std::shared_ptr<Currency> currency)
{

}

//  Class member function
//  Remove description (shared pointer) from description repository
void FinanceRepository::RemoveDescription(std::shared_ptr<Description> description)
{

}

//  Class member function
//  Remove payee (shared pointer) from payee repository
void FinanceRepository::RemovePayee(std::shared_ptr<Payee> payee)
{

}

//  Class member function
//  Remove comment (shared pointer) from comment repository
void FinanceRepository::RemoveComment(std::shared_ptr<Comment> comment)
{

}

//  Class member function
//  Remove tag (shared pointer) from tag repository
void FinanceRepository::RemoveTag(std::shared_ptr<Tag> tag)
{

}

//  Class member function
//  Get name of account from repository
std::string FinanceRepository::GetAccountName(AccountRepositoryIterator account) const
{
  return (**account).GetName();
}

//  Class member function
//  Get amount of account from repository
NUM FinanceRepository::GetAccountAmount(AccountRepositoryIterator account) const
{
  return (**account).GetAmount();
}

//  Class member function
//  Get name of category from repositor
std::string FinanceRepository::GetCategoryName(CategoryRepositoryIterator category) const
{
  return category->first->GetName();
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
  return description->first->GetName();
}

//  Class member function
//  Get name of payee from repository
std::string FinanceRepository::GetPayeeName(PayeeRepositoryIterator payee) const
{
  return payee->first->GetName();
}

//  Class member function
//  Get name of comment from repository
std::string FinanceRepository::GetCommentName(CommentRepositoryIterator comment) const
{
  return comment->first->GetName();
}

//  Class member function
//  Get name of tag from repository
std::string FinanceRepository::GetTagName(TagRepositoryIterator tag) const
{
  return tag->first->GetName();
}

//  Class member function
//  Set name of account in database
void FinanceRepository::SetAccountName(const std::string& account_name, const std::string& name)
{
  database_manager_->FindAccountByNameInTableAccountsInDatabaseUpdateName(account_name, name);
}

//  Class member function
//  Set amount of account in database
void FinanceRepository::SetAccountAmount(const std::string& account_name, const double amount)
{
  database_manager_->FindAccountByNameInTableAccountsInDatabaseUpdateAmount(account_name, amount);
}

//  Class member function
//  Set currency of account in database
void FinanceRepository::SetAccountCurrency(const std::string& account_name, Currency&& currency)
{
  database_manager_->FindAccountByNameInTableAccountsInDatabaseUpdateCurrency(account_name, std::move(currency));
}

//  Class member function
//  Set name of category from repository
void FinanceRepository::SetCategoryName(const std::string& category_name, const std::string& name)
{
  database_manager_->FindCategoryByNameInTableCategoriesInDatabaseUpdateName(category_name, name);
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
  description->first->SetName(name);
  PLOG_INFO << "Update name of Description in repository";
}

//  Class member function
//  Set name of payee from repository
void FinanceRepository::SetPayeeName(const std::string& payee_name, const std::string& name)
{
  database_manager_->FindPayeeByNameInTablePayeesInDatabaseUpdateName(payee_name, name);
}

//  Class member function
//  Set name of comment from repository
void FinanceRepository::SetCommentName(CommentRepositoryIterator comment, const std::string& name)
{
  comment->first->SetName(name);
  PLOG_INFO << "Update name of Comment in repository";
}

//  Class member function
//  Set name of tag from repository
void FinanceRepository::SetTagName(const std::string& tag_name, const std::string& name)
{
  database_manager_->FindTagByNameInTableTagsInDatabaseUpdateName(tag_name, name);
}

//  Class member function
//  Number of transactions in transaction repository
size_t FinanceRepository::GetTransactionsNumber() const
{
  return database_manager_->SizeOfTable("Transactions");
}

//  Class member function
//  Number of accounts in account repository
size_t FinanceRepository::GetAccountsNumber() const
{
  return database_manager_->SizeOfTable("Accounts");
}

//  Class member function
//  Number of categories in category repository
size_t FinanceRepository::GetCategoriesNumber() const
{
  return database_manager_->SizeOfTable("Categories");
}

//  Class member function
//  Number of currencies in currency repository
size_t FinanceRepository::GetCurrenciesNumber() const
{
  return database_manager_->SizeOfTable("Currencies");
}

//  Class member function
//  Number of descriptions in description repository
size_t FinanceRepository::GetDescriptionsNumber() const
{
  return database_manager_->SizeOfTable("Descriptions");
}

//  Class member function
//  Number of payees in payee repository
size_t FinanceRepository::GetPayeesNumber() const
{
  return database_manager_->SizeOfTable("Payees");
}

//  Class member function
//  Number of comments in comment repository
size_t FinanceRepository::GetCommentsNumber() const
{
  return database_manager_->SizeOfTable("Comments");
}

//  Class member function
//  Number of tags in tag repository
size_t FinanceRepository::GetTagsNumber() const
{
  return database_manager_->SizeOfTable("Tags");
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
    output_stream << i->first;
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
    output_stream << i->first;
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
    output_stream << i->first;
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
    output_stream << i->first;
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
    output_stream << i->first;
    ++i;
    if (i != EndTagRepository())
    {
      output_stream << delimeter;
    }
  }
}

//  Class member function
//  Find account with definite name in account repository
std::tuple<bool, int, Account> FinanceRepository::FindAccount(const std::string& name) const
{
  return database_manager_->FindAccountByNameInTableAccountsInDatabase(name);
}

//  Class member function
//  Find category with definite name in category repository
std::tuple<bool, int, Category, int> FinanceRepository::FindCategory(const std::string& name) const
{
  return database_manager_->FindCategoryByNameInTableCategoriesInDatabase(name);
}

//  Class member function
//  Find currency with definite name in category repository
std::tuple<bool, int, Currency> FinanceRepository::FindCurrencyByName(const std::string& name) const
{
  return database_manager_->FindCurrencyByNameInTableCurrenciesInDatabase(name);
}

//  Class member function
//  Find currency with definite code in category repository
std::tuple<bool, int, Currency> FinanceRepository::FindCurrencyByCode(const std::string& code) const
{
  return database_manager_->FindCurrencyByCodeInTableCurrenciesInDatabase(code);
}

//  Class member function
//  Find description with definite name in database
std::tuple<bool, int, Description, int> FinanceRepository::FindDescription(const std::string& name) const
{
  return database_manager_->FindDescriptionByNameInTableDescriptionsInDatabase(name);
}

//  Class member function
//  Find payee with definite name in database
std::tuple<bool, int, Payee, int> FinanceRepository::FindPayee(const std::string& name) const
{
  return database_manager_->FindPayeeByNameInTablePayeesInDatabase(name);
}

//  Class member function
//  Find comment with definite name in database
std::tuple<bool, int, Comment, int> FinanceRepository::FindComment(const std::string& name) const
{
  return database_manager_->FindCommentByNameInTableCommentsInDatabase(name);
}

//  Class member function
//  Find tag with definite name in tag repository
std::tuple<bool, int, Tag, int> FinanceRepository::FindTag(const std::string& name) const
{
  return database_manager_->FindTagByNameInTableTagsInDatabase(name);
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
  category_repository_.Add(transaction.GetCategoryPtr());
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
  description_repository_.Add(transaction.GetDescriptionPtr());
}

//  Class member function
//  Update payee repository with adding new transaction
void FinanceRepository::UpdatePayeeRepository(Transaction& transaction)
{
  payee_repository_.Add(transaction.GetPayeePtr());
}

//  Class member function
//  Update comment repository with adding new transaction
void FinanceRepository::UpdateCommentRepository(Transaction& transaction)
{
  comment_repository_.Add(transaction.GetCommentPtr());
}

//  Class member function
//  Update tag repository with adding new transaction
void FinanceRepository::UpdateTagRepository(Transaction& transaction)
{
  tag_repository_.Add(transaction.GetTagPtr());
}

//  Class member function
//  Calculate sum of today expenses
NUM FinanceRepository::SumExpensesToday() const
{
  NUM result = NUM(0.0);
  for (auto i = BeginTransactionRepository(); i != EndTransactionRepository(); ++i)
  {
    if ((**i).GetType().GetType() == kEnumType::Expense &&
      (**i).GetTime().GetDay() == Time().GetDay() &&
      (**i).GetTime().GetMonth() == Time().GetMonth() &&
      (**i).GetTime().GetYear() == Time().GetYear())
    {
      result += (**i).GetAmount();
    }
  }
  return result;
}

//  Class member function
//  Calculate sum of this month expenses
NUM FinanceRepository::SumExpensesThisMonth() const
{
  NUM result = NUM(0.0);
  for (auto i = BeginTransactionRepository(); i != EndTransactionRepository(); ++i)
  {
    if ((**i).GetType().GetType() == kEnumType::Expense &&
      (**i).GetTime().GetMonth() == Time().GetMonth() &&
      (**i).GetTime().GetYear() == Time().GetYear())
    {
      result += (**i).GetAmount();
    }
  }
  return result;
}

//  Class member function
//  Calculate sum of all time expenses
NUM FinanceRepository::SumExpensesAllTime() const
{
  NUM result = NUM(0.0);
  for (auto i = BeginTransactionRepository(); i != EndTransactionRepository(); ++i)
  {
    if ((**i).GetType().GetType() == kEnumType::Expense)
    {
      result += (**i).GetAmount();
    }
  }
  return result;
}

//  Class member function
//  Calculate sum of today incomes
NUM FinanceRepository::SumIncomesToday() const
{
  NUM result = NUM(0.0);
  for (auto i = BeginTransactionRepository(); i != EndTransactionRepository(); ++i)
  {
    if ((**i).GetType().GetType() == kEnumType::Income &&
      (**i).GetTime().GetDay() == Time().GetDay() &&
      (**i).GetTime().GetMonth() == Time().GetMonth() &&
      (**i).GetTime().GetYear() == Time().GetYear())
    {
      result += (**i).GetAmount();
    }
  }
  return result;
}

//  Class member function
//  Calculate sum of this month incomes
NUM FinanceRepository::SumIncomesThisMonth() const
{
  NUM result = NUM(0.0);
  for (auto i = BeginTransactionRepository(); i != EndTransactionRepository(); ++i)
  {
    if ((**i).GetType().GetType() == kEnumType::Income &&
      (**i).GetTime().GetMonth() == Time().GetMonth() &&
      (**i).GetTime().GetYear() == Time().GetYear())
    {
      result += (**i).GetAmount();
    }
  }
  return result;
}

//  Class member function
//  Calculate sum of all time incomes
NUM FinanceRepository::SumIncomesAllTime() const
{
  NUM result = NUM(0.0);
  for (auto i = BeginTransactionRepository(); i != EndTransactionRepository(); ++i)
  {
    if ((**i).GetType().GetType() == kEnumType::Income)
    {
      result += (**i).GetAmount();
    }
  }
  return result;
}

//  Class member function
//  Add default accounts to account repository
void FinanceRepository::AddDefaultAccounts()
{
  AddAccount({ "BYN Cash" });
  AddAccount({ "BYN Card" });
  AddAccount({ "USD Card" });
  AddAccount({ "USD Cash" });
  PLOG_INFO << "Add to repository of Accounts default Accounts";
}

//  Class member function
//  Add default categories to category repository
void FinanceRepository::AddDefaultCategories()
{
  AddCategory({ "Bills" });
  AddCategory({ "Financial Expenses" });
  AddCategory({ "Housing" });
  AddCategory({ "Food & Dining" });
  AddCategory({ "Life" });
  AddCategory({ "Transportation" });
  AddCategory({ "Vehicle" });
  AddCategory({ "Shopping" });
  PLOG_INFO << "Add to repository of Categories default Categories";
}

//  Class member function
//  Add default currencies to currency repository
void FinanceRepository::AddDefaultCurrencies()
{
  AddCurrency({ "BYN", "BYN", true });
  AddCurrency({ "USD", "USD", false });
  AddCurrency({ "EURO", "EURO", false });
  PLOG_INFO << "Add to repository of Currencies default Currencies";
}

//  Class member function
//  Clear tables in database
void FinanceRepository::ClearTablesInDatabase()
{
  database_manager_->ClearAllTablesInDatabase();
}
