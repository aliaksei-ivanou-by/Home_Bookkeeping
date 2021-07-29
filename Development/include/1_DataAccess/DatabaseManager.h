#ifndef HOMEBOOKKEEPING_1DATAACCESS_DATABASEMANAGER_H_
#define HOMEBOOKKEEPING_1DATAACCESS_DATABASEMANAGER_H_

#include "lib/sqlite/sqlite3.h"

#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>

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
