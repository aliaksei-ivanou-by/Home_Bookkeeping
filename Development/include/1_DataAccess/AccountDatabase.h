#ifndef HOMEBOOKKEEPING_1DATAACCESS_ACCOUNTDATABASE_H_
#define HOMEBOOKKEEPING_1DATAACCESS_ACCOUNTDATABASE_H_

#include "include/1_DataAccess/DatabaseManager.h"
#include "include/1_DataAccess/AccountRepository.h"
#include "include/1_DataAccess/CurrencyRepository.h"
#include "include/1_DataAccess/CurrencyDatabase.h"

class AccountDatabase
{
public:
  AccountDatabase() = delete;
  AccountDatabase(DatabaseManager* database_manager, CurrencyDatabase* currency_database);
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
private:
  DatabaseManager* database_manager_;
  CurrencyDatabase* currency_database_;
};

#endif