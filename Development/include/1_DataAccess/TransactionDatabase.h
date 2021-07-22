#ifndef HOMEBOOKKEEPING_1DATAACCESS_TRANSACTIONDATABASE_H_
#define HOMEBOOKKEEPING_1DATAACCESS_TRANSACTIONDATABASE_H_

#include "include/1_DataAccess/DatabaseManager.h"
#include "include/1_DataAccess/TransactionRepository.h"
#include "include/1_DataAccess/AccountDatabase.h"
#include "include/1_DataAccess/CategoryDatabase.h"
#include "include/1_DataAccess/CommentDatabase.h"
#include "include/1_DataAccess/CurrencyDatabase.h"
#include "include/1_DataAccess/DescriptionDatabase.h"
#include "include/1_DataAccess/PayeeDatabase.h"
#include "include/1_DataAccess/TagDatabase.h"

class TransactionDatabase
{
public:
  TransactionDatabase() = delete;
  TransactionDatabase(DatabaseManager* database_manager,
    CurrencyDatabase* currency_database,
    AccountDatabase* account_database,
    CategoryDatabase* category_database,
    CommentDatabase* comment_database,
    DescriptionDatabase* description_database,
    PayeeDatabase* payee_database,
    TagDatabase* tag_database);
  void CreateTableTransactionsInDatabase();
  void ClearTableTransactionsInDatabase();
  void InsertTransactionToTableTransactionsInDatabase(Transaction&& transaction);
  void InsertTransactionsToTableTransactionsInDatabase(TransactionRepository&& repository);
  std::tuple<bool, int, Transaction> FindTransactionInTableTransactionsInDatabase(const int id);
  void RemoveTransactionFromTableTransactionsInDatabase(const int id);
private:
  DatabaseManager* database_manager_;
  AccountDatabase* account_database_;
  CategoryDatabase* category_database_;
  CommentDatabase* comment_database_;
  CurrencyDatabase* currency_database_;
  DescriptionDatabase* description_database_;
  PayeeDatabase* payee_database_;
  TagDatabase* tag_database_;
};

#endif