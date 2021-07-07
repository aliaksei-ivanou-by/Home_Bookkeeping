#include "Home_Bookkeeping/1_DataAccess/CurrencyRepository.h"

//  Constructor
//  Default
CurrencyRepository::CurrencyRepository()
{}

//  Class member function
//  Add currency (default) to repository
void CurrencyRepository::Add()
{
  repository_.insert(std::make_shared<Currency>());
  PLOG_INFO << "Add currency to currency repository";
}

//  Class member function
//  Add currency to repository
void CurrencyRepository::Add(Currency currency)
{
  repository_.insert(std::make_shared<Currency>(currency));
  PLOG_INFO << "Add currency to currency repository";
}

//  Class member function
//  Add currency (shared pointer) to repository
void CurrencyRepository::Add(std::shared_ptr<Currency> currency)
{
  repository_.insert(currency);
  PLOG_INFO << "Add currency to currency repository";
}

//  Class member function
//  Remove currency (shared pointer) from repository
void CurrencyRepository::Remove(std::shared_ptr<Currency> currency)
{
  repository_.erase(currency);
  PLOG_INFO << "Remove currency from currency repository";
}

//  Class member function
//  Get name of currency from repository
std::string CurrencyRepository::GetName(CurrencyRepositoryIterator currency) const
{
  return (**currency).GetName();
}

//  Class member function
//  Set name of currency from repository
void CurrencyRepository::SetName(CurrencyRepositoryIterator currency, const std::string& name)
{
  (**currency).SetName(name);
  PLOG_INFO << "Set new name of currency in currency repository";
}

//  Class member function
//  Set code of currency from repository
void CurrencyRepository::SetCode(CurrencyRepositoryIterator currency, const std::string& code)
{
  (**currency).SetCode(code);
  PLOG_INFO << "Set new code of currency in currency repository";
}

//  Class member function
//  Set activity of currency from repository
void CurrencyRepository::SetActivity(CurrencyRepositoryIterator currency, const bool activity)
{
  (**currency).SetActivity(activity);
  PLOG_INFO << "Set new activity of currency in currency repository";
}

//  Class member function
//  Switch activity of currency from repository
void CurrencyRepository::Switch(CurrencyRepositoryIterator currency)
{
  (**currency).Switch();
  PLOG_INFO << "Switch activity of currency in currency repository";
}

//  Class member function
//  Switch on activity of currency from repository
void CurrencyRepository::SwitchOn(CurrencyRepositoryIterator currency)
{
  (**currency).SwitchOn();
  PLOG_INFO << "Switch on activity of currency in currency repository";
}

//  Class member function
//  Switch off activity of currency from repository
void CurrencyRepository::SwitchOff(CurrencyRepositoryIterator currency)
{
  (**currency).SwitchOff();
  PLOG_INFO << "Switch off activity of currency in currency repository";
}

//  Class member function
//  Get code of currency from repository
std::string CurrencyRepository::GetCode(CurrencyRepositoryIterator currency) const
{
  return (**currency).GetCode();
}

//  Class member function
//  Get activity of currency from repository
bool CurrencyRepository::GetActivity(CurrencyRepositoryIterator currency) const
{
  return (**currency).GetActivity();
}

//  Class member function
//  Calculate size of repository
size_t CurrencyRepository::Size() const
{
  return repository_.size();
}

//  Class member function
//  Clear repository
void CurrencyRepository::Clear()
{
  repository_.clear();
  PLOG_INFO << "Clear currency repository";
}

//  Class member function
//  Find currency (shared pointer) in repository
CurrencyRepositoryIterator CurrencyRepository::Find(std::shared_ptr<Currency> currency) const
{
  return repository_.find(currency);
}

//  Class member function
//  Find currency with definite name in repository
CurrencyRepositoryIterator CurrencyRepository::FindName(const std::string& name) const
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
//  Find currency with definite code in repository
CurrencyRepositoryIterator CurrencyRepository::FindCode(const std::string& code) const
{
  for (auto i = repository_.begin(); i != repository_.end(); ++i)
  {
    if ((**i).GetCode() == code)
    {
      return i;
    }
  }
  return repository_.end();
}

//  Class member function
//  Find begin iterator of repository
CurrencyRepositoryIterator CurrencyRepository::Begin() const
{
  return repository_.begin();
}

//  Class member function
//  Find end iterator of repository
CurrencyRepositoryIterator CurrencyRepository::End() const
{
  return repository_.end();
}
