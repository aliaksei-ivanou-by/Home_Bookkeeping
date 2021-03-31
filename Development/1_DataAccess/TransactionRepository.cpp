#include "home_bookkeeping/1_DataAccess/TransactionRepository.h"

//  Constructor
//  Default
TransactionRepository::TransactionRepository()
{}

//  Class member function
//  Add transaction to repository
void TransactionRepository::Add(Transaction transaction)
{
  repository_.insert(std::make_shared<Transaction>(transaction));
}

//  Class member function
//  Add transaction (shared pointer) to repository
void TransactionRepository::Add(std::shared_ptr<Transaction> transaction)
{
  repository_.insert(transaction);
}

//  Class member function
//  Remove transaction (shared pointer) from repository
void TransactionRepository::Remove(std::shared_ptr<Transaction> transaction)
{
  repository_.erase(transaction);
}

//  Class member function
//  Calculate size of repository
size_t TransactionRepository::Size() const
{
  return repository_.size();
}

//  Class member function
//  Clear repository
void TransactionRepository::Clear()
{
  repository_.clear();
}

//  Class member function
//  Find transaction (shared pointer) in repository
TransactionRepositoryIterator TransactionRepository::Find(std::shared_ptr<Transaction> transaction) const
{
  return repository_.find(transaction);
}

//  Class member function
//  Find begin iterator of repository
TransactionRepositoryIterator TransactionRepository::Begin() const
{
  return repository_.begin();
}

//  Class member function
//  Find end iterator of repository
TransactionRepositoryIterator TransactionRepository::End() const
{
  return repository_.end();
}

//  Class member function
//  Make command to create table in database for repository
std::string TransactionRepository::MakeCommandToCreateTableInDatabase() const
{
  return "CREATE TABLE IF NOT EXISTS Transactions(id INT, time VARCHAR(255), account_from VARCHAR(255), account_to VARCHAR(255), category VARCHAR(255), amount DOUBLE, amount_account_from DOUBLE, amount_acount_to DOUBLE, comment VARCHAR(255), currency VARCHAR(255), description VARCHAR(255), payee VARCHAR(255), tag VARCHAR(255), status VARCHAR(255), type VARCHAR(255));";
}

//  Class member function
//  Make command to insert repository to database
std::string TransactionRepository::MakeCommandToInsertToTableToDatabase(size_t id, TransactionRepositoryIterator iterator) const
{
  return "INSERT INTO Transactions VALUES(" +
    std::to_string(id)
    + ", '" +
    (**iterator).GetStringTime()
    + "', '" +
    (**iterator).GetAccountFrom().GetName()
    + "', '" +
    (**iterator).GetAccountTo().GetName()
    + "', '" +
    (**iterator).GetCategory().GetName()
    + "', " +
    std::to_string((**iterator).GetAmount())
    + ", " +
    std::to_string((**iterator).GetAmountAccountFrom())
    + ", " +
    std::to_string((**iterator).GetAmountAccountTo())
    + ", '" +
    (**iterator).GetComment().GetName()
    + "', '" +
    (**iterator).GetCurrency().GetName()
    + "', '" +
    (**iterator).GetDescription().GetName()
    + "', '" +
    (**iterator).GetPayee().GetName()
    + "', '" +
    (**iterator).GetTag().GetName()
    + "', '" +
    (**iterator).GetStatus().GetName()
    + "', '" +
    (**iterator).GetType().GetName()
    + "')";
}
