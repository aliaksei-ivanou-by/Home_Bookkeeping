#include "home_bookkeeping/1_DataAccess/PayeeRepository.h"

//  Constructor
//  Default
PayeeRepository::PayeeRepository()
{}

//  Class member function
//  Add payee (default) to repository
void PayeeRepository::Add()
{
  repository_.insert(std::make_shared<Payee>());
}

//  Class member function
//  Add payee to repository
void PayeeRepository::Add(Payee payee)
{
  repository_.insert(std::make_shared<Payee>(payee));
}

//  Class member function
//  Add payee (shared pointer) to repository
void PayeeRepository::Add(std::shared_ptr<Payee> payee)
{
  repository_.insert(payee);
}

//  Class member function
//  Remove payee (shared pointer) from repository
void PayeeRepository::Remove(std::shared_ptr<Payee> payee)
{
  repository_.erase(payee);
}

//  Class member function
//  Get name of payee from repository
std::string PayeeRepository::GetName(PayeeRepositoryIterator payee) const
{
  return (**payee).GetName();
}

//  Class member function
//  Set name of payee from repository
void PayeeRepository::SetName(PayeeRepositoryIterator payee, const std::string& name)
{
  (**payee).SetName(name);
}

//  Class member function
//  Calculate size of repository
size_t PayeeRepository::Size() const
{
  return repository_.size();
}

//  Class member function
//  Clear repository
void PayeeRepository::Clear()
{
  repository_.clear();
}

//  Class member function
//  Find payee (shared pointer) in repository
PayeeRepositoryIterator PayeeRepository::Find(std::shared_ptr<Payee> payee) const
{
  return repository_.find(payee);
}

//  Class member function
//  Find payee with definite name in repository
PayeeRepositoryIterator PayeeRepository::Find(std::string name) const
{
  for (auto i = repository_.begin(); i != repository_.end(); ++i)
  {
    if ((**i).GetName() == name)
    {
      return i;
    }
  }
  return repository_.end();
}

//  Class member function
//  Find begin iterator of repository
PayeeRepositoryIterator PayeeRepository::Begin() const
{
  return repository_.begin();
}

//  Class member function
//  Find end iterator of repository
PayeeRepositoryIterator PayeeRepository::End() const
{
  return repository_.end();
}

//  Class member function
//  Make command to create table for repository in database
std::string PayeeRepository::MakeCommandToCreateRepositoryInDatabase() const
{
  return "CREATE TABLE IF NOT EXISTS Payees(id INTEGER NOT NULL PRIMARY KEY, name VARCHAR(255) NOT NULL);";
}

//  Class member function
//  Make command to insert repository to database to table
std::string PayeeRepository::MakeCommandToInsertRepositoryToDatabase(size_t id, PayeeRepositoryIterator iterator) const
{
  return "INSERT INTO Payees VALUES(" +
    std::to_string(id)
    + ", '" +
    (**iterator).GetName()
    + "')";
}
