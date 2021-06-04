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
//      calculate rows with data in table
//      create all tables in database
//      check table for existence in database
//      create table in database
//      remove table from database
//      create table 'Transactions' in database
//      remove table 'Transactions' from database
//      insert transactions to table 'Transactions' in database
//      insert one transaction to table 'Transactions' in database
//      create table 'Accounts' in database
//      remove table 'Accounts' from database
//      insert accounts to table 'Accounts' in database
//      insert one account to table 'Accounts' in database
//      create table 'Categories' in database
//      remove table 'Categories' from database
//      insert categories to table 'Categories' in database
//      insert one category to table 'Categories' in database
//      create table 'Currencies' in database
//      remove table 'Currencies' from database
//      insert currencies to table 'Currencies' in database
//      insert one currency to table 'Currencies' in database
//      create table 'Descriptions' in database
//      remove table 'Descriptions' from database
//      insert descriptions to table 'Descriptions' in database
//      insert one description to table 'Descriptions' in database
//      create table 'Payees' in database
//      remove table 'Payees' from database
//      insert payees to table 'Payees' in database
//      insert one payee to table 'Payees' in database
//      create table 'Comments' in database
//      remove table 'Comments' from database
//      insert comments to table 'Comments' in database
//      insert one comment to table 'Comments' in database
//      create table 'Tags' in database
//      remove table 'Tags' from database
//      insert tags to table 'Tags' in database
//      insert one tag to table 'Tags' in database
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

  void CreateTableTransactionsInDatabase();
  void RemoveTableTransactionsFromDatabase(TransactionRepository&& repository);
  void InsertTransactionsToTableTransactionsInDatabase(TransactionRepository&& repository);
  void InsertTransactionToTableTransactionsInDatabase(Transaction&& transaction);

  void CreateTableAccountsInDatabase();
  void RemoveTableAccountsFromDatabase();
  void InsertAccountsToTableAccountsInDatabase(AccountRepository&& repository);
  void InsertAccountToTableAccountsInDatabase(Account&& account);

  void CreateTableCategoriesInDatabase();
  void RemoveTableCategoriesFromDatabase(CategoryRepository&& repository);
  void InsertCategoriesToTableCategoriesInDatabase(CategoryRepository&& repository);
  void InsertCategoryToTableCategoriesInDatabase(Category&& category);

  void CreateTableCurrenciesInDatabase();
  void RemoveTableCurrenciesFromDatabase(CurrencyRepository&& repository);
  void InsertCurrenciesToTableCurrenciesInDatabase(CurrencyRepository&& repository);
  void InsertCurrencyToTableCurrenciesInDatabase(Currency&& currency);

  void CreateTableDescriptionsInDatabase();
  void RemoveTableDescriptionsFromDatabase(DescriptionRepository&& repository);
  void InsertDescriptionsToTableDescriptionsInDatabase(DescriptionRepository&& repository);
  void InsertDescriptionToTableDescriptionsInDatabase(Description&& description);

  void CreateTablePayeesInDatabase();
  void RemoveTablePayeesFromDatabase(PayeeRepository&& repository);
  void InsertPayeesToTablePayeesInDatabase(PayeeRepository&& repository);
  void InsertPayeeToTablePayeesInDatabase(Payee&& payee);

  void CreateTableCommentsInDatabase();
  void RemoveTableCommentsFromDatabase(CommentRepository&& repository);
  void InsertCommentsToTableCommentsInDatabase(CommentRepository&& repository);
  void InsertCommentToTableCommentsInDatabase(Comment&& comment);

  void CreateTableTagsInDatabase();
  void RemoveTableTagsFromDatabase(TagRepository&& repository);
  void InsertTagsToTableTagsInDatabase(TagRepository&& repository);
  void InsertTagToTableTagsInDatabase(Tag&& tag);
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
