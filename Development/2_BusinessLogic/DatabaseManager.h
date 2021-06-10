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
//      remove all tables from database
//      check table for existence in database
//      create table in database
//      remove table from database
//    transactions:
//      create table 'Transactions' in database
//      remove table 'Transactions' from database
//      insert transactions to table 'Transactions' in database
//      insert one transaction to table 'Transactions' in database
//    accounts:
//      create table 'Accounts' in database
//      remove table 'Accounts' from database
//      insert accounts to table 'Accounts' in database
//      insert one account to table 'Accounts' in database
//    categories:
//      create table 'Categories' in database
//      remove table 'Categories' from database
//      insert categories to table 'Categories' in database
//      insert one category to table 'Categories' in database
//      find category with definite name in table 'Categories' in database
//    currencies:
//      create table 'Currencies' in database
//      remove table 'Currencies' from database
//      insert currencies to table 'Currencies' in database
//      insert one currency to table 'Currencies' in database
//    descriptions:
//      create table 'Descriptions' in database
//      remove table 'Descriptions' from database
//      insert descriptions to table 'Descriptions' in database
//      insert one description to table 'Descriptions' in database
//      find description with definite name in table 'Descriptions' in database
//    payees:
//      create table 'Payees' in database
//      remove table 'Payees' from database
//      insert payees to table 'Payees' in database
//      insert one payee to table 'Payees' in database
//      find payee with definite name in table 'Payees' in database
//    comments:
//      create table 'Comments' in database
//      remove table 'Comments' from database
//      insert comments to table 'Comments' in database
//      insert one comment to table 'Comments' in database
//      find comment with definite name in table 'Comments' in database
//    tags:
//      create table 'Tags' in database
//      remove table 'Tags' from database
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
  void RemoveAllTablesFromDatabase();

  void CreateTableTransactionsInDatabase();
  void RemoveTableTransactionsFromDatabase();
  void InsertTransactionsToTableTransactionsInDatabase(TransactionRepository&& repository);
  void InsertTransactionToTableTransactionsInDatabase(Transaction&& transaction);

  void CreateTableAccountsInDatabase();
  void RemoveTableAccountsFromDatabase();
  void InsertAccountsToTableAccountsInDatabase(AccountRepository&& repository);
  void InsertAccountToTableAccountsInDatabase(Account&& account);

  void CreateTableCategoriesInDatabase();
  void RemoveTableCategoriesFromDatabase();
  void InsertCategoriesToTableCategoriesInDatabase(CategoryRepository&& repository);
  void InsertCategoryToTableCategoriesInDatabase(Category&& category);
  std::tuple<bool, int, Category, int> FindCategoryByNameInTableCategoriesInDatabase(const std::string& name);

  void CreateTableCurrenciesInDatabase();
  void RemoveTableCurrenciesFromDatabase();
  void InsertCurrenciesToTableCurrenciesInDatabase(CurrencyRepository&& repository);
  void InsertCurrencyToTableCurrenciesInDatabase(Currency&& currency);
  std::tuple<bool, int, Currency> FindCurrencyByNameInTableCurrenciesInDatabase(const std::string& name);
  std::tuple<bool, int, Currency> FindCurrencyByCodeInTableCurrenciesInDatabase(const std::string& code);

  void CreateTableDescriptionsInDatabase();
  void RemoveTableDescriptionsFromDatabase();
  void InsertDescriptionsToTableDescriptionsInDatabase(DescriptionRepository&& repository);
  void InsertDescriptionToTableDescriptionsInDatabase(Description&& description);
  std::tuple<bool, int, Description, int> FindDescriptionByNameInTableDescriptionsInDatabase(const std::string& name);

  void CreateTablePayeesInDatabase();
  void RemoveTablePayeesFromDatabase();
  void InsertPayeesToTablePayeesInDatabase(PayeeRepository&& repository);
  void InsertPayeeToTablePayeesInDatabase(Payee&& payee);
  std::tuple<bool, int, Payee, int> FindPayeeByNameInTablePayeesInDatabase(const std::string& name);

  void CreateTableCommentsInDatabase();
  void RemoveTableCommentsFromDatabase();
  void InsertCommentsToTableCommentsInDatabase(CommentRepository&& repository);
  void InsertCommentToTableCommentsInDatabase(Comment&& comment);
  std::tuple<bool, int, Comment, int> FindCommentByNameInTableCommentsInDatabase(const std::string& name);

  void CreateTableTagsInDatabase();
  void RemoveTableTagsFromDatabase();
  void InsertTagsToTableTagsInDatabase(TagRepository&& repository);
  void InsertTagToTableTagsInDatabase(Tag&& tag);
  std::tuple<bool, int, Tag, int> FindTagByNameInTableTagsInDatabase(const std::string& name);

  bool CheckTableForExistenceInDatabase(const std::string& table);
  void CreateTableInDatabase(const std::string& table);
  void RemoveTableFromDatabase(const std::string& table);
private:
  char* database_error_;
  int database_status_;
  sqlite3* database_;
  sqlite3_stmt* database_stmt_;
};

#endif  //  HOMEBOOKKEEPING_2BUSINESSLOGIC_DATABASEMANAGER_H_
