#include "home_bookkeeping/1_DataAccess/TagRepository.h"

//  Constructor
//  Default
TagRepository::TagRepository()
{}

//  Class member function
//  Add tag (default) to repository
void TagRepository::Add()
{
  repository_.insert(std::make_shared<Tag>());
}

//  Class member function
//  Add tag to repository
void TagRepository::Add(Tag tag)
{
  repository_.insert(std::make_shared<Tag>(tag));
}

//  Class member function
//  Add tag (shared pointer) to repository
void TagRepository::Add(std::shared_ptr<Tag> tag)
{
  repository_.insert(tag);
}

//  Class member function
//  Remove tag (shared pointer) from repository
void TagRepository::Remove(std::shared_ptr<Tag> tag)
{
  repository_.erase(tag);
}

//  Class member function
//  Calculate size of repository
size_t TagRepository::Size() const
{
  return repository_.size();
}

//  Class member function
//  Clear repository
void TagRepository::Clear()
{
  repository_.clear();
}

//  Class member function
//  Find tag (shared pointer) in repository
TagRepositoryIterator TagRepository::Find(std::shared_ptr<Tag> tag) const
{
  return repository_.find(tag);
}

//  Class member function
//  Find begin iterator of repository
TagRepositoryIterator TagRepository::Begin() const
{
  return repository_.begin();
}

//  Class member function
//  Find end iterator of repository
TagRepositoryIterator TagRepository::End() const
{
  return repository_.end();
}
