#include "Home_Bookkeeping/1_DataAccess/PayeeRepository.h"

//  Constructor
//  Default
PayeeRepository::PayeeRepository()
{}

//  Class member function (private)
//  Add comment (shared pointer) to repository
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

//  Class member function
//  Add payee (default) to repository
void PayeeRepository::Add()
{
  std::shared_ptr<Payee> payee_temp = std::make_shared<Payee>(Payee());
  AddPayee(payee_temp);
}

//  Class member function
//  Add payee to repository
void PayeeRepository::Add(Payee payee)
{
  std::shared_ptr<Payee> payee_temp = std::make_shared<Payee>(payee);
  AddPayee(payee_temp);
}

//  Class member function
//  Add payee (shared pointer) to repository
void PayeeRepository::Add(std::shared_ptr<Payee> payee)
{
  AddPayee(payee);
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
  return payee->first->GetName();
}

//  Class member function
//  Set name of payee from repository
void PayeeRepository::SetName(PayeeRepositoryIterator payee, const std::string& name)
{
  payee->first->SetName(name);
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
PayeeRepositoryConstIterator PayeeRepository::Find(std::shared_ptr<Payee> payee) const
{
  return repository_.find(payee);
}

//  Class member function
//  Find payee with definite name in repository
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

//  Class member function
//  Find begin iterator of repository
PayeeRepositoryConstIterator PayeeRepository::Begin() const
{
  return repository_.begin();
}

//  Class member function
//  Find end iterator of repository
PayeeRepositoryConstIterator PayeeRepository::End() const
{
  return repository_.end();
}
