#include "include/1_DataAccess/PayeeRepository.h"

PayeeRepository::PayeeRepository()
{}

void PayeeRepository::AddPayee(std::shared_ptr<Payee> payee)
{
  for (auto& i : repository_)
  {
    if (i.first->GetName() == payee->GetName())
    {
      ++i.second;
      PLOG_INFO << "Add payee to payee repository (counter + 1)";
      return;
    }
  }
  repository_[payee] = 1;
  PLOG_INFO << "Add payee to payee repository";
}

void PayeeRepository::Add()
{
  std::shared_ptr<Payee> payee_temp = std::make_shared<Payee>(Payee());
  AddPayee(payee_temp);
}

void PayeeRepository::Add(Payee payee)
{
  std::shared_ptr<Payee> payee_temp = std::make_shared<Payee>(payee);
  AddPayee(payee_temp);
}

void PayeeRepository::Add(std::shared_ptr<Payee> payee)
{
  AddPayee(payee);
}

void PayeeRepository::Remove(std::shared_ptr<Payee> payee)
{
  repository_.erase(payee);
  PLOG_INFO << "Remove payee from payee repository";
}

std::string PayeeRepository::GetName(PayeeRepositoryIterator payee) const
{
  return payee->first->GetName();
}

void PayeeRepository::SetName(PayeeRepositoryIterator payee, const std::string& name)
{
  payee->first->SetName(name);
  PLOG_INFO << "Set new name of payee in payee repository";
}

size_t PayeeRepository::Size() const
{
  return repository_.size();
}

void PayeeRepository::Clear()
{
  repository_.clear();
  PLOG_INFO << "Clear payee repository";
}

PayeeRepositoryConstIterator PayeeRepository::Find(std::shared_ptr<Payee> payee) const
{
  return repository_.find(payee);
}

PayeeRepositoryConstIterator PayeeRepository::Find(std::string name) const
{
  for (auto i = repository_.begin(); i != repository_.end(); ++i)
  {
    if (i->first->GetName() == name)
    {
      return i;
    }
  }
  return repository_.end();
}

PayeeRepositoryConstIterator PayeeRepository::Begin() const
{
  return repository_.begin();
}

PayeeRepositoryConstIterator PayeeRepository::End() const
{
  return repository_.end();
}
