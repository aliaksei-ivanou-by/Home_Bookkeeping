#include "include/1_DataAccess/CurrencyRepository.h"

CurrencyRepository::CurrencyRepository()
{}

void CurrencyRepository::Add()
{
  repository_.insert(std::make_shared<Currency>());
  PLOG_INFO << "Add currency to currency repository";
}

void CurrencyRepository::Add(Currency currency)
{
  repository_.insert(std::make_shared<Currency>(currency));
  PLOG_INFO << "Add currency to currency repository";
}

void CurrencyRepository::Add(std::shared_ptr<Currency> currency)
{
  repository_.insert(currency);
  PLOG_INFO << "Add currency to currency repository";
}

void CurrencyRepository::Remove(std::shared_ptr<Currency> currency)
{
  repository_.erase(currency);
  PLOG_INFO << "Remove currency from currency repository";
}

std::string CurrencyRepository::GetName(CurrencyRepositoryIterator currency) const
{
  return (**currency).GetName();
}

void CurrencyRepository::SetName(CurrencyRepositoryIterator currency, const std::string& name)
{
  (**currency).SetName(name);
  PLOG_INFO << "Set new name of currency in currency repository";
}

void CurrencyRepository::SetCode(CurrencyRepositoryIterator currency, const std::string& code)
{
  (**currency).SetCode(code);
  PLOG_INFO << "Set new code of currency in currency repository";
}

void CurrencyRepository::SetActivity(CurrencyRepositoryIterator currency, const bool activity)
{
  (**currency).SetActivity(activity);
  PLOG_INFO << "Set new activity of currency in currency repository";
}

void CurrencyRepository::Switch(CurrencyRepositoryIterator currency)
{
  (**currency).Switch();
  PLOG_INFO << "Switch activity of currency in currency repository";
}

void CurrencyRepository::SwitchOn(CurrencyRepositoryIterator currency)
{
  (**currency).SwitchOn();
  PLOG_INFO << "Switch on activity of currency in currency repository";
}

void CurrencyRepository::SwitchOff(CurrencyRepositoryIterator currency)
{
  (**currency).SwitchOff();
  PLOG_INFO << "Switch off activity of currency in currency repository";
}

std::string CurrencyRepository::GetCode(CurrencyRepositoryIterator currency) const
{
  return (**currency).GetCode();
}

bool CurrencyRepository::GetActivity(CurrencyRepositoryIterator currency) const
{
  return (**currency).GetActivity();
}

size_t CurrencyRepository::Size() const
{
  return repository_.size();
}

void CurrencyRepository::Clear()
{
  repository_.clear();
  PLOG_INFO << "Clear currency repository";
}

CurrencyRepositoryIterator CurrencyRepository::Find(std::shared_ptr<Currency> currency) const
{
  return repository_.find(currency);
}

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

CurrencyRepositoryIterator CurrencyRepository::Begin() const
{
  return repository_.begin();
}

CurrencyRepositoryIterator CurrencyRepository::End() const
{
  return repository_.end();
}
