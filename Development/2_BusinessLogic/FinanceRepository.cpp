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
//  Add transaction to database
void FinanceRepository::AddTransaction(Transaction&& transaction)
{
  database_manager_->InsertTransactionToTableTransactionsInDatabase(std::move(transaction));
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
//  Remove transaction from database
void FinanceRepository::RemoveTransaction(const int id)
{
  database_manager_->RemoveTransactionFromTableTransactionsInDatabase(id);
}

//  Class member function
//  Remove account from database
void FinanceRepository::RemoveAccount(const std::string& name)
{
  database_manager_->RemoveAccountFromTableAccountsInDatabase(name);
}

//  Class member function
//  Remove category from database
void FinanceRepository::RemoveCategory(const std::string& name)
{
  database_manager_->RemoveCategoryFromTableCategoriesInDatabase(name);
}

//  Class member function
//  Remove currency from database
void FinanceRepository::RemoveCurrency(const std::string& name)
{
  database_manager_->RemoveCurrencyFromTableCurrenciesInDatabase(name);
}

//  Class member function
//  Remove description from database
void FinanceRepository::RemoveDescription(const std::string& name)
{
  database_manager_->RemoveDescriptionFromTableDescriptionsInDatabase(name);
}

//  Class member function
//  Remove payee from database
void FinanceRepository::RemovePayee(const std::string& name)
{
  database_manager_->RemovePayeeFromTablePayeesInDatabase(name);
}

//  Class member function
//  Remove comment from database
void FinanceRepository::RemoveComment(const std::string& name)
{
  database_manager_->RemoveCommentFromTableCommentsInDatabase(name);
}

//  Class member function
//  Remove tag from database
void FinanceRepository::RemoveTag(const std::string& name)
{
  database_manager_->RemoveTagFromTableTagsInDatabase(name);
}

//  Class member function
//  Get name of account from table 'Accounts' in database
std::string FinanceRepository::GetAccountName(const std::string& account_name)
{
  return database_manager_->GetAccountName(account_name);
}

//  Class member function
//  Get amount of account from table 'Accounts' in database
NUM FinanceRepository::GetAccountAmount(const std::string& account_name)
{
  return database_manager_->GetAccountAmount(account_name);
}

//  Class member function
//  Get name of category from table 'Categories' in database
std::string FinanceRepository::GetCategoryName(const std::string& category_name)
{
  return database_manager_->GetCategoryName(category_name);
}

//  Class member function
//  Get name of currency from table 'Currencies' in database
std::string FinanceRepository::GetCurrencyName(const std::string& currency_name)
{
  return database_manager_->GetCurrencyName(currency_name);
}

//  Class member function
//  Get code of currency from table 'Currencies' in database
std::string FinanceRepository::GetCurrencyCode(const std::string& currency_name)
{
  return database_manager_->GetCurrencyCode(currency_name);
}

//  Class member function
//  Get activity of currency from table 'Currencies' in database
bool FinanceRepository::GetCurrencyActivity(const std::string& currency_name)
{
  return database_manager_->GetCurrencyActivity(currency_name);
}

//  Class member function
//  Get name of description from table 'Descriptions' in database
std::string FinanceRepository::GetDescriptionName(const std::string& description_name)
{
  return database_manager_->GetDescriptionName(description_name);
}

//  Class member function
//  Get name of payee from table 'Payees' in database
std::string FinanceRepository::GetPayeeName(const std::string& payee_name)
{
  return database_manager_->GetPayeeName(payee_name);
}

//  Class member function
//  Get name of comment from table 'Comments' in database
std::string FinanceRepository::GetCommentName(const std::string& comment_name)
{
  return database_manager_->GetCommentName(comment_name);
}

//  Class member function
//  Get name of tag from table 'Tags' in database
std::string FinanceRepository::GetTagName(const std::string& tag_name)
{
  return database_manager_->GetTagName(tag_name);
}

//  Class member function
//  Set name of account in database
void FinanceRepository::SetAccountName(const std::string& account_name, const std::string& name)
{
  database_manager_->SetAccountName(account_name, name);
}

//  Class member function
//  Set amount of account in database
void FinanceRepository::SetAccountAmount(const std::string& account_name, const NUM amount)
{
  database_manager_->SetAccountAmount(account_name, amount);
}

//  Class member function
//  Set currency of account in database
void FinanceRepository::SetAccountCurrency(const std::string& account_name, Currency&& currency)
{
  database_manager_->SetAccountCurrency(account_name, std::move(currency));
}

//  Class member function
//  Set name of category from repository
void FinanceRepository::SetCategoryName(const std::string& category_name, const std::string& name)
{
  database_manager_->SetCategoryName(category_name, name);
}

//  Class member function
//  Set name of currency from repository
void FinanceRepository::SetCurrencyName(const std::string& currency_name, const std::string& name)
{
  database_manager_->SetCurrencyName(currency_name, name);
}

//  Class member function
//  Set code of currency from repository
void FinanceRepository::SetCurrencyCode(const std::string& currency_name, const std::string& code)
{
  database_manager_->SetCurrencyCode(currency_name, code);
}

//  Class member function
//  Set activity of currency from repository
void FinanceRepository::SetCurrencyActivity(const std::string& currency_name, const bool activity)
{
  database_manager_->SetCurrencyActivity(currency_name, activity);
}

//  Class member function
//  Switch activity of currency from repository
void FinanceRepository::SwitchCurrencyActivity(const std::string& currency_name)
{
  database_manager_->SwitchCurrencyActivity(currency_name);
}

//  Class member function
//  Switch on activity of currency from repository
void FinanceRepository::SwitchOnCurrencyActivity(const std::string& currency_name)
{
  database_manager_->SwitchOnCurrencyActivity(currency_name);
}

//  Class member function
//  Switch off activity of currency from repository
void FinanceRepository::SwitchOffCurrencyActivity(const std::string& currency_name)
{
  database_manager_->SwitchOffCurrencyActivity(currency_name);
}

//  Class member function
//  Set name of description from repository
void FinanceRepository::SetDescriptionName(const std::string& model_name, const std::string& name)
{
  database_manager_->SetDescriptionName(model_name, name);
}

//  Class member function
//  Set name of payee from repository
void FinanceRepository::SetPayeeName(const std::string& payee_name, const std::string& name)
{
  database_manager_->SetPayeeName(payee_name, name);
}

//  Class member function
//  Set name of comment from repository
void FinanceRepository::SetCommentName(const std::string& comment_name, const std::string& name)
{
  database_manager_->SetCommentName(comment_name, name);
}

//  Class member function
//  Set name of tag from repository
void FinanceRepository::SetTagName(const std::string& tag_name, const std::string& name)
{
  database_manager_->SetTagName(tag_name, name);
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
  database_manager_->ClearTableTransactionsInDatabase();
}

//  Class member function
//  Clear account repository
void FinanceRepository::ClearAccounts()
{
  database_manager_->ClearTableAccountsInDatabase();
}

//  Class member function
//  Clear category repository
void FinanceRepository::ClearCategories()
{
  database_manager_->ClearTableCategoriesInDatabase();
}

//  Class member function
//  Clear currency repository
void FinanceRepository::ClearCurrencies()
{
  database_manager_->ClearTableCurrenciesInDatabase();
}

//  Class member function
//  Clear description repository
void FinanceRepository::ClearDescriptions()
{
  database_manager_->ClearTableDescriptionsInDatabase();
}

//  Class member function
//  Clear payee repository
void FinanceRepository::ClearPayees()
{
  database_manager_->ClearTablePayeesInDatabase();
}

//  Class member function
//  Clear comment repository
void FinanceRepository::ClearComments()
{
  database_manager_->ClearTableCommentsInDatabase();
}

//  Class member function
//  Clear tag repository
void FinanceRepository::ClearTags()
{
  database_manager_->ClearTableTagsInDatabase();
}

//  Class member function
//  Find account with definite name in account repository
std::tuple<bool, int, Account> FinanceRepository::FindAccount(const std::string& name) const
{
  return database_manager_->FindAccountInTableAccountsInDatabase(name);
}

//  Class member function
//  Find category with definite name in category repository
std::tuple<bool, int, Category, int> FinanceRepository::FindCategory(const std::string& name) const
{
  return database_manager_->FindCategoryInTableCategoriesInDatabase(name);
}

//  Class member function
//  Find currency with definite name in category repository
std::tuple<bool, int, Currency> FinanceRepository::FindCurrency(const std::string& name) const
{
  return database_manager_->FindCurrencyInTableCurrenciesInDatabase(name);
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
  return database_manager_->FindDescriptionInTableDescriptionsInDatabase(name);
}

//  Class member function
//  Find payee with definite name in database
std::tuple<bool, int, Payee, int> FinanceRepository::FindPayee(const std::string& name) const
{
  return database_manager_->FindPayeeInTablePayeesInDatabase(name);
}

//  Class member function
//  Find comment with definite name in database
std::tuple<bool, int, Comment, int> FinanceRepository::FindComment(const std::string& name) const
{
  return database_manager_->FindCommentInTableCommentsInDatabase(name);
}

//  Class member function
//  Find tag with definite name in tag repository
std::tuple<bool, int, Tag, int> FinanceRepository::FindTag(const std::string& name) const
{
  return database_manager_->FindTagInTableTagsInDatabase(name);
}

//  Class member function
//  Calculate sum of today expenses
NUM FinanceRepository::SumExpensesToday() const
{
  NUM result = NUM(0.0);
  return result;
}

//  Class member function
//  Calculate sum of this month expenses
NUM FinanceRepository::SumExpensesThisMonth() const
{
  NUM result = NUM(0.0);
  return result;
}

//  Class member function
//  Calculate sum of all time expenses
NUM FinanceRepository::SumExpensesAllTime() const
{
  NUM result = NUM(0.0);
  return result;
}

//  Class member function
//  Calculate sum of today incomes
NUM FinanceRepository::SumIncomesToday() const
{
  NUM result = NUM(0.0);
  return result;
}

//  Class member function
//  Calculate sum of this month incomes
NUM FinanceRepository::SumIncomesThisMonth() const
{
  NUM result = NUM(0.0);
  return result;
}

//  Class member function
//  Calculate sum of all time incomes
NUM FinanceRepository::SumIncomesAllTime() const
{
  NUM result = NUM(0.0);
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
