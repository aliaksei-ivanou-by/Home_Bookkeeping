#ifndef HOMEBOOKKEEPING_2BUSINESSLOGIC_DATABASEMANAGER_H_
#define HOMEBOOKKEEPING_2BUSINESSLOGIC_DATABASEMANAGER_H_

#include "home_bookkeeping/1_DataAccess/AccountRepository.h"
#include "home_bookkeeping/1_DataAccess/CategoryRepository.h"
#include "home_bookkeeping/1_DataAccess/CommentRepository.h"
#include "home_bookkeeping/1_DataAccess/CurrencyRepository.h"
#include "home_bookkeeping/1_DataAccess/DescriptionRepository.h"
#include "home_bookkeeping/1_DataAccess/PayeeRepository.h"
#include "home_bookkeeping/1_DataAccess/TagRepository.h"
#include "home_bookkeeping/1_DataAccess/TransactionRepository.h"

#include "home_bookkeeping/lib/sqlite/sqlite3.h"
#include "home_bookkeeping/lib/logger/Log.h"
#include "home_bookkeeping/lib/logger/Initializers/RollingFileInitializer.h"

class DatabaseManager
{
public:
  DatabaseManager();
  ~DatabaseManager();

  void CreateTableTransactionsInDatabase(TransactionRepository&& repository);
  void RemoveTableTransactionsInDatabase(TransactionRepository&& repository);
  void InsertTransactionsToTableTransactionsInDatabase(TransactionRepository&& repository);
  void SaveToDatabaseTransactions(TransactionRepository&& repository);

  void CreateTableAccountsInDatabase(AccountRepository&& repository);
  void RemoveTableAccountsInDatabase(AccountRepository&& repository);
  void InsertAccountsToTableAccountsInDatabase(AccountRepository&& repository);
  void SaveToDatabaseAccounts(AccountRepository&& repository);

  void CreateTableCategoriesInDatabase(CategoryRepository&& repository);
  void RemoveTableCategoriesInDatabase(CategoryRepository&& repository);
  void InsertCategoriesToTableCategoriesInDatabase(CategoryRepository&& repository);
  void SaveToDatabaseCategories(CategoryRepository&& repository);

  void CreateTableCurrenciesInDatabase(CurrencyRepository&& repository);
  void RemoveTableCurrenciesInDatabase(CurrencyRepository&& repository);
  void InsertCurrenciesToTableCurrenciesInDatabase(CurrencyRepository&& repository);
  void SaveToDatabaseCurrencies(CurrencyRepository&& repository);

  void CreateTableDescriptionsInDatabase(DescriptionRepository&& repository);
  void RemoveTableDescriptionsInDatabase(DescriptionRepository&& repository);
  void InsertDescriptionsToTableDescriptionsInDatabase(DescriptionRepository&& repository);
  void SaveToDatabaseDescriptions(DescriptionRepository&& repository);

  void CreateTablePayeesInDatabase(PayeeRepository&& repository);
  void RemoveTablePayeesInDatabase(PayeeRepository&& repository);
  void InsertPayeesToTablePayeesInDatabase(PayeeRepository&& repository);
  void SaveToDatabasePayees(PayeeRepository&& repository);

  void CreateTableCommentsInDatabase(CommentRepository&& repository);
  void RemoveTableCommentsInDatabase(CommentRepository&& repository);
  void InsertCommentsToTableCommentsInDatabase(CommentRepository&& repository);
  void SaveToDatabaseComments(CommentRepository&& repository);

  void CreateTableTagsInDatabase(TagRepository&& repository);
  void RemoveTableTagsInDatabase(TagRepository&& repository);
  void InsertTagsToTableTagsInDatabase(TagRepository&& repository);
  void SaveToDatabaseTags(TagRepository&& repository);
private:
  char* database_error_;
  int database_status_;
  sqlite3* database_;
  sqlite3_stmt* database_stmt_;
};

#endif  //  HOMEBOOKKEEPING_2BUSINESSLOGIC_DATABASEMANAGER_H_
