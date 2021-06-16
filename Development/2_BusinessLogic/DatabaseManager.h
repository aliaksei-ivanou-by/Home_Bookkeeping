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
//      find account with definite name and update name of account in table 'Accounts' in database
//      find account with definite name and update amount of account in table 'Accounts' in database
//      find account with definite name and update currency of account in table 'Accounts' in database
//      remove account with definite name from table 'Accounts' in database
//    categories:
//      create table 'Categories' in database
//      clear table 'Categories' in database
//      insert category to table 'Categories' in database
//      insert categories to table 'Categories' in database
//      find category with definite name in table 'Categories' in database
//      remove category with definite name from table 'Categories' in database
//    currencies:
//      create table 'Currencies' in database
//      clear table 'Currencies' in database
//      insert currency to table 'Currencies' in database
//      insert currencies to table 'Currencies' in database
//      remove currency with definite name from table 'Currencies' in database
//    descriptions:
//      create table 'Descriptions' in database
//      clear table 'Descriptions' in database
//      insert description to table 'Descriptions' in database
//      insert descriptions to table 'Descriptions' in database
//      find description with definite name in table 'Descriptions' in database
//      remove description with definite name from table 'Descriptions' in database
//    payees:
//      create table 'Payees' in database
//      clear table 'Payees' in database
//      insert payee to table 'Payees' in database
//      insert payees to table 'Payees' in database
//      find payee with definite name in table 'Payees' in database
//      remove payee with definite name from table 'Payees' in database
//    comments:
//      create table 'Comments' in database
//      clear table 'Comments' in database
//      insert comment to table 'Comments' in database
//      insert comments to table 'Comments' in database
//      find comment with definite name in table 'Comments' in database
//      remove comment with definite name from table 'Comments' in database
//    tags:
//      create table 'Tags' in database
//      clear table 'Tags' in database
//      insert tag to table 'Tags' in database
//      insert tags to table 'Tags' in database
//      find tag with definite name in table 'Tags' in database
//      remove tag with definite name from table 'Tags' in database
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
  bool CheckTableForExistenceInDatabase(const std::string& table);
  void CreateTableInDatabase(const std::string& table);
  void ClearTableInDatabase(const std::string& table);

  void CreateTableTransactionsInDatabase();
  void ClearTableTransactionsInDatabase();
  void InsertTransactionToTableTransactionsInDatabase(Transaction&& transaction);
  void InsertTransactionsToTableTransactionsInDatabase(TransactionRepository&& repository);
  /*std::tuple<bool, int, Transaction>*/void FindTransactionInTableTransactionsInDatabase(const int id);
  void RemoveTransactionFromTableTransactionsInDatabase(const int id);

  void CreateTableAccountsInDatabase();
  void ClearTableAccountsInDatabase();
  void InsertAccountToTableAccountsInDatabase(Account&& account);
  void InsertAccountsToTableAccountsInDatabase(AccountRepository&& repository);
  std::tuple<bool, int, Account> FindAccountInTableAccountsInDatabase(const std::string& name);
  void FindAccountInTableAccountsInDatabaseUpdateName(const std::string& account_name, const std::string& name);
  void FindAccountInTableAccountsInDatabaseUpdateAmount(const std::string& account_name, const double amount);
  void FindAccountInTableAccountsInDatabaseUpdateCurrency(const std::string& account_name, Currency&& currency);
  void RemoveAccountFromTableAccountsInDatabase(const std::string& name);

  void CreateTableCategoriesInDatabase();
  void ClearTableCategoriesInDatabase();
  void InsertCategoryToTableCategoriesInDatabase(Category&& category);
  void InsertCategoriesToTableCategoriesInDatabase(CategoryRepository&& repository);
  std::tuple<bool, int, Category, int> FindCategoryInTableCategoriesInDatabase(const std::string& name);
  void FindCategoryInTableCategoriesInDatabaseUpdateName(const std::string& category_name, const std::string& name);
  void RemoveCategoryFromTableCategoriesInDatabase(const std::string& name);

  void CreateTableCurrenciesInDatabase();
  void ClearTableCurrenciesInDatabase();
  void InsertCurrencyToTableCurrenciesInDatabase(Currency&& currency);
  void InsertCurrenciesToTableCurrenciesInDatabase(CurrencyRepository&& repository);
  std::tuple<bool, int, Currency> FindCurrencyInTableCurrenciesInDatabase(const std::string& name);
  std::tuple<bool, int, Currency> FindCurrencyByCodeInTableCurrenciesInDatabase(const std::string& code);
  void RemoveCurrencyFromTableCurrenciesInDatabase(const std::string& name);

  void CreateTableDescriptionsInDatabase();
  void ClearTableDescriptionsInDatabase();
  void InsertDescriptionToTableDescriptionsInDatabase(Description&& description);
  void InsertDescriptionsToTableDescriptionsInDatabase(DescriptionRepository&& repository);
  std::tuple<bool, int, Description, int> FindDescriptionInTableDescriptionsInDatabase(const std::string& name);
  void FindDescriptionInTableDescriptionsInDatabaseUpdateName(const std::string& model_name, const std::string& name);
  void RemoveDescriptionFromTableDescriptionsInDatabase(const std::string& name);

  void CreateTablePayeesInDatabase();
  void ClearTablePayeesInDatabase();
  void InsertPayeeToTablePayeesInDatabase(Payee&& payee);
  void InsertPayeesToTablePayeesInDatabase(PayeeRepository&& repository);
  std::tuple<bool, int, Payee, int> FindPayeeInTablePayeesInDatabase(const std::string& name);
  void FindPayeeInTablePayeesInDatabaseUpdateName(const std::string& payee_name, const std::string& name);
  void RemovePayeeFromTablePayeesInDatabase(const std::string& name);

  void CreateTableCommentsInDatabase();
  void ClearTableCommentsInDatabase();
  void InsertCommentToTableCommentsInDatabase(Comment&& comment);
  void InsertCommentsToTableCommentsInDatabase(CommentRepository&& repository);
  std::tuple<bool, int, Comment, int> FindCommentInTableCommentsInDatabase(const std::string& name);
  void FindCommentInTableCommentsInDatabaseUpdateName(const std::string& comment_name, const std::string& name);
  void RemoveCommentFromTableCommentsInDatabase(const std::string& name);

  void CreateTableTagsInDatabase();
  void ClearTableTagsInDatabase();
  void InsertTagToTableTagsInDatabase(Tag&& tag);
  void InsertTagsToTableTagsInDatabase(TagRepository&& repository);
  std::tuple<bool, int, Tag, int> FindTagInTableTagsInDatabase(const std::string& name);
  void FindTagInTableTagsInDatabaseUpdateName(const std::string& tag_name, const std::string& name);
  void RemoveTagFromTableTagsInDatabase(const std::string& name);
private:
  char* database_error_;
  int database_status_;
  sqlite3* database_;
  sqlite3_stmt* database_stmt_;
};

#endif  //  HOMEBOOKKEEPING_2BUSINESSLOGIC_DATABASEMANAGER_H_
