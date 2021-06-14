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
//    transactions:in
//      create table 'Transactions' in database
//      clear table 'Transactions' in database
//      insert transactions to table 'Transactions' in database
//      insert one transaction to table 'Transactions' in database
//    accounts:
//      create table 'Accounts' in database
//      clear table 'Accounts' in database
//      insert accounts to table 'Accounts' in database
//      insert one account to table 'Accounts' in database
//    categories:
//      create table 'Categories' in database
//      clear table 'Categories' in database
//      insert categories to table 'Categories' in database
//      insert one category to table 'Categories' in database
//      find category with definite name in table 'Categories' in database
//    currencies:
//      create table 'Currencies' in database
//      clear table 'Currencies' in database
//      insert currencies to table 'Currencies' in database
//      insert one currency to table 'Currencies' in database
//    descriptions:
//      create table 'Descriptions' in database
//      clear table 'Descriptions' in database
//      insert descriptions to table 'Descriptions' in database
//      insert one description to table 'Descriptions' in database
//      find description with definite name in table 'Descriptions' in database
//    payees:
//      create table 'Payees' in database
//      clear table 'Payees' in database
//      insert payees to table 'Payees' in database
//      insert one payee to table 'Payees' in database
//      find payee with definite name in table 'Payees' in database
//    comments:
//      create table 'Comments' in database
//      clear table 'Comments' in database
//      insert comments to table 'Comments' in database
//      insert one comment to table 'Comments' in database
//      find comment with definite name in table 'Comments' in database
//    tags:
//      create table 'Tags' in database
//      clear table 'Tags' in database
//      insert tags to table 'Tags' in database
//      insert one tag to table 'Tags' in database
//      find tag with definite name in table 'Tags' in database
//
//  Variables:
//      Database;
//      Prepared Statement Object;
//      SQL Command Status
//      SQL Command Error Message

#include "home_bookkeeping/lib/sqlite/sqlite3.h"
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

class DatabaseManager
{
public:
  DatabaseManager();
  ~DatabaseManager();

  int SizeOfTable(const std::string& table);

  void CreateAllTablesInDatabase();
  void ClearAllTablesInDatabase();

  void CreateTableTransactionsInDatabase();
  void ClearTableTransactionsInDatabase();
  void InsertTransactionsToTableTransactionsInDatabase(TransactionRepository&& repository);
  void InsertTransactionToTableTransactionsInDatabase(Transaction&& transaction);

  void CreateTableAccountsInDatabase();
  void ClearTableAccountsInDatabase();
  void InsertAccountsToTableAccountsInDatabase(AccountRepository&& repository);
  void InsertAccountToTableAccountsInDatabase(Account&& account);
  std::tuple<bool, int, Account> FindAccountByNameInTableAccountsInDatabase(const std::string& name);
  void FindAccountByNameInTableAccountsInDatabaseUpdateName(const std::string& account_name, const std::string& name);
  void FindAccountByNameInTableAccountsInDatabaseUpdateAmount(const std::string& account_name, const double amount);
  void FindAccountByNameInTableAccountsInDatabaseUpdateCurrency(const std::string& account_name, Currency&& currency);

  void CreateTableCategoriesInDatabase();
  void ClearTableCategoriesInDatabase();
  void InsertCategoriesToTableCategoriesInDatabase(CategoryRepository&& repository);
  void InsertCategoryToTableCategoriesInDatabase(Category&& category);
  std::tuple<bool, int, Category, int> FindCategoryByNameInTableCategoriesInDatabase(const std::string& name);
  void FindCategoryByNameInTableCategoriesInDatabaseUpdateName(const std::string& category_name, const std::string& name);

  void CreateTableCurrenciesInDatabase();
  void ClearTableCurrenciesInDatabase();
  void InsertCurrenciesToTableCurrenciesInDatabase(CurrencyRepository&& repository);
  void InsertCurrencyToTableCurrenciesInDatabase(Currency&& currency);
  std::tuple<bool, int, Currency> FindCurrencyByNameInTableCurrenciesInDatabase(const std::string& name);
  std::tuple<bool, int, Currency> FindCurrencyByCodeInTableCurrenciesInDatabase(const std::string& code);

  void CreateTableDescriptionsInDatabase();
  void ClearTableDescriptionsInDatabase();
  void InsertDescriptionsToTableDescriptionsInDatabase(DescriptionRepository&& repository);
  void InsertDescriptionToTableDescriptionsInDatabase(Description&& description);
  std::tuple<bool, int, Description, int> FindDescriptionByNameInTableDescriptionsInDatabase(const std::string& name);

  void CreateTablePayeesInDatabase();
  void ClearTablePayeesInDatabase();
  void InsertPayeesToTablePayeesInDatabase(PayeeRepository&& repository);
  void InsertPayeeToTablePayeesInDatabase(Payee&& payee);
  std::tuple<bool, int, Payee, int> FindPayeeByNameInTablePayeesInDatabase(const std::string& name);

  void CreateTableCommentsInDatabase();
  void ClearTableCommentsInDatabase();
  void InsertCommentsToTableCommentsInDatabase(CommentRepository&& repository);
  void InsertCommentToTableCommentsInDatabase(Comment&& comment);
  std::tuple<bool, int, Comment, int> FindCommentByNameInTableCommentsInDatabase(const std::string& name);

  void CreateTableTagsInDatabase();
  void ClearTableTagsInDatabase();
  void InsertTagsToTableTagsInDatabase(TagRepository&& repository);
  void InsertTagToTableTagsInDatabase(Tag&& tag);
  std::tuple<bool, int, Tag, int> FindTagByNameInTableTagsInDatabase(const std::string& name);
  void FindTagByNameInTableTagsInDatabaseUpdateName(const std::string& tag_name, const std::string& name);

  bool CheckTableForExistenceInDatabase(const std::string& table);
  void CreateTableInDatabase(const std::string& table);
  void ClearTableInDatabase(const std::string& table);
private:
  char* database_error_;
  int database_status_;
  sqlite3* database_;
  sqlite3_stmt* database_stmt_;
};

#endif  //  HOMEBOOKKEEPING_2BUSINESSLOGIC_DATABASEMANAGER_H_
