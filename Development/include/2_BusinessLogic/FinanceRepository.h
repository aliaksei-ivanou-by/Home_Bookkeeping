#ifndef HOMEBOOKKEEPING_2BUSINESSLOGIC_FINANCENREPOSITORY_H_
#define HOMEBOOKKEEPING_2BUSINESSLOGIC_FINANCENREPOSITORY_H_

#include <iostream>
#include <chrono>
#include <thread>

#include "lib/logger/Log.h"
#include "lib/logger/Initializers/RollingFileInitializer.h"

#include "include/1_DataAccess/AccountRepository.h"
#include "include/1_DataAccess/CategoryRepository.h"
#include "include/1_DataAccess/CommentRepository.h"
#include "include/1_DataAccess/CurrencyRepository.h"
#include "include/1_DataAccess/DescriptionRepository.h"
#include "include/1_DataAccess/PayeeRepository.h"
#include "include/1_DataAccess/TagRepository.h"
#include "include/1_DataAccess/TransactionRepository.h"

#include "include/1_DataAccess/DatabaseManager.h"

#include "include/1_DataAccess/AccountDatabase.h"
#include "include/1_DataAccess/CategoryDatabase.h"
#include "include/1_DataAccess/CommentDatabase.h"
#include "include/1_DataAccess/CurrencyDatabase.h"
#include "include/1_DataAccess/DescriptionDatabase.h"
#include "include/1_DataAccess/PayeeDatabase.h"
#include "include/1_DataAccess/TagDatabase.h"
#include "include/1_DataAccess/TransactionDatabase.h"

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
  CurrencyDatabase* currency_database_;
  AccountDatabase* account_database_;
  CategoryDatabase* category_database_;
  CommentDatabase* comment_database_;
  DescriptionDatabase* description_database_;
  PayeeDatabase* payee_database_;
  TagDatabase* tag_database_;
  TransactionDatabase* transaction_database_;
};

#endif
