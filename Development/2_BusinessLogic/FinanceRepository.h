#ifndef HOMEBOOKKEEPING_2BUSINESSLOGIC_FINANCENREPOSITORY_H_
#define HOMEBOOKKEEPING_2BUSINESSLOGIC_FINANCENREPOSITORY_H_

//  Class FinanceRepository
//
//  Constructors:
//    Default
//
//  Class member functions:
//    basic:
//      iterators:
//        begin:
//          Find begin iterator of transaction repository
//          Find begin iterator of account repository
//          Find begin iterator of category repository
//          Find begin iterator of currency repository
//          Find begin iterator of description repository
//          Find begin iterator of payee repository
//          Find begin iterator of comment repository
//          Find begin iterator of tag repository
//        end:
//          Find end iterator of transaction repository
//          Find end iterator of account repository
//          Find end iterator of category repository
//          Find end iterator of currency repository
//          Find end iterator of description repository
//          Find end iterator of payee repository
//          Find end iterator of comment repository
//          Find end iterator of tag repository
//        add element:
//          Add transaction to transaction repository
//          Add account (default)  to account repository
//          Add account to account repository
//          Add category (default) to category repository
//          Add category to category repository
//          Add currency to currency repository
//          Add description to description repository
//          Add payee to payee repository
//          Add comment to comment repository
//          Add tag to tag repository
//        remove element:
//          Remove transaction (shared pointer) from transaction repository
//          Remove account (shared pointer) from account repository
//          Remove category (shared pointer) from category repository
//          Remove currency (shared pointer) from currency repository
//          Remove description (shared pointer) from description repository
//          Remove payee (shared pointer) from payee repository
//          Remove comment (shared pointer) from comment repository
//          Remove tag (shared pointer) from tag repository
//        number of elements in repository:
//          Number of transactions in transaction repository
//          Number of accounts in account repository
//          Number of categories in category repository
//          Number of currencies in currency repository
//          Number of descriptions in description repository
//          Number of payees in payee repository
//          Number of comments in comment repository
//          Number of tags in tag repository
//        clear repository:
//          Clear transaction repository
//          Clear account repository
//          Clear category repository
//          Clear currency repository
//          Clear description repository
//          Clear payee repository
//          Clear comment repository
//          Clear tag repository
//        print repository:
//          Print transaction repository
//          Print account repository
//          Print category repository
//          Print currency repository
//          Print description repository
//          Print payee repository
//          Print comment repository
//          Print tag repository
//        find:
//          Find account in account repository
//          Find transaction (shared pointer) in transaction repository
//          Find account (shared pointer) in account repository
//          Find category (shared pointer) in category repository
//          Find currency (shared pointer) in currency repository
//          Find description (shared pointer) in description repository
//          Find payee (shared pointer) in payee repository
//          Find comment (shared pointer) in comment repository
//          Find tag (shared pointer) in tag repository
//        update repository with adding new transaction:
//          Update last amount of account in account repository with adding new transaction
//          Update account repository with adding new transaction
//          Update category repository with adding new transaction
//          Update currency repository with adding new transaction
//          Update description repository with adding new transaction
//          Update payee repository with adding new transaction
//          Update comment repository with adding new transaction
//          Update tag repository with adding new transaction
//    sum:
//      expenses:
//        Calculate sum of today expenses
//        Calculate sum of this month expenses
//        Calculate sum of all time expenses
//      incomes:
//        Calculate sum of today incomes
//        Calculate sum of this month incomes
//        Calculate sum of all time incomes
//    default repositories:
//      Set default account repository
//      Set default category repository
//      Set default currency repository
//
//  Variables:
//    transaction repository
//    category repository
//    comment repository
//    payee repository
//    account repository
//    currency repository
//    description repository
//    tag repository

#include <iostream>

#include "home_bookkeeping/1_DataAccess/AccountRepository.h"
#include "home_bookkeeping/1_DataAccess/CategoryRepository.h"
#include "home_bookkeeping/1_DataAccess/CommentRepository.h"
#include "home_bookkeeping/1_DataAccess/CurrencyRepository.h"
#include "home_bookkeeping/1_DataAccess/DescriptionRepository.h"
#include "home_bookkeeping/1_DataAccess/PayeeRepository.h"
#include "home_bookkeeping/1_DataAccess/TagRepository.h"
#include "home_bookkeeping/1_DataAccess/TransactionRepository.h"

class FinanceRepository
{
private:
  //  basic->iterators->begin
  TransactionRepositoryIterator BeginTransactionRepository() const;
  AccountRepositoryIterator BeginAccountRepository() const;
  CategoryRepositoryIterator BeginCategoryRepository() const;
  CurrencyRepositoryIterator BeginCurrencyRepository() const;
  DescriptionRepositoryIterator BeginDescriptionRepository() const;
  PayeeRepositoryIterator BeginPayeeRepository() const;
  CommentRepositoryIterator BeginCommentRepository() const;
  TagRepositoryIterator BeginTagRepository() const;
  //  basic->iterators->end
  TransactionRepositoryIterator EndTransactionRepository() const;
  AccountRepositoryIterator EndAccountRepository() const;
  CategoryRepositoryIterator EndCategoryRepository() const;
  CurrencyRepositoryIterator EndCurrencyRepository() const;
  DescriptionRepositoryIterator EndDescriptionRepository() const;
  PayeeRepositoryIterator EndPayeeRepository() const;
  CommentRepositoryIterator EndCommentRepository() const;
  TagRepositoryIterator EndTagRepository() const;
public:
  //  constructor->default
	FinanceRepository();
  //  basic->add element
  void AddTransaction(Transaction& transaction);
  void AddAccount();
  void AddAccount(const Account& account);
  void AddCategory();
  void AddCategory(const Category& category);
  void AddCurrency();
  void AddCurrency(const Currency& currency);
  void AddDescription();
  void AddDescription(const Description& description);
  void AddPayee();
  void AddPayee(const Payee& payee);
  void AddComment();
  void AddComment(const Comment& comment);
  void AddTag();
  void AddTag(const Tag& tag);
  //  basic->remove element
  void RemoveTransaction(std::shared_ptr<Transaction> transaction);
  void RemoveAccount(std::shared_ptr<Account> account);
  void RemoveCategory(std::shared_ptr<Category> category);
  void RemoveCurrency(std::shared_ptr<Currency> currency);
  void RemoveDescription(std::shared_ptr<Description> description);
  void RemovePayee(std::shared_ptr<Payee> payee);
  void RemoveComment(std::shared_ptr<Comment> comment);
  void RemoveTag(std::shared_ptr<Tag> tag);
  //  basic->get name of model from repository
  std::string GetAccountName(AccountRepositoryIterator account) const;
  //  basic->number of elements in repository
  size_t GetTransactionsNumber() const;
  size_t GetAccountsNumber() const;
  size_t GetCategoriesNumber() const;
  size_t GetCurrenciesNumber() const;
  size_t GetDescriptionsNumber() const;
  size_t GetPayeesNumber() const;
  size_t GetCommentsNumber() const;
  size_t GetTagsNumber() const;
  //  basic->clear repository
  void ClearTransactions();
  void ClearAccounts();
  void ClearCategories();
  void ClearCurrencies();
  void ClearDescriptions();
  void ClearPayees();
  void ClearComments();
  void ClearTags();
  //  basic->print repository
  void PrintTransactions(const std::string& delimeter = "\n", std::ostream& output_stream = std::cout) const;
  void PrintAccounts(const std::string& delimeter = "\n", std::ostream& output_stream = std::cout) const;
  void PrintCategories(const std::string& delimeter = "\n", std::ostream& output_stream = std::cout) const;
  void PrintCurrencies(const std::string& delimeter = "\n", std::ostream& output_stream = std::cout) const;
  void PrintDescriptions(const std::string& delimeter = "\n", std::ostream& output_stream = std::cout) const;
  void PrintPayees(const std::string& delimeter = "\n", std::ostream& output_stream = std::cout) const;
  void PrintComments(const std::string& delimeter = "\n", std::ostream& output_stream = std::cout) const;
  void PrintTags(const std::string& delimeter = "\n", std::ostream& output_stream = std::cout) const;
  //  basic->find
  AccountRepositoryIterator FindAccount(std::string account) const;
  TransactionRepositoryIterator FindTransaction(std::shared_ptr<Transaction> transaction) const;
  AccountRepositoryIterator FindAccount(std::shared_ptr<Account> account) const;
  CategoryRepositoryIterator FindCategory(std::shared_ptr<Category> category) const;
  CurrencyRepositoryIterator FindCurrency(std::shared_ptr<Currency> currency) const;
  DescriptionRepositoryIterator FindDescription(std::shared_ptr<Description> description) const;
  PayeeRepositoryIterator FindPayee(std::shared_ptr<Payee> payee) const;
  CommentRepositoryIterator FindComment(std::shared_ptr<Comment> comment) const;
  TagRepositoryIterator FindTag(std::shared_ptr<Tag> tag) const;
  //  basic->update repository with adding new transaction
  void UpdateAccountAmount(Transaction& transaction);
  void UpdateAccountRepository(Transaction& transaction);
  void UpdateCategoryRepository(Transaction& transaction);
  void UpdateCurrencyRepository(Transaction& transaction);
  void UpdateDescriptionRepository(Transaction& transaction);
  void UpdatePayeeRepository(Transaction& transaction);
  void UpdateCommentRepository(Transaction& transaction);
  void UpdateTagRepository(Transaction& transaction);
  //  sum->expenses
  double SumExpensesToday() const;
  double SumExpensesThisMonth() const;
  double SumExpensesAllTime() const;
  //  sum->incomes
  double SumIncomesToday() const;
  double SumIncomesThisMonth() const;
  double SumIncomesAllTime() const;
  //  default repositories
  void SetDefaultCategories();
  void SetDefaultAccounts();
  void SetDefaultCurrencies();
private:
  TransactionRepository transaction_repository_;
  CategoryRepository category_repository_;
  CommentRepository comment_repository_;
  PayeeRepository payee_repository_;
  AccountRepository account_repository_;
  CurrencyRepository currency_repository_;
  DescriptionRepository description_repository_;
  TagRepository tag_repository_;
};

#endif  //  HOMEBOOKKEEPING_2BUSINESSLOGIC_FINANCENREPOSITORY_H_
