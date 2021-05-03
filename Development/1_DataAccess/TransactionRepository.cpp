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
//  Make command to create table for repository in database
std::string TransactionRepository::MakeCommandToCreateRepositoryInDatabase() const
{
  return "CREATE TABLE IF NOT EXISTS Transactions(id SERIAL PRIMARY KEY, time VARCHAR(255) NOT NULL, account_from VARCHAR(255) NOT NULL, account_to VARCHAR(255) NOT NULL, category VARCHAR(255) NOT NULL, amount DOUBLE NOT NULL, amount_account_from DOUBLE NOT NULL, amount_acount_to DOUBLE NOT NULL, comment VARCHAR(255) NOT NULL, currency VARCHAR(255) NOT NULL, description VARCHAR(255) NOT NULL, payee VARCHAR(255), tag VARCHAR(255) NOT NULL, status VARCHAR(255) NOT NULL, type VARCHAR(255) NOT NULL);";
}

//  Class member function
//  Make command to insert repository to database to table
std::string TransactionRepository::MakeCommandToInsertRepositoryToDatabase(size_t id, TransactionRepositoryIterator iterator) const
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
    std::to_string((**iterator).GetAmount().getAsDouble())
    + ", " +
    std::to_string((**iterator).GetAmountAccountFrom().getAsDouble())
    + ", " +
    std::to_string((**iterator).GetAmountAccountTo().getAsDouble())
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
