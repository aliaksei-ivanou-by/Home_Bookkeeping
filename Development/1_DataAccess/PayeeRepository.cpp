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
  PLOG_INFO << "Add payee to payee repository";
}

//  Class member function
//  Add payee to repository
void PayeeRepository::Add(Payee payee)
{
  repository_.insert(std::make_shared<Payee>(payee));
  PLOG_INFO << "Add payee to payee repository";
}

//  Class member function
//  Add payee (shared pointer) to repository
void PayeeRepository::Add(std::shared_ptr<Payee> payee)
{
  repository_.insert(payee);
  PLOG_INFO << "Add payee to payee repository";
}

//  Class member function
//  Remove payee (shared pointer) from repository
void PayeeRepository::Remove(std::shared_ptr<Payee> payee)
{
  repository_.erase(payee);
  PLOG_INFO << "Remove payee from payee repository";
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
  PLOG_INFO << "Set new name of payee in payee repository";
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
  PLOG_INFO << "Clear payee repository";
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
