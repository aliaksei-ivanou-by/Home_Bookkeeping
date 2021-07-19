#ifndef HOMEBOOKKEEPING_1DATAACCESS_PAYEEREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_PAYEEREPOSITORY_H_

#include <iostream>
#include <map>

#include "include/0_Models/Payee.h"

using PayeeRepositoryIterator = std::map<std::shared_ptr<Payee>, int>::iterator;
using PayeeRepositoryConstIterator = std::map<std::shared_ptr<Payee>, int>::const_iterator;

class PayeeRepository
{
public:
  PayeeRepository();
  void Add();
  void Add(Payee payee);
  void Add(std::shared_ptr<Payee> payee);
  void Remove(std::shared_ptr<Payee> payee);
  std::string GetName(PayeeRepositoryIterator payee) const;
  void SetName(PayeeRepositoryIterator payee, const std::string& name);
  size_t Size() const;
  void Clear();
  PayeeRepositoryConstIterator Find(std::shared_ptr<Payee> payee) const;
  PayeeRepositoryConstIterator Find(std::string name) const;
  PayeeRepositoryConstIterator Begin() const;
  PayeeRepositoryConstIterator End() const;
private:
  void AddPayee(std::shared_ptr<Payee> payee);
  std::map<std::shared_ptr<Payee>, int> repository_;
};

#endif
