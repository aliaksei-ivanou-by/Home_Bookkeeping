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
//          Remove transaction from database
//          Remove account from database
//          Remove category from database
//          Remove currency from database
//          Remove description from database
//          Remove payee from database
//          Remove comment from database
//          Remove tag from database
//        get value of model
//          Get name of account from table 'Accounts' in database
//          Get amount of account from table 'Accounts' in database
//          Get name of category from table 'Categories' in database
//          Get name of currency from table 'Currencies' in database
//          Get code of currency from table 'Currencies' in database
//          Get activity of currency from table 'Currencies' in database
//          Get name of description from table 'Descriptions' in database
//          Get name of payee from table 'Payees' in database
//          Get name of comment from table 'Comments' in database
//          Get name of tag from table 'Tags' in database
//        set value of model
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
//        number of elements
//          Number of transactions in database
//          Number of accounts in database
//          Number of categories in database
//          Number of currencies in database
//          Number of descriptions in database
//          Number of payees in database
//          Number of comments in database
//          Number of tags in database
//        clear table
//          Clear table 'Transactions' in database
//          Clear table 'Accounts' in database
//          Clear table 'Categories' in database
//          Clear table 'Currencies' in database
//          Clear table 'Descriptions' in database
//          Clear table 'Payees' in database
//          Clear table 'Comments' in database
//          Clear table 'Tags' in database
//        find:
//          Find account with definite name in database
//          Find category with definite name in database
//          Find currency with definite name in database
//          Find currency with definite code in database
//          Find description with definite name in database
//          Find payee with definite name in database
//          Find comment with definite name in database
//          Find tag with definite name in database
//    sum:
//      expenses:
//        Calculate sum of today expenses
//        Calculate sum of this month expenses
//        Calculate sum of all time expenses
//      incomes:
//        Calculate sum of today incomes
//        Calculate sum of this month incomes
//        Calculate sum of all time incomes
//    add default models to database:
//      Add default accounts to table 'Accounts' in database
//      Add default categories to table 'Categories' in database
//      Add default currencies to table 'Currencies' in database
//    clear tables in database
//  Variables:
//    Database Manager

#include <iostream>
#include <chrono>
#include <thread>

#include "Home_Bookkeeping/lib/logger/Log.h"
#include "Home_Bookkeeping/lib/logger/Initializers/RollingFileInitializer.h"

#include "Home_Bookkeeping/1_DataAccess/AccountRepository.h"
#include "Home_Bookkeeping/1_DataAccess/CategoryRepository.h"
#include "Home_Bookkeeping/1_DataAccess/CommentRepository.h"
#include "Home_Bookkeeping/1_DataAccess/CurrencyRepository.h"
#include "Home_Bookkeeping/1_DataAccess/DescriptionRepository.h"
#include "Home_Bookkeeping/1_DataAccess/PayeeRepository.h"
#include "Home_Bookkeeping/1_DataAccess/TagRepository.h"
#include "Home_Bookkeeping/1_DataAccess/TransactionRepository.h"

#include "Home_Bookkeeping/2_BusinessLogic/DatabaseManager.h"

class FinanceRepository
{
public:
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
  void RemoveTransaction(const int id);
  void RemoveAccount(const std::string& name);
  void RemoveCategory(const std::string& name);
  void RemoveCurrency(const std::string& name);
  void RemoveDescription(const std::string& name);
  void RemovePayee(const std::string& name);
  void RemoveComment(const std::string& name);
  void RemoveTag(const std::string& name);
  //  basic->get values of model from repository
  std::string GetAccountName(const std::string& account_name);
  NUM GetAccountAmount(const std::string& account_name);
  std::string GetCategoryName(const std::string& category_name);
  std::string GetCurrencyName(const std::string& currency_name);
  std::string GetCurrencyCode(const std::string& currency_name);
  bool GetCurrencyActivity(const std::string& currency_name);
  std::string GetDescriptionName(const std::string& description_name);
  std::string GetPayeeName(const std::string& payee_name);
  std::string GetCommentName(const std::string& comment_name);
  std::string GetTagName(const std::string& tag_name);
  //  basic->set values of model from repository
  void SetAccountName(const std::string& account_name, const std::string& name);
  void SetAccountAmount(const std::string& account_name, const NUM amount);
  void SetAccountCurrency(const std::string& account_name, Currency&& currency);
  void SetCategoryName(const std::string& category_name, const std::string& name);
  void SetCurrencyName(const std::string& currency_name, const std::string& name);
  void SetCurrencyCode(const std::string& currency_name, const std::string& code);
  void SetCurrencyActivity(const std::string& currency_name, const bool activity);
  void SwitchCurrencyActivity(const std::string& currency_name);
  void SwitchOnCurrencyActivity(const std::string& currency_name);
  void SwitchOffCurrencyActivity(const std::string& currency_name);
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
  //  basic->find (definite name)
  std::tuple<bool, int, Account> FindAccount(const std::string& name) const;
  std::tuple<bool, int, Category, int> FindCategory(const std::string& name) const;
  std::tuple<bool, int, Currency> FindCurrency(const std::string& name) const;
  std::tuple<bool, int, Currency> FindCurrencyByCode(const std::string& name) const;
  std::tuple<bool, int, Description, int> FindDescription(const std::string& name) const;
  std::tuple<bool, int, Payee, int> FindPayee(const std::string& name) const;
  std::tuple<bool, int, Comment, int> FindComment(const std::string& comment) const;
  std::tuple<bool, int, Tag, int> FindTag(const std::string& name) const;
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
  DatabaseManager* database_manager_;
};

#endif  //  HOMEBOOKKEEPING_2BUSINESSLOGIC_FINANCENREPOSITORY_H_
