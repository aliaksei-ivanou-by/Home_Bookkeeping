#include "include/1_DataAccess/TransactionDatabase.h"

TransactionDatabase::TransactionDatabase(
                            DatabaseManager* database_manager,
                            CurrencyDatabase* currency_database,
                            AccountDatabase* account_database,
                            CategoryDatabase* category_database,
                            CommentDatabase* comment_database,
                            DescriptionDatabase* description_database,
                            PayeeDatabase* payee_database,
                            TagDatabase* tag_database
)
{
  database_manager_ = database_manager;
  currency_database_ = currency_database;
  account_database_ = account_database;
  category_database_ = category_database;
  comment_database_ = comment_database;
  description_database_ = description_database;
  payee_database_ = payee_database;
  tag_database_ = tag_database;
}

void TransactionDatabase::CreateTableTransactionsInDatabase()
{
  database_manager_->CreateTableInDatabase("Transactions");
}

void TransactionDatabase::ClearTableTransactionsInDatabase()
{
  database_manager_->ClearTableInDatabase("Transactions");
}

void TransactionDatabase::InsertTransactionToTableTransactionsInDatabase(Transaction&& transaction)
{
  // Check account_from
  bool transaction_account_from_in_database;
  int transaction_account_from_id;
  std::tie(transaction_account_from_in_database, transaction_account_from_id, std::ignore) = account_database_->FindAccountInTableAccountsInDatabase(transaction.GetAccountFrom().GetName());
  if (!transaction_account_from_in_database)
  {
    account_database_->InsertAccountToTableAccountsInDatabase(transaction.GetAccountFrom());
     std::tie(transaction_account_from_in_database, transaction_account_from_id, std::ignore) = account_database_->FindAccountInTableAccountsInDatabase(transaction.GetAccountFrom().GetName());
  }
  // Check account_to
  bool transaction_account_to_in_database;
  int transaction_account_to_id;
  std::tie(transaction_account_to_in_database, transaction_account_to_id, std::ignore) = account_database_->FindAccountInTableAccountsInDatabase(transaction.GetAccountTo().GetName());
  if (!transaction_account_to_in_database)
  {
    account_database_->InsertAccountToTableAccountsInDatabase(transaction.GetAccountTo());
    std::tie(transaction_account_to_in_database, transaction_account_to_id, std::ignore) = account_database_->FindAccountInTableAccountsInDatabase(transaction.GetAccountTo().GetName());
  }
  // Check category
  bool transaction_category_in_database;
  int transaction_category_id;
  std::tie(transaction_category_in_database, transaction_category_id, std::ignore, std::ignore) = category_database_->FindCategoryInTableCategoriesInDatabase(transaction.GetCategory().GetName());
  if (!transaction_category_in_database)
  {
    category_database_->InsertCategoryToTableCategoriesInDatabase(transaction.GetCategory());
    std::tie(transaction_category_in_database, transaction_category_id, std::ignore, std::ignore) = category_database_->FindCategoryInTableCategoriesInDatabase(transaction.GetCategory().GetName());
  }
  // Check comment
  bool transaction_comment_in_database;
  int transaction_comment_id;
  std::tie(transaction_comment_in_database, transaction_comment_id, std::ignore, std::ignore) = comment_database_->FindCommentInTableCommentsInDatabase(transaction.GetComment().GetName());
  if (!transaction_category_in_database)
  {
    comment_database_->InsertCommentToTableCommentsInDatabase(transaction.GetComment());
    std::tie(transaction_comment_in_database, transaction_comment_id, std::ignore, std::ignore) = comment_database_->FindCommentInTableCommentsInDatabase(transaction.GetComment().GetName());
  }
  // Check currency
  bool transaction_currency_in_database;
  int transaction_currency_id;
  std::tie(transaction_currency_in_database, transaction_currency_id, std::ignore) = currency_database_->FindCurrencyInTableCurrenciesInDatabase(transaction.GetCurrency().GetName());
  if (!transaction_category_in_database)
  {
    currency_database_->InsertCurrencyToTableCurrenciesInDatabase(transaction.GetCurrency());
    std::tie(transaction_currency_in_database, transaction_currency_id, std::ignore) = currency_database_->FindCurrencyInTableCurrenciesInDatabase(transaction.GetCurrency().GetName());
  }
  // Check description
  bool transaction_description_in_database;
  int transaction_description_id;
  std::tie(transaction_description_in_database, transaction_description_id, std::ignore, std::ignore) = description_database_->FindDescriptionInTableDescriptionsInDatabase(transaction.GetDescription().GetName());
  if (!transaction_description_in_database)
  {
    description_database_->InsertDescriptionToTableDescriptionsInDatabase(transaction.GetDescription());
    std::tie(transaction_description_in_database, transaction_description_id, std::ignore, std::ignore) = description_database_->FindDescriptionInTableDescriptionsInDatabase(transaction.GetDescription().GetName());
  }
  // Check payee
  bool transaction_payee_in_database;
  int transaction_payee_id;
  std::tie(transaction_payee_in_database, transaction_payee_id, std::ignore, std::ignore) = payee_database_->FindPayeeInTablePayeesInDatabase(transaction.GetPayee().GetName());
  if (!transaction_payee_in_database)
  {
    payee_database_->InsertPayeeToTablePayeesInDatabase(transaction.GetPayee());
    std::tie(transaction_payee_in_database, transaction_payee_id, std::ignore, std::ignore) = payee_database_->FindPayeeInTablePayeesInDatabase(transaction.GetPayee().GetName());
  }
  // Check tag
  bool transaction_tag_in_database;
  int transaction_tag_id;
  std::tie(transaction_tag_in_database, transaction_tag_id, std::ignore, std::ignore) = tag_database_->FindTagInTableTagsInDatabase(transaction.GetTag().GetName());
  if (!transaction_tag_in_database)
  {
    tag_database_->InsertTagToTableTagsInDatabase(transaction.GetTag());
    std::tie(transaction_tag_in_database, transaction_tag_id, std::ignore, std::ignore) = tag_database_->FindTagInTableTagsInDatabase(transaction.GetTag().GetName());
  }
  // Check amount_account_from and amount_account_to
  NUM transaction_amount_account_from;
  NUM transaction_amount_account_to;
  if (transaction.GetType() == kEnumType::Expense)
  {
    transaction_amount_account_from = account_database_->GetAccountAmount(transaction.GetAccountFrom().GetName()) - transaction.GetAmount();
    transaction_amount_account_to = account_database_->GetAccountAmount(transaction.GetAccountTo().GetName()) - transaction.GetAmount();
    transaction.SetAmountAccountFrom(transaction_amount_account_from);
    transaction.SetAmountAccountTo(transaction_amount_account_to);
    account_database_->SetAccountAmount(transaction.GetAccountFrom().GetName(), transaction_amount_account_from);
    account_database_->SetAccountAmount(transaction.GetAccountTo().GetName(), transaction_amount_account_to);
  }
  if (transaction.GetType() == kEnumType::Income)
  {
    transaction_amount_account_from = account_database_->GetAccountAmount(transaction.GetAccountFrom().GetName()) + transaction.GetAmount();
    transaction_amount_account_to = account_database_->GetAccountAmount(transaction.GetAccountTo().GetName()) + transaction.GetAmount();
    transaction.SetAmountAccountFrom(transaction_amount_account_from);
    transaction.SetAmountAccountTo(transaction_amount_account_to);
    account_database_->SetAccountAmount(transaction.GetAccountFrom().GetName(), transaction_amount_account_from);
    account_database_->SetAccountAmount(transaction.GetAccountTo().GetName(), transaction_amount_account_to);
  }
  if (transaction.GetType() == kEnumType::Transfer)
  {
    transaction_amount_account_from = account_database_->GetAccountAmount(transaction.GetAccountFrom().GetName()) - transaction.GetAmount();
    transaction_amount_account_to = account_database_->GetAccountAmount(transaction.GetAccountTo().GetName()) + transaction.GetAmount();
    transaction.SetAmountAccountFrom(transaction_amount_account_from);
    transaction.SetAmountAccountTo(transaction_amount_account_to);
    account_database_->SetAccountAmount(transaction.GetAccountFrom().GetName(), transaction_amount_account_from);
    account_database_->SetAccountAmount(transaction.GetAccountTo().GetName(), transaction_amount_account_to);
  }

  int transaction_status;
  int transaction_type;

  const std::string sql_request = std::string("INSERT INTO Transactions VALUES(") +
    "null, '" +
    transaction.GetTime().GetStringTime() + "', " +
    std::to_string(transaction_account_from_id) + ", " +
    std::to_string(transaction_account_to_id) + ", " +
    std::to_string(transaction_category_id) + ", " +
    std::to_string(transaction.GetAmount()) + ", " +
    std::to_string(transaction_amount_account_from) + ", " +
    std::to_string(transaction_amount_account_to) + ", " +
    std::to_string(transaction_comment_id) + ", " +
    std::to_string(transaction_currency_id) + ", " +
    std::to_string(transaction_description_id) + ", " +
    std::to_string(transaction_payee_id) + ", " +
    std::to_string(transaction_tag_id) + ", '" +
    std::to_string(0) + "', '" +
    std::to_string(0) + "');";
  database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
  if (database_manager_->database_status_ != SQLITE_OK)
  {
    PLOG_ERROR << "SQL Insert Error: " << database_manager_->database_error_;
  }
  else
  {
    PLOG_INFO << "Insert transaction to table 'Transactions' in database";
  }
}

void TransactionDatabase::InsertTransactionsToTableTransactionsInDatabase(TransactionRepository&& repository)
{
  for (auto i = repository.Begin(); i != repository.End(); ++i)
  {
    InsertTransactionToTableTransactionsInDatabase(std::move(**i));
  }
}

std::tuple<bool, int, Transaction> TransactionDatabase::FindTransactionInTableTransactionsInDatabase(const int id)
{
  return std::make_tuple(false, 0, Transaction(Account(), Category(), 0));
  /*
  sqlite3_prepare_v2(database_, "SELECT * FROM Transactions", -1, &database_stmt_, 0);
  while (sqlite3_step(database_stmt_) != SQLITE_DONE)
  {
    int transaction_id = (sqlite3_column_int(database_stmt_, 0));
    const unsigned char* account_name = (sqlite3_column_text(database_stmt_, 1));
    double account_amount = (sqlite3_column_double(database_stmt_, 2));
    int account_currency = (sqlite3_column_int(database_stmt_, 3));
    if (reinterpret_cast<const char*>(account_name) == name)
    {
      std::string sql_request = std::string("SELECT * FROM Currencies WHERE id = ") + std::to_string(account_currency) + ";";
      sqlite3_prepare_v2(database_, sql_request.c_str(), -1, &database_stmt_, 0);
      const unsigned char* currency_name = nullptr;
      const unsigned char* currency_code = nullptr;
      int currency_activity;
      while (sqlite3_step(database_stmt_) != SQLITE_DONE)
      {
        currency_name = (sqlite3_column_text(database_stmt_, 1));
        currency_code = (sqlite3_column_text(database_stmt_, 2));
        currency_activity = (sqlite3_column_int(database_stmt_, 3));
        break;
      }
      Currency currency((reinterpret_cast<const char*>(currency_name)), (reinterpret_cast<const char*>(currency_code)), currency_activity);
      Account account((reinterpret_cast<const char*>(account_name)), account_amount, currency);
      PLOG_INFO << "Account with name " << name << " is found in table 'Accounts' in database";
      return std::make_tuple(true, account_id, account);
    }
  }
  PLOG_INFO << "Account with name " << name << " isn't found in table 'Accounts' in database";
  return std::make_tuple(false, 0, Account());
  */
}

void TransactionDatabase::RemoveTransactionFromTableTransactionsInDatabase(const int id)
{
  bool transaction_is_in_table = false;
  int transaction_id = 0;
  std::tie(transaction_is_in_table, transaction_id, std::ignore) = FindTransactionInTableTransactionsInDatabase(id);
  if (transaction_is_in_table)
  {
    const std::string sql_request = std::string("DELETE FROM Transactions WHERE id = ") +
      std::to_string(transaction_id) + ";";
    database_manager_->database_status_ = sqlite3_exec(database_manager_->database_, sql_request.c_str(), NULL, NULL, &database_manager_->database_error_);
    if (database_manager_->database_status_ != SQLITE_OK)
    {
      PLOG_ERROR << "SQL Remove row Error: " << database_manager_->database_error_;
    }
    else
    {
      PLOG_INFO << "Remove transaction with id = " << transaction_id << " from table 'Transactions' in database";
    }
  }
}
