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
//          Remove account (shared pointer) from account repository
//          Remove category (shared pointer) from category repository
//          Remove currency (shared pointer) from currency repository
//          Remove description (shared pointer) from description repository
//          Remove payee (shared pointer) from payee repository
//          Remove comment (shared pointer) from comment repository
//          Remove tag (shared pointer) from tag repository
//        get values of model from repository
//          Get name of account from repository
//          Get amount of account from repository
//          Get name of category from repository
//          Get name of currency from repository
//          Get code of currency from repository
//          Get activity of currency from repository
//          Get name of description from repository
//          Get name of payee from repository
//          Get name of comment from repository
//          Get name of tag from repository
//        set values of model from repository
//          Set name of account from repository
//          Set amount of account from repository
//          Set name of category from repository
//          Set name of currency from repository
//          Set code of currency from repository
//          Set activity of currency from repository
//          Switch activity of currency from repository
//          Switch on activity of currency from repository
//          Switch off activity of currency from repository
//          Set name of description from repository
//          Set name of payee from repository
//          Set name of comment from repository
//          Set name of tag from repository
//        number of elements in repository:
//          Number of transactions in transaction repository
//          Number of accounts in account repository
//          Number of categories in category repository
//          Number of currencies in currency repository
//          Number of descriptions in description repository
//          Number of payees in payee repository
//          Number of comments in comment repository
//          Number of tags in tag repository
//        clear repository:
//          Clear transaction repository
//          Clear account repository
//          Clear category repository
//          Clear currency repository
//          Clear description repository
//          Clear payee repository
//          Clear comment repository
//          Clear tag repository
//        print repository:
//          Print transaction repository
//          Print account repository
//          Print category repository
//          Print currency repository
//          Print description repository
//          Print payee repository
//          Print comment repository
//          Print tag repository
//        find (definite name):
//          Find account with definite name in account repository
//          Find account with definite amoune in account repository
//          Find category with definite name in category repository
//          Find currency with definite name in currency repository
//          Find currency with definite code in currency repository
//          Find description with definite name in description repository
//          Find payee with definite name in payee repository
//          Find comment with definite name in tag repository
//          Find tag with definite name in tag repository
//        find (shared pointer):
//          Find transaction (shared pointer) in transaction repository
//          Find account (shared pointer) in account repository
//          Find category (shared pointer) in category repository
//          Find currency (shared pointer) in currency repository
//          Find description (shared pointer) in description repository
//          Find payee (shared pointer) in payee repository
//          Find comment (shared pointer) in comment repository
//          Find tag (shared pointer) in tag repository
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
//
//  Variables:
//    transaction repository
//    category repository
//    comment repository
//    payee repository
//    account repository
//    currency repository
//    description repository
//    tag repository
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
  //  basic->add element
  void AddTransaction(Transaction&& transaction);
  void AddAccount();
  void AddAccount(Account&& account);
  void AddAccounts(AccountRepository&& accounts);
  void AddCategory();
  void AddCategory(Category&& category);
  void AddCategories(CategoryRepository&& categories);
  void AddCurrency();
  void AddCurrency(const Currency& currency);
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
  //  basic->remove element
  void RemoveTransaction(std::shared_ptr<Transaction> transaction);
  void RemoveAccount(std::shared_ptr<Account> account);
  void RemoveCategory(std::shared_ptr<Category> category);
  void RemoveCurrency(std::shared_ptr<Currency> currency);
  void RemoveDescription(std::shared_ptr<Description> description);
  void RemovePayee(std::shared_ptr<Payee> payee);
  void RemoveComment(std::shared_ptr<Comment> comment);
  void RemoveTag(std::shared_ptr<Tag> tag);
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
  void SetAccountName(AccountRepositoryIterator account, const std::string& name);
  void SetAccountAmount(AccountRepositoryIterator account, const double amount);
  void SetCategoryName(CategoryRepositoryIterator category, const std::string& name);
  void SetCurrencyName(CurrencyRepositoryIterator currency, const std::string& name);
  void SetCurrencyCode(CurrencyRepositoryIterator currency, const std::string& code);
  void SetCurrencyActivity(CurrencyRepositoryIterator currency, const bool activity);
  void SwitchCurrencyActivity(CurrencyRepositoryIterator currency);
  void SwitchOnCurrencyActivity(CurrencyRepositoryIterator currency);
  void SwitchOffCurrencyActivity(CurrencyRepositoryIterator currency);
  void SetDescriptionName(DescriptionRepositoryIterator description, const std::string& name);
  void SetPayeeName(PayeeRepositoryIterator payee, const std::string& name);
  void SetCommentName(CommentRepositoryIterator comment, const std::string& name);
  void SetTagName(TagRepositoryIterator tag, const std::string& name);
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
  AccountRepositoryIterator FindAccount(std::string name) const;
  AccountRepositoryIterator FindAccount(double amount) const;
  CategoryRepositoryConstIterator FindCategory(std::string name) const;
  CurrencyRepositoryIterator FindCurrencyName(std::string name) const;
  CurrencyRepositoryIterator FindCurrencyCode(std::string name) const;
  DescriptionRepositoryConstIterator FindDescription(std::string name) const;
  PayeeRepositoryConstIterator FindPayee(std::string name) const;
  CommentRepositoryConstIterator FindComment(std::string comment) const;
  TagRepositoryConstIterator FindTag(std::string name) const;
  //  basic->find (shared pointer)
  TransactionRepositoryIterator FindTransaction(std::shared_ptr<Transaction> transaction) const;
  AccountRepositoryIterator FindAccount(std::shared_ptr<Account> account) const;
  CategoryRepositoryConstIterator FindCategory(std::shared_ptr<Category> category) const;
  CurrencyRepositoryIterator FindCurrency(std::shared_ptr<Currency> currency) const;
  DescriptionRepositoryConstIterator FindDescription(std::shared_ptr<Description> description) const;
  PayeeRepositoryConstIterator FindPayee(std::shared_ptr<Payee> payee) const;
  CommentRepositoryConstIterator FindComment(std::shared_ptr<Comment> comment) const;
  TagRepositoryConstIterator FindTag(std::shared_ptr<Tag> tag) const;
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
