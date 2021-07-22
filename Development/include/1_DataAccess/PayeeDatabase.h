#ifndef HOMEBOOKKEEPING_1DATAACCESS_PAYEEDATABASE_H_
#define HOMEBOOKKEEPING_1DATAACCESS_PAYEEDATABASE_H_

#include "include/1_DataAccess/DatabaseManager.h"
#include "include/1_DataAccess/PayeeRepository.h"

class PayeeDatabase
{
public:
  PayeeDatabase() = delete;
  PayeeDatabase(DatabaseManager* database_manager);
  void CreateTablePayeesInDatabase();
  void ClearTablePayeesInDatabase();
  void InsertPayeeToTablePayeesInDatabase(Payee&& payee);
  void InsertPayeesToTablePayeesInDatabase(PayeeRepository&& repository);
  std::tuple<bool, int, Payee, int> FindPayeeInTablePayeesInDatabase(const std::string& model_name);
  void SetPayeeName(const std::string& model_name, const std::string& name);
  std::string GetPayeeName(const std::string& model_name);
  void RemovePayeeFromTablePayeesInDatabase(const std::string& model_name);
private:
  DatabaseManager* database_manager_;
};

#endif