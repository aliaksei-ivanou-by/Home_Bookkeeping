#ifndef HOMEBOOKKEEPING_2BUSINESSLOGIC_DATABASEMANAGER_H_
#define HOMEBOOKKEEPING_2BUSINESSLOGIC_DATABASEMANAGER_H_

#include "lib/sqlite/sqlite3.h"
#include "lib/logger/Log.h"
#include "lib/logger/Initializers/RollingFileInitializer.h"

#include "include/1_DataAccess/AccountRepository.h"
#include "include/1_DataAccess/CategoryRepository.h"
#include "include/1_DataAccess/CommentRepository.h"
#include "include/1_DataAccess/CurrencyRepository.h"
#include "include/1_DataAccess/DescriptionRepository.h"
#include "include/1_DataAccess/PayeeRepository.h"
#include "include/1_DataAccess/TagRepository.h"
#include "include/1_DataAccess/TransactionRepository.h"

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

  void CreateTableTransactionsInDatabase();
  void ClearTableTransactionsInDatabase();
  void InsertTransactionToTableTransactionsInDatabase(Transaction&& transaction);
  void InsertTransactionsToTableTransactionsInDatabase(TransactionRepository&& repository);
  std::tuple<bool, int, Transaction> FindTransactionInTableTransactionsInDatabase(const int id);
  void RemoveTransactionFromTableTransactionsInDatabase(const int id);

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

  void CreateTableCategoriesInDatabase();
  void ClearTableCategoriesInDatabase();
  void InsertCategoryToTableCategoriesInDatabase(Category&& category);
  void InsertCategoriesToTableCategoriesInDatabase(CategoryRepository&& repository);
  std::tuple<bool, int, Category, int> FindCategoryInTableCategoriesInDatabase(const std::string& model_name);
  void SetCategoryName(const std::string& model_name, const std::string& name);
  std::string GetCategoryName(const std::string& model_name);
  void RemoveCategoryFromTableCategoriesInDatabase(const std::string& model_name);

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

  void CreateTableDescriptionsInDatabase();
  void ClearTableDescriptionsInDatabase();
  void InsertDescriptionToTableDescriptionsInDatabase(Description&& description);
  void InsertDescriptionsToTableDescriptionsInDatabase(DescriptionRepository&& repository);
  std::tuple<bool, int, Description, int> FindDescriptionInTableDescriptionsInDatabase(const std::string& model_name);
  void SetDescriptionName(const std::string& model_name, const std::string& name);
  std::string GetDescriptionName(const std::string& model_name);
  void RemoveDescriptionFromTableDescriptionsInDatabase(const std::string& model_name);

  void CreateTablePayeesInDatabase();
  void ClearTablePayeesInDatabase();
  void InsertPayeeToTablePayeesInDatabase(Payee&& payee);
  void InsertPayeesToTablePayeesInDatabase(PayeeRepository&& repository);
  std::tuple<bool, int, Payee, int> FindPayeeInTablePayeesInDatabase(const std::string& model_name);
  void SetPayeeName(const std::string& model_name, const std::string& name);
  std::string GetPayeeName(const std::string& model_name);
  void RemovePayeeFromTablePayeesInDatabase(const std::string& model_name);

  void CreateTableCommentsInDatabase();
  void ClearTableCommentsInDatabase();
  void InsertCommentToTableCommentsInDatabase(Comment&& comment);
  void InsertCommentsToTableCommentsInDatabase(CommentRepository&& repository);
  std::tuple<bool, int, Comment, int> FindCommentInTableCommentsInDatabase(const std::string& model_name);
  void SetCommentName(const std::string& model_name, const std::string& name);
  std::string GetCommentName(const std::string& model_name);
  void RemoveCommentFromTableCommentsInDatabase(const std::string& model_name);

  void CreateTableTagsInDatabase();
  void ClearTableTagsInDatabase();
  void InsertTagToTableTagsInDatabase(Tag&& tag);
  void InsertTagsToTableTagsInDatabase(TagRepository&& repository);
  std::tuple<bool, int, Tag, int> FindTagInTableTagsInDatabase(const std::string& model_name);
  void SetTagName(const std::string& model_name, const std::string& name);
  std::string GetTagName(const std::string& model_name);
  void RemoveTagFromTableTagsInDatabase(const std::string& model_name);
private:
  char* database_error_;
  int database_status_;
  sqlite3* database_;
  sqlite3_stmt* database_stmt_;
};

#endif
