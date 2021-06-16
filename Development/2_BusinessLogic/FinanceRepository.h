#ifndef HOMEBOOKKEEPING_2BUSINESSLOGIC_FINANCENREPOSITORY_H_
#define HOMEBOOKKEEPING_2BUSINESSLOGIC_FINANCENREPOSITORY_H_

//  Class FinanceRepository
//
//  Constructors:
//    Default
//
//  Destructors:
//    Default
//
//  Class member functions:
//    basic:
//      iterators:
//        begin:
//          Find begin iterator of transaction repository
//          Find begin iterator of account repository
//          Find begin iterator of category repository
//          Find begin iterator of currency repository
//          Find begin iterator of description repository
//          Find begin iterator of payee repository
//          Find begin iterator of comment repository
//          Find begin iterator of tag repository
//        end:
//          Find end iterator of transaction repository
//          Find end iterator of account repository
//          Find end iterator of category repository
//          Find end iterator of currency repository
//          Find end iterator of description repository
//          Find end iterator of payee repository
//          Find end iterator of comment repository
//          Find end iterator of tag repository
//        add element:
//          Add transaction to database
//          Add account (default) to database
//          Add account to database
//          Add category (default) to database
//          Add category to database
//          Add currency to database
//          Add description to database
//          Add payee to database
//          Add payees to database
//          Add comment to database
//          Add tag to database
//        remove element:
//          Remove transaction (shared pointer) from transaction repository
//          Remove account from database
//          Remove category from database
//          Remove currency from database
//          Remove description from database
//          Remove payee from database
//          Remove comment from database
//          Remove tag from database
//          Add model 'Unspecified' instead of removed models to database
//        get values of model from repository
//          Get name of account from database
//          Get amount of account from database
//          Get name of category from database
//          Get name of currency from database
//          Get code of currency from database
//          Get activity of currency from database
//          Get name of description from database
//          Get name of payee from database
//          Get name of comment from database
//          Get name of tag from database
//        set values of model from repository
//          Set name of account from database
//          Set amount of account from database
//          Set name of category from database
//          Set name of currency from database
//          Set code of currency from database
//          Set activity of currency from database
//          Switch activity of currency from database
//          Switch on activity of currency from database
//          Switch off activity of currency from database
//          Set name of description from database
//          Set name of payee from database
//          Set name of comment from database
//          Set name of tag from database
//        number of elements in repository:
//          Number of transactions in database
//          Number of accounts in database
//          Number of categories in database
//          Number of currencies in database
//          Number of descriptions in database
//          Number of payees in database
//          Number of comments in database
//          Number of tags in database
//        clear repository:
//          Clear table 'Transactions' in database
//          Clear table 'Accounts' in database
//          Clear table 'Categories' in database
//          Clear table 'Currencies' in database
//          Clear table 'Descriptions' in database
//          Clear table 'Payees' in database
//          Clear table 'Comments' in database
//          Clear table 'Tags' in database
//        print repository:
//          Print transaction repository
//          Print account repository
//          Print category repository
//          Print currency repository
//          Print description repository
//          Print payee repository
//          Print comment repository
//          Print tag repository
//        find:
//          Find account with definite name in database
//          Find category with definite name in database
//          Find currency with definite name in database
//          Find currency with definite code in database
//          Find description with definite name in database
//          Find payee with definite name in database
//          Find comment with definite name in database
//          Find tag with definite name in database
//        update repository with adding new transaction:
//          Update last amount of account in account repository with adding new transaction
//          Update account repository with adding new transaction
//          Update category repository with adding new transaction
//          Update currency repository with adding new transaction
//          Update description repository with adding new transaction
//          Update payee repository with adding new transaction
//          Update comment repository with adding new transaction
//          Update tag repository with adding new transaction
//    sum:
//      expenses:
//        Calculate sum of today expenses
//        Calculate sum of this month expenses
//        Calculate sum of all time expenses
//      incomes:
//        Calculate sum of today incomes
//        Calculate sum of this month incomes
//        Calculate sum of all time incomes
//    add default models to repository:
//      Add default accounts to account repository
//      Add default categories to category repository
//      Add default currencies to currency repository
//    clear tables in database
//  Variables:
//    transaction repository (temp variable for GUI)
//    category repository (temp variable for GUI)
//    comment repository (temp variable for GUI)
//    payee repository (temp variable for GUI)
//    account repository (temp variable for GUI)
//    currency repository (temp variable for GUI)
//    description repository (temp variable for GUI)
//    tag repository (temp variable for GUI)
//    Database Manager

#include <iostream>
#include <chrono>
#include <thread>

#include "home_bookkeeping/lib/logger/Log.h"
#include "home_bookkeeping/lib/logger/Initializers/RollingFileInitializer.h"

#include "home_bookkeeping/1_DataAccess/AccountRepository.h"
#include "home_bookkeeping/1_DataAccess/CategoryRepository.h"
#include "home_bookkeeping/1_DataAccess/CommentRepository.h"
#include "home_bookkeeping/1_DataAccess/CurrencyRepository.h"
#include "home_bookkeeping/1_DataAccess/DescriptionRepository.h"
#include "home_bookkeeping/1_DataAccess/PayeeRepository.h"
#include "home_bookkeeping/1_DataAccess/TagRepository.h"
#include "home_bookkeeping/1_DataAccess/TransactionRepository.h"

#include "home_bookkeeping/2_BusinessLogic/DatabaseManager.h"

class FinanceRepository
{
public:
  //  basic->iterators->begin
  TransactionRepositoryIterator BeginTransactionRepository() const;
  AccountRepositoryIterator BeginAccountRepository() const;
  CategoryRepositoryConstIterator BeginCategoryRepository() const;
  CurrencyRepositoryIterator BeginCurrencyRepository() const;
  DescriptionRepositoryConstIterator BeginDescriptionRepository() const;
  PayeeRepositoryConstIterator BeginPayeeRepository() const;
  CommentRepositoryConstIterator BeginCommentRepository() const;
  TagRepositoryConstIterator BeginTagRepository() const;
  //  basic->iterators->end
  TransactionRepositoryIterator EndTransactionRepository() const;
  AccountRepositoryIterator EndAccountRepository() const;
  CategoryRepositoryConstIterator EndCategoryRepository() const;
  CurrencyRepositoryIterator EndCurrencyRepository() const;
  DescriptionRepositoryConstIterator EndDescriptionRepository() const;
  PayeeRepositoryConstIterator EndPayeeRepository() const;
  CommentRepositoryConstIterator EndCommentRepository() const;
  TagRepositoryConstIterator EndTagRepository() const;
  //  constructor->default
  FinanceRepository();
  //  destructor->default
  ~FinanceRepository();
  //  basic->add element to database
  void AddTransaction(Transaction&& transaction);
  void AddAccount();
  void AddAccount(Account&& account);
  void AddAccounts(AccountRepository&& accounts);
  void AddCategory();
  void AddCategory(Category&& category);
  void AddCategories(CategoryRepository&& categories);
  void AddCurrency();
  void AddCurrency(Currency&& currency);
  void AddCurrencies(CurrencyRepository&& currencies);
  void AddDescription();
  void AddDescription(Description&& description);
  void AddDescriptions(DescriptionRepository&& descriptions);
  void AddPayee();
  void AddPayee(Payee&& payee);
  void AddPayees(PayeeRepository&& payees);
  void AddComment();
  void AddComment(Comment&& comment);
  void AddComments(CommentRepository&& comments);
  void AddTag();
  void AddTag(Tag&& tag);
  void AddTags(TagRepository&& tags);
  //  basic->remove element from database
  void RemoveTransaction(std::shared_ptr<Transaction> transaction);
  void RemoveAccount(const std::string& name);
  void RemoveCategory(const std::string& name);
  void RemoveCurrency(const std::string& name);
  void RemoveDescription(const std::string& name);
  void RemovePayee(const std::string& name);
  void RemoveComment(const std::string& name);
  void RemoveTag(const std::string& name);
  //  basic->get values of model from repository
  std::string GetAccountName(AccountRepositoryIterator account) const;
  NUM GetAccountAmount(AccountRepositoryIterator account) const;
  std::string GetCategoryName(CategoryRepositoryIterator category) const;
  std::string GetCurrencyName(CurrencyRepositoryIterator currency) const;
  std::string GetCurrencyCode(CurrencyRepositoryIterator currency) const;
  bool GetCurrencyActivity(CurrencyRepositoryIterator currency) const;
  std::string GetDescriptionName(DescriptionRepositoryIterator description) const;
  std::string GetPayeeName(PayeeRepositoryIterator payee) const;
  std::string GetCommentName(CommentRepositoryIterator comment) const;
  std::string GetTagName(TagRepositoryIterator tag) const;
  //  basic->set values of model from repository
  void SetAccountName(const std::string& account_name, const std::string& name);
  void SetAccountAmount(const std::string& account_name, const double amount);
  void SetAccountCurrency(const std::string& account_name, Currency&& currency);
  void SetCategoryName(const std::string& category_name, const std::string& name);
  void SetCurrencyName(CurrencyRepositoryIterator currency, const std::string& name);
  void SetCurrencyCode(CurrencyRepositoryIterator currency, const std::string& code);
  void SetCurrencyActivity(CurrencyRepositoryIterator currency, const bool activity);
  void SwitchCurrencyActivity(CurrencyRepositoryIterator currency);
  void SwitchOnCurrencyActivity(CurrencyRepositoryIterator currency);
  void SwitchOffCurrencyActivity(CurrencyRepositoryIterator currency);
  void SetDescriptionName(const std::string& model_name, const std::string& name);
  void SetPayeeName(const std::string& payee_name, const std::string& name);
  void SetCommentName(const std::string& comment_name, const std::string& name);
  void SetTagName(const std::string& tag_name, const std::string& name);
  //  basic->number of elements in repository
  size_t GetTransactionsNumber() const;
  size_t GetAccountsNumber() const;
  size_t GetCategoriesNumber() const;
  size_t GetCurrenciesNumber() const;
  size_t GetDescriptionsNumber() const;
  size_t GetPayeesNumber() const;
  size_t GetCommentsNumber() const;
  size_t GetTagsNumber() const;
  //  basic->clear repository
  void ClearTransactions();
  void ClearAccounts();
  void ClearCategories();
  void ClearCurrencies();
  void ClearDescriptions();
  void ClearPayees();
  void ClearComments();
  void ClearTags();
  //  basic->print repository
  void PrintTransactions(const std::string& delimeter = "\n", std::ostream& output_stream = std::cout) const;
  void PrintAccounts(const std::string& delimeter = "\n", std::ostream& output_stream = std::cout) const;
  void PrintCategories(const std::string& delimeter = "\n", std::ostream& output_stream = std::cout) const;
  void PrintCurrencies(const std::string& delimeter = "\n", std::ostream& output_stream = std::cout) const;
  void PrintDescriptions(const std::string& delimeter = "\n", std::ostream& output_stream = std::cout) const;
  void PrintPayees(const std::string& delimeter = "\n", std::ostream& output_stream = std::cout) const;
  void PrintComments(const std::string& delimeter = "\n", std::ostream& output_stream = std::cout) const;
  void PrintTags(const std::string& delimeter = "\n", std::ostream& output_stream = std::cout) const;
  //  basic->find (definite name)
  std::tuple<bool, int, Account> FindAccount(const std::string& name) const;
  std::tuple<bool, int, Category, int> FindCategory(const std::string& name) const;
  std::tuple<bool, int, Currency> FindCurrency(const std::string& name) const;
  std::tuple<bool, int, Currency> FindCurrencyByCode(const std::string& name) const;
  std::tuple<bool, int, Description, int> FindDescription(const std::string& name) const;
  std::tuple<bool, int, Payee, int> FindPayee(const std::string& name) const;
  std::tuple<bool, int, Comment, int> FindComment(const std::string& comment) const;
  std::tuple<bool, int, Tag, int> FindTag(const std::string& name) const;
  //  basic->update repository with adding new transaction
  void UpdateAccountAmount(Transaction& transaction);
  void UpdateAccountRepository(Transaction& transaction);
  void UpdateCategoryRepository(Transaction& transaction);
  void UpdateCurrencyRepository(Transaction& transaction);
  void UpdateDescriptionRepository(Transaction& transaction);
  void UpdatePayeeRepository(Transaction& transaction);
  void UpdateCommentRepository(Transaction& transaction);
  void UpdateTagRepository(Transaction& transaction);
  //  sum->expenses
  NUM SumExpensesToday() const;
  NUM SumExpensesThisMonth() const;
  NUM SumExpensesAllTime() const;
  //  sum->incomes
  NUM SumIncomesToday() const;
  NUM SumIncomesThisMonth() const;
  NUM SumIncomesAllTime() const;
  //  add default models to repository
  void AddDefaultCategories();
  void AddDefaultAccounts();
  void AddDefaultCurrencies();

  void ClearTablesInDatabase();
private:
  TransactionRepository transaction_repository_;
  CategoryRepository category_repository_;
  CommentRepository comment_repository_;
  PayeeRepository payee_repository_;
  AccountRepository account_repository_;
  CurrencyRepository currency_repository_;
  DescriptionRepository description_repository_;
  TagRepository tag_repository_;
  DatabaseManager* database_manager_;
};

#endif  //  HOMEBOOKKEEPING_2BUSINESSLOGIC_FINANCENREPOSITORY_H_
