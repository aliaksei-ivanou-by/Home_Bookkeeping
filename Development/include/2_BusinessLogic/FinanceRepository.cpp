#include "include/2_BusinessLogic/FinanceRepository.h"

FinanceRepository::FinanceRepository()
{
  std::string file = "log_" + TimeDate().GetStringTime() + ".txt";
  plog::init(plog::info, file.c_str());
  PLOG_INFO << "Logger init";
  database_manager_ = new DatabaseManager();
  currency_database_ = new CurrencyDatabase(database_manager_);
  account_database_ = new AccountDatabase(database_manager_, currency_database_);
  category_database_ = new CategoryDatabase(database_manager_);
  comment_database_ = new CommentDatabase(database_manager_);
  description_database_ = new DescriptionDatabase(database_manager_);
  payee_database_ = new PayeeDatabase(database_manager_);
  tag_database_ = new TagDatabase(database_manager_);
}

FinanceRepository::~FinanceRepository()
{
  delete database_manager_;
  delete account_database_;
  delete category_database_;
  delete currency_database_;
  delete comment_database_;
  delete description_database_;
  delete payee_database_;
  delete tag_database_;
}

void FinanceRepository::AddTransaction(Transaction&& transaction)
{
  database_manager_->InsertTransactionToTableTransactionsInDatabase(std::move(transaction));
}

void FinanceRepository::AddAccount()
{
  account_database_->InsertAccountToTableAccountsInDatabase(Account());
}

void FinanceRepository::AddAccount(Account&& account)
{
  account_database_->InsertAccountToTableAccountsInDatabase(std::move(account));
}

void FinanceRepository::AddAccounts(AccountRepository&& accounts)
{
  account_database_->InsertAccountsToTableAccountsInDatabase(std::move(accounts));
}

void FinanceRepository::AddCategory()
{
  category_database_->InsertCategoryToTableCategoriesInDatabase(Category());
}

void FinanceRepository::AddCategory(Category&& category)
{
  category_database_->InsertCategoryToTableCategoriesInDatabase(std::move(category));
}

void FinanceRepository::AddCategories(CategoryRepository&& categories)
{
  category_database_->InsertCategoriesToTableCategoriesInDatabase(std::move(categories));
}

void FinanceRepository::AddCurrency()
{
  currency_database_->InsertCurrencyToTableCurrenciesInDatabase(Currency());
}

void FinanceRepository::AddCurrency(Currency&& currency)
{
  currency_database_->InsertCurrencyToTableCurrenciesInDatabase(std::move(currency));
}

void FinanceRepository::AddCurrencies(CurrencyRepository&& currencies)
{
  currency_database_->InsertCurrenciesToTableCurrenciesInDatabase(std::move(currencies));
}

void FinanceRepository::AddDescription()
{
  description_database_->InsertDescriptionToTableDescriptionsInDatabase(Description());
}

void FinanceRepository::AddDescription(Description&& description)
{
  description_database_->InsertDescriptionToTableDescriptionsInDatabase(std::move(description));
}

void FinanceRepository::AddDescriptions(DescriptionRepository&& descriptions)
{
  description_database_->InsertDescriptionsToTableDescriptionsInDatabase(std::move(descriptions));
}

void FinanceRepository::AddPayee()
{
  payee_database_->InsertPayeeToTablePayeesInDatabase(Payee());
}

void FinanceRepository::AddPayee(Payee&& payee)
{
  payee_database_->InsertPayeeToTablePayeesInDatabase(std::move(payee));
}

void FinanceRepository::AddPayees(PayeeRepository&& payees)
{
  payee_database_->InsertPayeesToTablePayeesInDatabase(std::move(payees));
}

void FinanceRepository::AddComment()
{
  comment_database_->InsertCommentToTableCommentsInDatabase(Comment());
}

void FinanceRepository::AddComment(Comment&& comment)
{
  comment_database_->InsertCommentToTableCommentsInDatabase(std::move(comment));
}

void FinanceRepository::AddComments(CommentRepository&& comments)
{
  comment_database_->InsertCommentsToTableCommentsInDatabase(std::move(comments));
}

void FinanceRepository::AddTag()
{
  tag_database_->InsertTagToTableTagsInDatabase(Tag());
}

void FinanceRepository::AddTag(Tag&& tag)
{
  tag_database_->InsertTagToTableTagsInDatabase(std::move(tag));
}

void FinanceRepository::AddTags(TagRepository&& tags)
{
  tag_database_->InsertTagsToTableTagsInDatabase(std::move(tags));
}

void FinanceRepository::RemoveTransaction(const int id)
{
  database_manager_->RemoveTransactionFromTableTransactionsInDatabase(id);
}

void FinanceRepository::RemoveAccount(const std::string& name)
{
  account_database_->RemoveAccountFromTableAccountsInDatabase(name);
}

void FinanceRepository::RemoveCategory(const std::string& name)
{
  category_database_->RemoveCategoryFromTableCategoriesInDatabase(name);
}

void FinanceRepository::RemoveCurrency(const std::string& name)
{
  currency_database_->RemoveCurrencyFromTableCurrenciesInDatabase(name);
}

void FinanceRepository::RemoveDescription(const std::string& name)
{
  description_database_->RemoveDescriptionFromTableDescriptionsInDatabase(name);
}

void FinanceRepository::RemovePayee(const std::string& name)
{
  payee_database_->RemovePayeeFromTablePayeesInDatabase(name);
}

void FinanceRepository::RemoveComment(const std::string& name)
{
  comment_database_->RemoveCommentFromTableCommentsInDatabase(name);
}

void FinanceRepository::RemoveTag(const std::string& name)
{
  tag_database_->RemoveTagFromTableTagsInDatabase(name);
}

std::string FinanceRepository::GetAccountName(const std::string& account_name)
{
  return account_database_->GetAccountName(account_name);
}

NUM FinanceRepository::GetAccountAmount(const std::string& account_name)
{
  return account_database_->GetAccountAmount(account_name);
}

std::string FinanceRepository::GetCategoryName(const std::string& category_name)
{
  return category_database_->GetCategoryName(category_name);
}

std::string FinanceRepository::GetCurrencyName(const std::string& currency_name)
{
  return currency_database_->GetCurrencyName(currency_name);
}

std::string FinanceRepository::GetCurrencyCode(const std::string& currency_name)
{
  return currency_database_->GetCurrencyCode(currency_name);
}

bool FinanceRepository::GetCurrencyActivity(const std::string& currency_name)
{
  return currency_database_->GetCurrencyActivity(currency_name);
}

std::string FinanceRepository::GetDescriptionName(const std::string& description_name)
{
  return description_database_->GetDescriptionName(description_name);
}

std::string FinanceRepository::GetPayeeName(const std::string& payee_name)
{
  return payee_database_->GetPayeeName(payee_name);
}

std::string FinanceRepository::GetCommentName(const std::string& comment_name)
{
  return comment_database_->GetCommentName(comment_name);
}

std::string FinanceRepository::GetTagName(const std::string& tag_name)
{
  return tag_database_->GetTagName(tag_name);
}

void FinanceRepository::SetAccountName(const std::string& account_name, const std::string& name)
{
  account_database_->SetAccountName(account_name, name);
}

void FinanceRepository::SetAccountAmount(const std::string& account_name, const NUM amount)
{
  account_database_->SetAccountAmount(account_name, amount);
}

void FinanceRepository::SetAccountCurrency(const std::string& account_name, Currency&& currency)
{
  account_database_->SetAccountCurrency(account_name, std::move(currency));
}

void FinanceRepository::SetCategoryName(const std::string& category_name, const std::string& name)
{
  category_database_->SetCategoryName(category_name, name);
}

void FinanceRepository::SetCurrencyName(const std::string& currency_name, const std::string& name)
{
  currency_database_->SetCurrencyName(currency_name, name);
}

void FinanceRepository::SetCurrencyCode(const std::string& currency_name, const std::string& code)
{
  currency_database_->SetCurrencyCode(currency_name, code);
}

void FinanceRepository::SetCurrencyActivity(const std::string& currency_name, const bool activity)
{
  currency_database_->SetCurrencyActivity(currency_name, activity);
}

void FinanceRepository::SwitchCurrencyActivity(const std::string& currency_name)
{
  currency_database_->SwitchCurrencyActivity(currency_name);
}

void FinanceRepository::SwitchOnCurrencyActivity(const std::string& currency_name)
{
  currency_database_->SwitchOnCurrencyActivity(currency_name);
}

void FinanceRepository::SwitchOffCurrencyActivity(const std::string& currency_name)
{
  currency_database_->SwitchOffCurrencyActivity(currency_name);
}

void FinanceRepository::SetDescriptionName(const std::string& model_name, const std::string& name)
{
  description_database_->SetDescriptionName(model_name, name);
}

void FinanceRepository::SetPayeeName(const std::string& payee_name, const std::string& name)
{
  payee_database_->SetPayeeName(payee_name, name);
}

void FinanceRepository::SetCommentName(const std::string& comment_name, const std::string& name)
{
  comment_database_->SetCommentName(comment_name, name);
}

void FinanceRepository::SetTagName(const std::string& tag_name, const std::string& name)
{
  tag_database_->SetTagName(tag_name, name);
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
  transaction_database_->ClearTableTransactionsInDatabase();
}

void FinanceRepository::ClearAccounts()
{
  account_database_->ClearTableAccountsInDatabase();
}

void FinanceRepository::ClearCategories()
{
  category_database_->ClearTableCategoriesInDatabase();
}

void FinanceRepository::ClearCurrencies()
{
  currency_database_->ClearTableCurrenciesInDatabase();
}

void FinanceRepository::ClearDescriptions()
{
  description_database_->ClearTableDescriptionsInDatabase();
}

void FinanceRepository::ClearPayees()
{
  payee_database_->ClearTablePayeesInDatabase();
}

void FinanceRepository::ClearComments()
{
  comment_database_->ClearTableCommentsInDatabase();
}

void FinanceRepository::ClearTags()
{
  tag_database_->ClearTableTagsInDatabase();
}

std::tuple<bool, int, Account> FinanceRepository::FindAccount(const std::string& name) const
{
  return account_database_->FindAccountInTableAccountsInDatabase(name);
}

std::tuple<bool, int, Category, int> FinanceRepository::FindCategory(const std::string& name) const
{
  return category_database_->FindCategoryInTableCategoriesInDatabase(name);
}

std::tuple<bool, int, Currency> FinanceRepository::FindCurrency(const std::string& name) const
{
  return currency_database_->FindCurrencyInTableCurrenciesInDatabase(name);
}

std::tuple<bool, int, Currency> FinanceRepository::FindCurrencyByCode(const std::string& code) const
{
  return currency_database_->FindCurrencyByCodeInTableCurrenciesInDatabase(code);
}

std::tuple<bool, int, Description, int> FinanceRepository::FindDescription(const std::string& name) const
{
  return description_database_->FindDescriptionInTableDescriptionsInDatabase(name);
}

std::tuple<bool, int, Payee, int> FinanceRepository::FindPayee(const std::string& name) const
{
  return payee_database_->FindPayeeInTablePayeesInDatabase(name);
}

std::tuple<bool, int, Comment, int> FinanceRepository::FindComment(const std::string& name) const
{
  return comment_database_->FindCommentInTableCommentsInDatabase(name);
}

std::tuple<bool, int, Tag, int> FinanceRepository::FindTag(const std::string& name) const
{
  return tag_database_->FindTagInTableTagsInDatabase(name);
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
