#ifndef HOMEBOOKKEEPING_2BUSINESSLOGIC_DATABASEMANAGER_H_
#define HOMEBOOKKEEPING_2BUSINESSLOGIC_DATABASEMANAGER_H_

//  Class DatabaseManager
//
//  Constructors:
//    Default
//
//  Destructors:
//    Default
//
//  Class member functions:
//    general:
//      calculate rows with data in table
//      create all tables in database
//      clear all tables in database
//      check table for existence in database
//      create table in database
//      clear table from database
//    transactions:
//      create table 'Transactions' in database
//      clear table 'Transactions' in database
//      insert transaction to table 'Transactions' in database
//      insert transactions to table 'Transactions' in database
//      remove transaction with definite id from table 'Transactions' in database
//    accounts:
//      create table 'Accounts' in database
//      clear table 'Accounts' in database
//      insert account to table 'Accounts' in database
//      insert accounts to table 'Accounts' in database
//      find account with definite name in table 'Accounts' in database
//      set name of account in table 'Accounts' in database
//      set amount of account in table 'Accounts' in database
//      set currency of account in table 'Accounts' in database
//      get name of account from table 'Accounts' in database
//      get amount of account from table 'Accounts' in database
//      get currency of account from table 'Accounts' in database
//      remove account with definite name from table 'Accounts' in database
//    categories:
//      create table 'Categories' in database
//      clear table 'Categories' in database
//      insert category to table 'Categories' in database
//      insert categories to table 'Categories' in database
//      find category with definite name in table 'Categories' in database
//      set name of category in table 'Categories' in database
//      get name of category from table 'Categories' in database
//      remove category with definite name from table 'Categories' in database
//    currencies:
//      create table 'Currencies' in database
//      clear table 'Currencies' in database
//      insert currency to table 'Currencies' in database
//      insert currencies to table 'Currencies' in database
//      set name of currency in table 'Currencies' in database
//      set code of currency in table 'Currencies' in database
//      set activity of currency in table 'Currencies' in database
//      get name of currency from table 'Currencies' in database
//      get code of currency from table 'Currencies' in database
//      get activity of currency from table 'Currencies' in database
//      switch activity of currency from table 'Currencies' in database
//      switch off activity of currency from table 'Currencies' in database
//      switch on activity of currency from table 'Currencies' in database
//      remove currency with definite name from table 'Currencies' in database
//    descriptions:
//      create table 'Descriptions' in database
//      clear table 'Descriptions' in database
//      insert description to table 'Descriptions' in database
//      insert descriptions to table 'Descriptions' in database
//      find description with definite name in table 'Descriptions' in database
//      set name of description in table 'Descriptions' in database
//      get name of description from table 'Descriptions' in database
//      remove description with definite name from table 'Descriptions' in database
//    payees:
//      create table 'Payees' in database
//      clear table 'Payees' in database
//      insert payee to table 'Payees' in database
//      insert payees to table 'Payees' in database
//      find payee with definite name in table 'Payees' in database
//      set name of payee in table 'Payees' in database
//      get name of payee from table 'Payees' in database
//      remove payee with definite name from table 'Payees' in database
//    comments:
//      create table 'Comments' in database
//      clear table 'Comments' in database
//      insert comment to table 'Comments' in database
//      insert comments to table 'Comments' in database
//      find comment with definite name in table 'Comments' in database
//      set name of comment in table 'Comments' in database
//      get name of comment from table 'Comments' in database
//      remove comment with definite name from table 'Comments' in database
//    tags:
//      create table 'Tags' in database
//      clear table 'Tags' in database
//      insert tag to table 'Tags' in database
//      insert tags to table 'Tags' in database
//      find tag with definite name in table 'Tags' in database
//      set name of tag in table 'Tags' in database
//      get name of tag from table 'Tags' in database
//      remove tag with definite name from table 'Tags' in database
//
//  Variables:
//      Database;
//      Prepared Statement Object;
//      SQL Command Status
//      SQL Command Error Message

#include "Home_Bookkeeping/lib/sqlite/sqlite3.h"
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

class DatabaseManager
{
public:
  DatabaseManager();
  ~DatabaseManager();

  int SizeOfTable(const std::string& table);
  void CreateTableInDatabase(const std::string& table);
  void CreateAllTablesInDatabase();
  void ClearTableInDatabase(const std::string& table);
  void ClearAllTablesInDatabase();
  bool CheckTableForExistenceInDatabase(const std::string& table);

  void CreateTableTransactionsInDatabase();
  void ClearTableTransactionsInDatabase();
  void InsertTransactionToTableTransactionsInDatabase(Transaction&& transaction);
  void InsertTransactionsToTableTransactionsInDatabase(TransactionRepository&& repository);
  std::tuple<bool, int, Transaction> FindTransactionInTableTransactionsInDatabase(const int id);
  void RemoveTransactionFromTableTransactionsInDatabase(const int id);

  void CreateTableAccountsInDatabase();
  void ClearTableAccountsInDatabase();
  void InsertAccountToTableAccountsInDatabase(Account&& model);
  void InsertAccountsToTableAccountsInDatabase(AccountRepository&& repository);
  std::tuple<bool, int, Account> FindAccountInTableAccountsInDatabase(const std::string& model_name);
  void SetAccountName(const std::string& model_name, const std::string& name);
  void SetAccountAmount(const std::string& model_name, const NUM amount);
  void SetAccountCurrency(const std::string& model_name, Currency&& currency);
  std::string GetAccountName(const std::string& model_name);
  NUM GetAccountAmount(const std::string& model_name);
  Currency GetAccountCurrency(const std::string& model_name);
  void RemoveAccountFromTableAccountsInDatabase(const std::string& model_name);

  void CreateTableCategoriesInDatabase();
  void ClearTableCategoriesInDatabase();
  void InsertCategoryToTableCategoriesInDatabase(Category&& category);
  void InsertCategoriesToTableCategoriesInDatabase(CategoryRepository&& repository);
  std::tuple<bool, int, Category, int> FindCategoryInTableCategoriesInDatabase(const std::string& model_name);
  void SetCategoryName(const std::string& model_name, const std::string& name);
  std::string GetCategoryName(const std::string& model_name);
  void RemoveCategoryFromTableCategoriesInDatabase(const std::string& model_name);

  void CreateTableCurrenciesInDatabase();
  void ClearTableCurrenciesInDatabase();
  void InsertCurrencyToTableCurrenciesInDatabase(Currency&& currency);
  void InsertCurrenciesToTableCurrenciesInDatabase(CurrencyRepository&& repository);
  std::tuple<bool, int, Currency> FindCurrencyInTableCurrenciesInDatabase(const std::string& model_name);
  std::tuple<bool, int, Currency> FindCurrencyByCodeInTableCurrenciesInDatabase(const std::string& model_code);
  void SetCurrencyName(const std::string& model_name, const std::string& name);
  void SetCurrencyCode(const std::string& model_name, const std::string& code);
  void SetCurrencyActivity(const std::string& model_name, const bool activity);
  std::string GetCurrencyName(const std::string& model_name);
  std::string GetCurrencyCode(const std::string& model_name);
  bool GetCurrencyActivity(const std::string& model_name);
  void SwitchCurrencyActivity(const std::string& model_name);
  void SwitchOnCurrencyActivity(const std::string& model_name);
  void SwitchOffCurrencyActivity(const std::string& model_name);
  void RemoveCurrencyFromTableCurrenciesInDatabase(const std::string& model_name);

  void CreateTableDescriptionsInDatabase();
  void ClearTableDescriptionsInDatabase();
  void InsertDescriptionToTableDescriptionsInDatabase(Description&& description);
  void InsertDescriptionsToTableDescriptionsInDatabase(DescriptionRepository&& repository);
  std::tuple<bool, int, Description, int> FindDescriptionInTableDescriptionsInDatabase(const std::string& model_name);
  void SetDescriptionName(const std::string& model_name, const std::string& name);
  std::string GetDescriptionName(const std::string& model_name);
  void RemoveDescriptionFromTableDescriptionsInDatabase(const std::string& model_name);

  void CreateTablePayeesInDatabase();
  void ClearTablePayeesInDatabase();
  void InsertPayeeToTablePayeesInDatabase(Payee&& payee);
  void InsertPayeesToTablePayeesInDatabase(PayeeRepository&& repository);
  std::tuple<bool, int, Payee, int> FindPayeeInTablePayeesInDatabase(const std::string& model_name);
  void SetPayeeName(const std::string& model_name, const std::string& name);
  std::string GetPayeeName(const std::string& model_name);
  void RemovePayeeFromTablePayeesInDatabase(const std::string& model_name);

  void CreateTableCommentsInDatabase();
  void ClearTableCommentsInDatabase();
  void InsertCommentToTableCommentsInDatabase(Comment&& comment);
  void InsertCommentsToTableCommentsInDatabase(CommentRepository&& repository);
  std::tuple<bool, int, Comment, int> FindCommentInTableCommentsInDatabase(const std::string& model_name);
  void SetCommentName(const std::string& model_name, const std::string& name);
  std::string GetCommentName(const std::string& model_name);
  void RemoveCommentFromTableCommentsInDatabase(const std::string& model_name);

  void CreateTableTagsInDatabase();
  void ClearTableTagsInDatabase();
  void InsertTagToTableTagsInDatabase(Tag&& tag);
  void InsertTagsToTableTagsInDatabase(TagRepository&& repository);
  std::tuple<bool, int, Tag, int> FindTagInTableTagsInDatabase(const std::string& model_name);
  void SetTagName(const std::string& model_name, const std::string& name);
  std::string GetTagName(const std::string& model_name);
  void RemoveTagFromTableTagsInDatabase(const std::string& model_name);
private:
  char* database_error_;
  int database_status_;
  sqlite3* database_;
  sqlite3_stmt* database_stmt_;
};

#endif  //  HOMEBOOKKEEPING_2BUSINESSLOGIC_DATABASEMANAGER_H_
