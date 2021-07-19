#ifndef HOMEBOOKKEEPING_1DATAACCESS_TAGREPOSITORY_H_
#define HOMEBOOKKEEPING_1DATAACCESS_TAGREPOSITORY_H_

#include <iostream>
#include <map>

#include "include/0_Models/Tag.h"

using TagRepositoryIterator = std::map<std::shared_ptr<Tag>, int>::iterator;
using TagRepositoryConstIterator = std::map<std::shared_ptr<Tag>, int>::const_iterator;

class TagRepository
{
public:
  TagRepository();
  void Add();
  void Add(Tag tag);
  void Add(std::shared_ptr<Tag> tag);
  void Remove(std::shared_ptr<Tag> tag);
  std::string GetName(TagRepositoryIterator tag) const;
  void SetName(TagRepositoryIterator tag, const std::string& name);
  size_t Size() const;
  void Clear();
  TagRepositoryConstIterator Find(std::shared_ptr<Tag> tag) const;
  TagRepositoryConstIterator Find(std::string name) const;
  TagRepositoryConstIterator Begin() const;
  TagRepositoryConstIterator End() const;
private:
  void AddTag(std::shared_ptr<Tag> tag);
  std::map<std::shared_ptr<Tag>, int> repository_;
};

#endif
