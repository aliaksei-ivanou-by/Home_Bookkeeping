#include "include/1_DataAccess/AccountRepository.h"

AccountRepository::AccountRepository()
{}

void AccountRepository::Add()
{
  repository_.insert(std::make_shared<Account>());
  PLOG_INFO << "Add account to account repository";
}

void AccountRepository::Add(Account account)
{
  repository_.insert(std::make_shared<Account>(account));
  PLOG_INFO << "Add account to account repository";
}

void AccountRepository::Add(std::shared_ptr<Account> account)
{
  repository_.insert(account);
  PLOG_INFO << "Add account to account repository";
}

void AccountRepository::Remove(std::shared_ptr<Account> account)
{
  repository_.erase(account);
  PLOG_INFO << "Remove account from account repository";
}

std::string AccountRepository::GetName(AccountRepositoryIterator account) const
{
  return (**account).GetName();
}

NUM AccountRepository::GetAmount(AccountRepositoryIterator account) const
{
  return (**account).GetAmount();
}

void AccountRepository::SetName(AccountRepositoryIterator account, const std::string& name)
{
  (**account).SetName(name);
  PLOG_INFO << "Set new name of account in account repository";
}

void AccountRepository::SetAmount(AccountRepositoryIterator account, const double amount)
{
  (**account).SetAmount(amount);
  PLOG_INFO << "Set new amount of account in account repository";
}

size_t AccountRepository::Size() const
{
  return repository_.size();
}

void AccountRepository::Clear()
{
  repository_.clear();
  PLOG_INFO << "Clear account repository";
}

AccountRepositoryIterator AccountRepository::Find(std::shared_ptr<Account> account) const
{
  return repository_.find(account);
}

AccountRepositoryIterator AccountRepository::Find(std::string name) const
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

AccountRepositoryIterator AccountRepository::Find(double amount) const
{
  for (auto i = repository_.begin(); i != repository_.end(); ++i)
  {
    if ((**i).GetAmount() == NUM(amount))
    {
      return i;
    }
  }
  return repository_.end();
}

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
