#ifndef HOMEBOOKKEEPING_1DATAACCESS_DESCRIPTIONREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_DESCRIPTIONREPOSITORY_H_

#include <iostream>
#include <map>

#include "include/0_Models/Description.h"

using DescriptionRepositoryIterator = std::map<std::shared_ptr<Description>, int>::iterator;
using DescriptionRepositoryConstIterator = std::map<std::shared_ptr<Description>, int>::const_iterator;

class DescriptionRepository
{
public:
  DescriptionRepository();
  void Add();
  void Add(Description description);
  void Add(std::shared_ptr<Description> description);
  void Remove(std::shared_ptr<Description> description);
  std::string GetName(DescriptionRepositoryIterator description) const;
  void SetName(DescriptionRepositoryIterator description, const std::string& name);
  size_t Size() const;
  void Clear();
  DescriptionRepositoryConstIterator Find(std::shared_ptr<Description> description) const;
  DescriptionRepositoryConstIterator Find(const std::string& description) const;
  DescriptionRepositoryConstIterator Begin() const;
  DescriptionRepositoryConstIterator End() const;
private:
  void AddDescription(std::shared_ptr<Description> description);
  std::map<std::shared_ptr<Description>, int> repository_;
};

#endif
