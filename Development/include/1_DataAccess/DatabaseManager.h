#ifndef HOMEBOOKKEEPING_1DATAACCESS_DATABASEMANAGER_H_
#define HOMEBOOKKEEPING_1DATAACCESS_DATABASEMANAGER_H_

#include "lib/sqlite/sqlite3.h"
#include "lib/logger/Log.h"
#include "lib/logger/Initializers/RollingFileInitializer.h"

#include "AccountRepository.h"
#include "CommentRepository.h"
#include "CurrencyRepository.h"
#include "TransactionRepository.h"

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

  void InsertTransactionToTableTransactionsInDatabase(Transaction&& transaction);
  void InsertTransactionsToTableTransactionsInDatabase(TransactionRepository&& repository);
  std::tuple<bool, int, Transaction> FindTransactionInTableTransactionsInDatabase(const int id);
  void RemoveTransactionFromTableTransactionsInDatabase(const int id);

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
private:
  char* database_error_;
  int database_status_;
  sqlite3* database_;
  sqlite3_stmt* database_stmt_;

  friend class ModelDatabase;
  friend class AccountDatabase;
  friend class CategoryDatabase;
  friend class CommentDatabase;
  friend class CurrencyDatabase;
  friend class DescriptionDatabase;
  friend class PayeeDatabase;
  friend class TagDatabase;
  friend class TransactionDatabase;
};

#endif
