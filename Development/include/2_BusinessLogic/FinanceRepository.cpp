#include "include/2_BusinessLogic/FinanceRepository.h"

FinanceRepository::FinanceRepository()
{
  std::string file = "log_" + TimeDate().GetStringTime() + ".txt";
  plog::init(plog::info, file.c_str());
  PLOG_INFO << "Logger init";
  database_manager_ = new DatabaseManager();
}

FinanceRepository::~FinanceRepository()
{
  delete database_manager_;
}

void FinanceRepository::AddTransaction(Transaction&& transaction)
{
  database_manager_->InsertTransactionToTableTransactionsInDatabase(std::move(transaction));
}

void FinanceRepository::AddAccount()
{
  database_manager_->InsertAccountToTableAccountsInDatabase(Account());
}

void FinanceRepository::AddAccount(Account&& account)
{
  database_manager_->InsertAccountToTableAccountsInDatabase(std::move(account));
}

void FinanceRepository::AddAccounts(AccountRepository&& accounts)
{
  database_manager_->InsertAccountsToTableAccountsInDatabase(std::move(accounts));
}

void FinanceRepository::AddCategory()
{
  database_manager_->InsertCategoryToTableCategoriesInDatabase(Category());
}

void FinanceRepository::AddCategory(Category&& category)
{
  database_manager_->InsertCategoryToTableCategoriesInDatabase(std::move(category));
}

void FinanceRepository::AddCategories(CategoryRepository&& categories)
{
  database_manager_->InsertCategoriesToTableCategoriesInDatabase(std::move(categories));
}

void FinanceRepository::AddCurrency()
{
  database_manager_->InsertCurrencyToTableCurrenciesInDatabase(Currency());
}

void FinanceRepository::AddCurrency(Currency&& currency)
{
  database_manager_->InsertCurrencyToTableCurrenciesInDatabase(std::move(currency));
}

void FinanceRepository::AddCurrencies(CurrencyRepository&& currencies)
{
  database_manager_->InsertCurrenciesToTableCurrenciesInDatabase(std::move(currencies));
}

void FinanceRepository::AddDescription()
{
  database_manager_->InsertDescriptionToTableDescriptionsInDatabase(Description());
}

void FinanceRepository::AddDescription(Description&& description)
{
  database_manager_->InsertDescriptionToTableDescriptionsInDatabase(std::move(description));
}

void FinanceRepository::AddDescriptions(DescriptionRepository&& descriptions)
{
  database_manager_->InsertDescriptionsToTableDescriptionsInDatabase(std::move(descriptions));
}

void FinanceRepository::AddPayee()
{
  database_manager_->InsertPayeeToTablePayeesInDatabase(Payee());
}

void FinanceRepository::AddPayee(Payee&& payee)
{
  database_manager_->InsertPayeeToTablePayeesInDatabase(std::move(payee));
}

void FinanceRepository::AddPayees(PayeeRepository&& payees)
{
  database_manager_->InsertPayeesToTablePayeesInDatabase(std::move(payees));
}

void FinanceRepository::AddComment()
{
  database_manager_->InsertCommentToTableCommentsInDatabase(Comment());
}

void FinanceRepository::AddComment(Comment&& comment)
{
  database_manager_->InsertCommentToTableCommentsInDatabase(std::move(comment));
}

void FinanceRepository::AddComments(CommentRepository&& comments)
{
  database_manager_->InsertCommentsToTableCommentsInDatabase(std::move(comments));
}

void FinanceRepository::AddTag()
{
  database_manager_->InsertTagToTableTagsInDatabase(Tag());
}

void FinanceRepository::AddTag(Tag&& tag)
{
  database_manager_->InsertTagToTableTagsInDatabase(std::move(tag));
}

void FinanceRepository::AddTags(TagRepository&& tags)
{
  database_manager_->InsertTagsToTableTagsInDatabase(std::move(tags));
}

void FinanceRepository::RemoveTransaction(const int id)
{
  database_manager_->RemoveTransactionFromTableTransactionsInDatabase(id);
}

void FinanceRepository::RemoveAccount(const std::string& name)
{
  database_manager_->RemoveAccountFromTableAccountsInDatabase(name);
}

void FinanceRepository::RemoveCategory(const std::string& name)
{
  database_manager_->RemoveCategoryFromTableCategoriesInDatabase(name);
}

void FinanceRepository::RemoveCurrency(const std::string& name)
{
  database_manager_->RemoveCurrencyFromTableCurrenciesInDatabase(name);
}

void FinanceRepository::RemoveDescription(const std::string& name)
{
  database_manager_->RemoveDescriptionFromTableDescriptionsInDatabase(name);
}

void FinanceRepository::RemovePayee(const std::string& name)
{
  database_manager_->RemovePayeeFromTablePayeesInDatabase(name);
}

void FinanceRepository::RemoveComment(const std::string& name)
{
  database_manager_->RemoveCommentFromTableCommentsInDatabase(name);
}

void FinanceRepository::RemoveTag(const std::string& name)
{
  database_manager_->RemoveTagFromTableTagsInDatabase(name);
}

std::string FinanceRepository::GetAccountName(const std::string& account_name)
{
  return database_manager_->GetAccountName(account_name);
}

NUM FinanceRepository::GetAccountAmount(const std::string& account_name)
{
  return database_manager_->GetAccountAmount(account_name);
}

std::string FinanceRepository::GetCategoryName(const std::string& category_name)
{
  return database_manager_->GetCategoryName(category_name);
}

std::string FinanceRepository::GetCurrencyName(const std::string& currency_name)
{
  return database_manager_->GetCurrencyName(currency_name);
}

std::string FinanceRepository::GetCurrencyCode(const std::string& currency_name)
{
  return database_manager_->GetCurrencyCode(currency_name);
}

bool FinanceRepository::GetCurrencyActivity(const std::string& currency_name)
{
  return database_manager_->GetCurrencyActivity(currency_name);
}

std::string FinanceRepository::GetDescriptionName(const std::string& description_name)
{
  return database_manager_->GetDescriptionName(description_name);
}

std::string FinanceRepository::GetPayeeName(const std::string& payee_name)
{
  return database_manager_->GetPayeeName(payee_name);
}

std::string FinanceRepository::GetCommentName(const std::string& comment_name)
{
  return database_manager_->GetCommentName(comment_name);
}

std::string FinanceRepository::GetTagName(const std::string& tag_name)
{
  return database_manager_->GetTagName(tag_name);
}

void FinanceRepository::SetAccountName(const std::string& account_name, const std::string& name)
{
  database_manager_->SetAccountName(account_name, name);
}

void FinanceRepository::SetAccountAmount(const std::string& account_name, const NUM amount)
{
  database_manager_->SetAccountAmount(account_name, amount);
}

void FinanceRepository::SetAccountCurrency(const std::string& account_name, Currency&& currency)
{
  database_manager_->SetAccountCurrency(account_name, std::move(currency));
}

void FinanceRepository::SetCategoryName(const std::string& category_name, const std::string& name)
{
  database_manager_->SetCategoryName(category_name, name);
}

void FinanceRepository::SetCurrencyName(const std::string& currency_name, const std::string& name)
{
  database_manager_->SetCurrencyName(currency_name, name);
}

void FinanceRepository::SetCurrencyCode(const std::string& currency_name, const std::string& code)
{
  database_manager_->SetCurrencyCode(currency_name, code);
}

void FinanceRepository::SetCurrencyActivity(const std::string& currency_name, const bool activity)
{
  database_manager_->SetCurrencyActivity(currency_name, activity);
}

void FinanceRepository::SwitchCurrencyActivity(const std::string& currency_name)
{
  database_manager_->SwitchCurrencyActivity(currency_name);
}

void FinanceRepository::SwitchOnCurrencyActivity(const std::string& currency_name)
{
  database_manager_->SwitchOnCurrencyActivity(currency_name);
}

void FinanceRepository::SwitchOffCurrencyActivity(const std::string& currency_name)
{
  database_manager_->SwitchOffCurrencyActivity(currency_name);
}

void FinanceRepository::SetDescriptionName(const std::string& model_name, const std::string& name)
{
  database_manager_->SetDescriptionName(model_name, name);
}

void FinanceRepository::SetPayeeName(const std::string& payee_name, const std::string& name)
{
  database_manager_->SetPayeeName(payee_name, name);
}

void FinanceRepository::SetCommentName(const std::string& comment_name, const std::string& name)
{
  database_manager_->SetCommentName(comment_name, name);
}

void FinanceRepository::SetTagName(const std::string& tag_name, const std::string& name)
{
  database_manager_->SetTagName(tag_name, name);
}

size_t FinanceRepository::GetTransactionsNumber() const
{
  return database_manager_->SizeOfTable("Transactions");
}

size_t FinanceRepository::GetAccountsNumber() const
{
  return database_manager_->SizeOfTable("Accounts");
}

size_t FinanceRepository::GetCategoriesNumber() const
{
  return database_manager_->SizeOfTable("Categories");
}

size_t FinanceRepository::GetCurrenciesNumber() const
{
  return database_manager_->SizeOfTable("Currencies");
}

size_t FinanceRepository::GetDescriptionsNumber() const
{
  return database_manager_->SizeOfTable("Descriptions");
}

size_t FinanceRepository::GetPayeesNumber() const
{
  return database_manager_->SizeOfTable("Payees");
}

size_t FinanceRepository::GetCommentsNumber() const
{
  return database_manager_->SizeOfTable("Comments");
}

size_t FinanceRepository::GetTagsNumber() const
{
  return database_manager_->SizeOfTable("Tags");
}

void FinanceRepository::ClearTransactions()
{
  database_manager_->ClearTableTransactionsInDatabase();
}

void FinanceRepository::ClearAccounts()
{
  database_manager_->ClearTableAccountsInDatabase();
}

void FinanceRepository::ClearCategories()
{
  database_manager_->ClearTableCategoriesInDatabase();
}

void FinanceRepository::ClearCurrencies()
{
  database_manager_->ClearTableCurrenciesInDatabase();
}

void FinanceRepository::ClearDescriptions()
{
  database_manager_->ClearTableDescriptionsInDatabase();
}

void FinanceRepository::ClearPayees()
{
  database_manager_->ClearTablePayeesInDatabase();
}

void FinanceRepository::ClearComments()
{
  database_manager_->ClearTableCommentsInDatabase();
}

void FinanceRepository::ClearTags()
{
  database_manager_->ClearTableTagsInDatabase();
}

std::tuple<bool, int, Account> FinanceRepository::FindAccount(const std::string& name) const
{
  return database_manager_->FindAccountInTableAccountsInDatabase(name);
}

std::tuple<bool, int, Category, int> FinanceRepository::FindCategory(const std::string& name) const
{
  return database_manager_->FindCategoryInTableCategoriesInDatabase(name);
}

std::tuple<bool, int, Currency> FinanceRepository::FindCurrency(const std::string& name) const
{
  return database_manager_->FindCurrencyInTableCurrenciesInDatabase(name);
}

std::tuple<bool, int, Currency> FinanceRepository::FindCurrencyByCode(const std::string& code) const
{
  return database_manager_->FindCurrencyByCodeInTableCurrenciesInDatabase(code);
}

std::tuple<bool, int, Description, int> FinanceRepository::FindDescription(const std::string& name) const
{
  return database_manager_->FindDescriptionInTableDescriptionsInDatabase(name);
}

std::tuple<bool, int, Payee, int> FinanceRepository::FindPayee(const std::string& name) const
{
  return database_manager_->FindPayeeInTablePayeesInDatabase(name);
}

std::tuple<bool, int, Comment, int> FinanceRepository::FindComment(const std::string& name) const
{
  return database_manager_->FindCommentInTableCommentsInDatabase(name);
}

std::tuple<bool, int, Tag, int> FinanceRepository::FindTag(const std::string& name) const
{
  return database_manager_->FindTagInTableTagsInDatabase(name);
}

NUM FinanceRepository::SumExpensesToday() const
{
  NUM result = NUM(0.0);
  return result;
}

NUM FinanceRepository::SumExpensesThisMonth() const
{
  NUM result = NUM(0.0);
  return result;
}

NUM FinanceRepository::SumExpensesAllTime() const
{
  NUM result = NUM(0.0);
  return result;
}

NUM FinanceRepository::SumIncomesToday() const
{
  NUM result = NUM(0.0);
  return result;
}

NUM FinanceRepository::SumIncomesThisMonth() const
{
  NUM result = NUM(0.0);
  return result;
}

NUM FinanceRepository::SumIncomesAllTime() const
{
  NUM result = NUM(0.0);
  return result;
}

void FinanceRepository::AddDefaultAccounts()
{
  AddAccount({ "BYN Cash" });
  AddAccount({ "BYN Card" });
  AddAccount({ "USD Card" });
  AddAccount({ "USD Cash" });
  PLOG_INFO << "Add to repository of Accounts default Accounts";
}

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

void FinanceRepository::AddDefaultCurrencies()
{
  AddCurrency({ "BYN", "BYN", true });
  AddCurrency({ "USD", "USD", false });
  AddCurrency({ "EURO", "EURO", false });
  PLOG_INFO << "Add to repository of Currencies default Currencies";
}

void FinanceRepository::ClearTablesInDatabase()
{
  database_manager_->ClearAllTablesInDatabase();
}
