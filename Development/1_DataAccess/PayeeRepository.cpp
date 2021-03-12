#include "home_bookkeeping/1_DataAccess/PayeeRepository.h"

//  Constructor
//  Default
PayeeRepository::PayeeRepository()
{}

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
