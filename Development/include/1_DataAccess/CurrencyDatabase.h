#ifndef HOMEBOOKKEEPING_1DATAACCESS_CURRENCYDATABASE_H_
#define HOMEBOOKKEEPING_1DATAACCESS_CURRENCYDATABASE_H_

#include "include/1_DataAccess/DatabaseManager.h"
#include "include/1_DataAccess/CurrencyRepository.h"

class CurrencyDatabase
{
public:
  CurrencyDatabase() = delete;
  CurrencyDatabase(DatabaseManager* database_manager);
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
private:
  DatabaseManager* database_manager_;
};

#endif