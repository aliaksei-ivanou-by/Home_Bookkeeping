#include "home_bookkeeping/2_BusinessLogic/DatabaseManager.h"

DatabaseManager::DatabaseManager():
  database_error_{ 0 },
  database_status_{ 0 },
  database_{ nullptr },
  database_stmt_{ nullptr }
{
  sqlite3_open("database.db", &database_);
  PLOG_INFO << "Open database";
}

DatabaseManager::~DatabaseManager()
{
  sqlite3_close(database_);
  PLOG_INFO << "Close database";
}

void DatabaseManager::CreateTableTransactionsInDatabase(TransactionRepository&& repository)
{
  database_status_ = sqlite3_exec(database_, repository.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Create table 'Transactions' in database";
}

void DatabaseManager::RemoveTableTransactionsInDatabase(TransactionRepository&& repository)
{
  database_status_ = sqlite3_exec(database_, repository.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Remove table 'Transactions' in database if exists";
}

void DatabaseManager::InsertTransactionsToTableTransactionsInDatabase(TransactionRepository&& repository)
{
  size_t j = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    database_status_ = sqlite3_exec(database_, repository.MakeCommandToInsertRepositoryToDatabase(j, i).c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    ++j;
  }
  PLOG_INFO << "Insert transactions to table 'Transactions' in database";
}

void DatabaseManager::SaveToDatabaseTransactions(TransactionRepository&& repository)
{
  RemoveTableTransactionsInDatabase(std::move(repository));
  CreateTableTransactionsInDatabase(std::move(repository));
  InsertTransactionsToTableTransactionsInDatabase(std::move(repository));
  PLOG_INFO << "Save transactions to table 'Transactions' in database";
}

void DatabaseManager::CreateTableAccountsInDatabase(AccountRepository&& repository)
{
  database_status_ = sqlite3_exec(database_, repository.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Create table 'Accounts' in database";
}

void DatabaseManager::RemoveTableAccountsInDatabase(AccountRepository&& repository)
{
  database_status_ = sqlite3_exec(database_, repository.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Remove table 'Accounts' in database if exists";
}

void DatabaseManager::InsertAccountsToTableAccountsInDatabase(AccountRepository&& repository)
{
  size_t j = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    database_status_ = sqlite3_exec(database_, repository.MakeCommandToInsertRepositoryToDatabase(j, i).c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    ++j;
  }
  PLOG_INFO << "Insert accounts to table 'Accounts' in database";
}

void DatabaseManager::SaveToDatabaseAccounts(AccountRepository&& repository)
{
  RemoveTableAccountsInDatabase(std::move(repository));
  CreateTableAccountsInDatabase(std::move(repository));
  InsertAccountsToTableAccountsInDatabase(std::move(repository));
  PLOG_INFO << "Save accounts to table 'Accounts' in database";
}

void DatabaseManager::CreateTableCategoriesInDatabase(CategoryRepository&& repository)
{
  database_status_ = sqlite3_exec(database_, repository.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Create table 'Categories' in database";
}

void DatabaseManager::RemoveTableCategoriesInDatabase(CategoryRepository&& repository)
{
  database_status_ = sqlite3_exec(database_, repository.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Remove table 'Categories' in database if exists";
}

void DatabaseManager::InsertCategoriesToTableCategoriesInDatabase(CategoryRepository&& repository)
{
  size_t j = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    database_status_ = sqlite3_exec(database_, repository.MakeCommandToInsertRepositoryToDatabase(j, i).c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    ++j;
  }
  PLOG_INFO << "Insert categories to table 'Categories' in database";
}

void DatabaseManager::SaveToDatabaseCategories(CategoryRepository&& repository)
{
  RemoveTableCategoriesInDatabase(std::move(repository));
  CreateTableCategoriesInDatabase(std::move(repository));
  InsertCategoriesToTableCategoriesInDatabase(std::move(repository));
  PLOG_INFO << "Save categories to table 'Categories' in database";
}

void DatabaseManager::CreateTableCurrenciesInDatabase(CurrencyRepository&& repository)
{
  database_status_ = sqlite3_exec(database_, repository.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Create table 'Currencies' in database";
}

void DatabaseManager::RemoveTableCurrenciesInDatabase(CurrencyRepository&& repository)
{
  database_status_ = sqlite3_exec(database_, repository.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Remove table 'Currencies' in database if exists";
}

void DatabaseManager::InsertCurrenciesToTableCurrenciesInDatabase(CurrencyRepository&& repository)
{
  size_t j = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    database_status_ = sqlite3_exec(database_, repository.MakeCommandToInsertRepositoryToDatabase(j, i).c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    ++j;
  }
  PLOG_INFO << "Insert currencies to table 'Currencies' in database";
}

void DatabaseManager::SaveToDatabaseCurrencies(CurrencyRepository&& repository)
{
  RemoveTableCurrenciesInDatabase(std::move(repository));
  CreateTableCurrenciesInDatabase(std::move(repository));
  InsertCurrenciesToTableCurrenciesInDatabase(std::move(repository));
  PLOG_INFO << "Save currencies to table 'Currencies' in database";
}

void DatabaseManager::CreateTableDescriptionsInDatabase(DescriptionRepository&& repository)
{
  database_status_ = sqlite3_exec(database_, repository.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Create table 'Descriptions' in database";
}

void DatabaseManager::RemoveTableDescriptionsInDatabase(DescriptionRepository&& repository)
{
  database_status_ = sqlite3_exec(database_, repository.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Remove table 'Descriptions' in database if exists";
}

void DatabaseManager::InsertDescriptionsToTableDescriptionsInDatabase(DescriptionRepository&& repository)
{
  size_t j = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    database_status_ = sqlite3_exec(database_, repository.MakeCommandToInsertRepositoryToDatabase(j, i).c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    ++j;
  }
  PLOG_INFO << "Insert descriptions to table 'Descriptions' in database";
}

void DatabaseManager::SaveToDatabaseDescriptions(DescriptionRepository&& repository)
{
  RemoveTableDescriptionsInDatabase(std::move(repository));
  CreateTableDescriptionsInDatabase(std::move(repository));
  InsertDescriptionsToTableDescriptionsInDatabase(std::move(repository));
  PLOG_INFO << "Save descriptions to table 'Descriptions' in database";
}

void DatabaseManager::CreateTablePayeesInDatabase(PayeeRepository&& repository)
{
  database_status_ = sqlite3_exec(database_, repository.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Create table 'Payees' in database";
}

void DatabaseManager::RemoveTablePayeesInDatabase(PayeeRepository&& repository)
{
  database_status_ = sqlite3_exec(database_, repository.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Remove table 'Payees' in database if exists";
}

void DatabaseManager::InsertPayeesToTablePayeesInDatabase(PayeeRepository&& repository)
{
  size_t j = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    database_status_ = sqlite3_exec(database_, repository.MakeCommandToInsertRepositoryToDatabase(j, i).c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    ++j;
  }
  PLOG_INFO << "Insert payees to table 'Payees' in database";
}

void DatabaseManager::SaveToDatabasePayees(PayeeRepository&& repository)
{
  RemoveTablePayeesInDatabase(std::move(repository));
  CreateTablePayeesInDatabase(std::move(repository));
  InsertPayeesToTablePayeesInDatabase(std::move(repository));
  PLOG_INFO << "Save payees to table 'Payees' in database";
}

void DatabaseManager::CreateTableCommentsInDatabase(CommentRepository&& repository)
{
  database_status_ = sqlite3_exec(database_, repository.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Create table 'Comments' in database";
}

void DatabaseManager::RemoveTableCommentsInDatabase(CommentRepository&& repository)
{
  database_status_ = sqlite3_exec(database_, repository.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Remove table 'Comments' in database if exists";
}

void DatabaseManager::InsertCommentsToTableCommentsInDatabase(CommentRepository&& repository)
{
  size_t j = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    database_status_ = sqlite3_exec(database_, repository.MakeCommandToInsertRepositoryToDatabase(j, i).c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    ++j;
  }
  PLOG_INFO << "Insert comments to table 'Comments' in database";
}

void DatabaseManager::SaveToDatabaseComments(CommentRepository&& repository)
{
  RemoveTableCommentsInDatabase(std::move(repository));
  CreateTableCommentsInDatabase(std::move(repository));
  InsertCommentsToTableCommentsInDatabase(std::move(repository));
  PLOG_INFO << "Save comments to table 'Comments' in database";
}

void DatabaseManager::CreateTableTagsInDatabase(TagRepository&& repository)
{
  database_status_ = sqlite3_exec(database_, repository.MakeCommandToCreateRepositoryInDatabase().c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Create table 'Tags' in database";
}

void DatabaseManager::RemoveTableTagsInDatabase(TagRepository&& repository)
{
  database_status_ = sqlite3_exec(database_, repository.MakeCommandToRemoveRepositoryFromDatabase().c_str(), NULL, NULL, &database_error_);
  if (database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Error: " << database_error_;
  }
  PLOG_INFO << "Remove table 'Tags' in database if exists";
}

void DatabaseManager::InsertTagsToTableTagsInDatabase(TagRepository&& repository)
{
  size_t j = 0;
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    database_status_ = sqlite3_exec(database_, repository.MakeCommandToInsertRepositoryToDatabase(j, i).c_str(), NULL, NULL, &database_error_);
    if (database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Insert Error: " << database_error_;
    }
    ++j;
  }
  PLOG_INFO << "Insert tags to table 'Tags' in database";
}

void DatabaseManager::SaveToDatabaseTags(TagRepository&& repository)
{
  RemoveTableTagsInDatabase(std::move(repository));
  CreateTableTagsInDatabase(std::move(repository));
  InsertTagsToTableTagsInDatabase(std::move(repository));
  PLOG_INFO << "Save tags to table 'Tags' in database";
}
