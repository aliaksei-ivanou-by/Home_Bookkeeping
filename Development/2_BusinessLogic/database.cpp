#include "home_bookkeeping/2_BusinessLogic/FinanceRepository.h"

//  Class member function
//  Save to database transaction repository
void FinanceRepository::SaveToDatabaseTransactions(std::ostream& output_stream) const
{
  char* err = 0;
  int rc = 0;
  rc = sqlite3_exec(database_, transaction_repository_.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    output_stream << "error: " << err << '\n';
  }
  rc = sqlite3_exec(database_, transaction_repository_.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    output_stream << "error: " << err << '\n';
  }
  size_t j = 0;
  for (auto i = transaction_repository_.Begin(); i != transaction_repository_.End(); ++i)
  {
    std::string str = transaction_repository_.MakeCommandToInsertRepositoryToDatabase(j, i);
    rc = sqlite3_exec(database_, str.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
      output_stream << "insert error: " << err << '\n';
    }
    ++j;
  }
}

//  Class member function
//  Save to database account repository
void FinanceRepository::SaveToDatabaseAccounts(std::ostream& output_stream) const
{
  char* err = 0;
  int rc = 0;
  rc = sqlite3_exec(database_, account_repository_.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    output_stream << "error: " << err << '\n';
  }
  rc = sqlite3_exec(database_, account_repository_.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    output_stream << "error: " << err << '\n';
  }
  size_t j = 0;
  for (auto i = account_repository_.Begin(); i != account_repository_.End(); ++i)
  {
    std::string str = account_repository_.MakeCommandToInsertRepositoryToDatabase(j, i);
    rc = sqlite3_exec(database_, str.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
      output_stream << "insert error: " << err << '\n';
    }
    ++j;
  }
}

