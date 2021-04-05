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

//  Class member function
//  Save to database category repository
void FinanceRepository::SaveToDatabaseCategories(std::ostream& output_stream) const
{
  char* err = 0;
  int rc = 0;
  rc = sqlite3_exec(database_, category_repository_.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    output_stream << "error: " << err << '\n';
  }
  rc = sqlite3_exec(database_, category_repository_.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    output_stream << "error: " << err << '\n';
  }
  size_t j = 0;
  for (auto i = category_repository_.Begin(); i != category_repository_.End(); ++i)
  {
    std::string str = category_repository_.MakeCommandToInsertRepositoryToDatabase(j, i);
    rc = sqlite3_exec(database_, str.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
      output_stream << "insert error: " << err << '\n';
    }
    ++j;
  }
}

//  Class member function
//  Save to database currency repository
void FinanceRepository::SaveToDatabaseCurrencies(std::ostream& output_stream) const
{
  char* err = 0;
  int rc = 0;
  rc = sqlite3_exec(database_, currency_repository_.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    output_stream << "error: " << err << '\n';
  }
  rc = sqlite3_exec(database_, currency_repository_.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    output_stream << "error: " << err << '\n';
  }
  size_t j = 0;
  for (auto i = currency_repository_.Begin(); i != currency_repository_.End(); ++i)
  {
    std::string str = currency_repository_.MakeCommandToInsertRepositoryToDatabase(j, i);
    rc = sqlite3_exec(database_, str.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
      output_stream << "insert error: " << err << '\n';
    }
    ++j;
  }
}

//  Class member function
//  Save to database description repository
void FinanceRepository::SaveToDatabaseDescriptions(std::ostream& output_stream) const
{
  char* err = 0;
  int rc = 0;
  rc = sqlite3_exec(database_, description_repository_.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    output_stream << "error: " << err << '\n';
  }
  rc = sqlite3_exec(database_, description_repository_.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    output_stream << "error: " << err << '\n';
  }
  size_t j = 0;
  for (auto i = description_repository_.Begin(); i != description_repository_.End(); ++i)
  {
    std::string str = description_repository_.MakeCommandToInsertRepositoryToDatabase(j, i);
    rc = sqlite3_exec(database_, str.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
      output_stream << "insert error: " << err << '\n';
    }
    ++j;
  }
}

//  Class member function
//  Save to database payee repository
void FinanceRepository::SaveToDatabasePayees(std::ostream& output_stream) const
{
  char* err = 0;
  int rc = 0;
  rc = sqlite3_exec(database_, payee_repository_.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    output_stream << "error: " << err << '\n';
  }
  rc = sqlite3_exec(database_, payee_repository_.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    output_stream << "error: " << err << '\n';
  }
  size_t j = 0;
  for (auto i = payee_repository_.Begin(); i != payee_repository_.End(); ++i)
  {
    std::string str = payee_repository_.MakeCommandToInsertRepositoryToDatabase(j, i);
    rc = sqlite3_exec(database_, str.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
      output_stream << "insert error: " << err << '\n';
    }
    ++j;
  }
}

//  Class member function
//  Save to database comment repository
void FinanceRepository::SaveToDatabaseComments(std::ostream& output_stream) const
{
  char* err = 0;
  int rc = 0;
  rc = sqlite3_exec(database_, comment_repository_.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    output_stream << "error: " << err << '\n';
  }
  rc = sqlite3_exec(database_, comment_repository_.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    output_stream << "error: " << err << '\n';
  }
  size_t j = 0;
  for (auto i = comment_repository_.Begin(); i != comment_repository_.End(); ++i)
  {
    std::string str = comment_repository_.MakeCommandToInsertRepositoryToDatabase(j, i);
    rc = sqlite3_exec(database_, str.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
      output_stream << "insert error: " << err << '\n';
    }
    ++j;
  }
}

//  Class member function
//  Save to database tag repository
void FinanceRepository::SaveToDatabaseTags(std::ostream& output_stream) const
{
  char* err = 0;
  int rc = 0;
  rc = sqlite3_exec(database_, tag_repository_.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    output_stream << "error: " << err << '\n';
  }
  rc = sqlite3_exec(database_, tag_repository_.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    output_stream << "error: " << err << '\n';
  }
  size_t j = 0;
  for (auto i = tag_repository_.Begin(); i != tag_repository_.End(); ++i)
  {
    std::string str = tag_repository_.MakeCommandToInsertRepositoryToDatabase(j, i);
    rc = sqlite3_exec(database_, str.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
      output_stream << "insert error: " << err << '\n';
    }
    ++j;
  }
}