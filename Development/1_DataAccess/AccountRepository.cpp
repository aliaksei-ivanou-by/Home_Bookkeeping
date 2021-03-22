#include "home_bookkeeping/1_DataAccess/AccountRepository.h"

//  Constructor
//  Default
AccountRepository::AccountRepository()
{}

//  Class member function
//  Add account (default) to repository
void AccountRepository::Add()
{
  repository_.insert(std::make_shared<Account>());
}

//  Class member function
//  Add account to repository
void AccountRepository::Add(Account account)
{
  repository_.insert(std::make_shared<Account>(account));
}

//  Class member function
//  Add account (shared pointer) to repository
void AccountRepository::Add(std::shared_ptr<Account> account)
{
  repository_.insert(account);
}

//  Class member function
//  Remove account (shared pointer) from repository
void AccountRepository::Remove(std::shared_ptr<Account> account)
{
  repository_.erase(account);
}

//  Class member function
//  Get name of account from repository
std::string AccountRepository::GetName(AccountRepositoryIterator account) const
{
  return (**account).GetName();
}

//  Class member function
//  Calculate size of repository
size_t AccountRepository::Size() const
{
  return repository_.size();
}

//  Class member function
//  Clear repository
void AccountRepository::Clear()
{
  repository_.clear();
}

//  Class member function
//  Find account (shared pointer) in repository
AccountRepositoryIterator AccountRepository::Find(std::shared_ptr<Account> account) const
{
  return repository_.find(account);
}

//  Class member function
//  Find account in repository
AccountRepositoryIterator AccountRepository::Find(std::string account) const
{
  for (auto i = repository_.begin(); i != repository_.end(); ++i)
  {
    if ((**i).GetName() == account)
    {
      return i;
    }
  }
  return repository_.end();
}

//  Class member function
//  Find begin iterator of repository
AccountRepositoryIterator AccountRepository::Begin() const
{
  return repository_.begin();
}

//  Class member function
//  Find end iterator of repository
AccountRepositoryIterator AccountRepository::End() const
{
  return repository_.end();
}
