#include "home_bookkeeping/1_DataAccess/DescriptionRepository.h"

//  Constructor
//  Default
DescriptionRepository::DescriptionRepository()
{}

//  Class member function
//  Add description to repository
void DescriptionRepository::Add(Description description)
{
  repository_.insert(std::make_shared<Description>(description));
}

//  Class member function
//  Add description (shared pointer) to repository
void DescriptionRepository::Add(std::shared_ptr<Description> description)
{
  repository_.insert(description);
}

//  Class member function
//  Remove description (shared pointer) from repository
void DescriptionRepository::Remove(std::shared_ptr<Description> description)
{
  repository_.erase(description);
}

//  Class member function
//  Calculate size of repository
size_t DescriptionRepository::Size() const
{
  return repository_.size();
}

//  Class member function
//  Clear repository
void DescriptionRepository::Clear()
{
  repository_.clear();
}

//  Class member function
//  Find description (shared pointer) in repository
DescriptionRepositoryIterator DescriptionRepository::Find(std::shared_ptr<Description> description) const
{
  return repository_.find(description);
}

//  Class member function
//  Find begin iterator of repository
DescriptionRepositoryIterator DescriptionRepository::Begin() const
{
  return repository_.begin();

}

//  Class member function
//  Find end iterator of repository
DescriptionRepositoryIterator DescriptionRepository::End() const
{
  return repository_.end();
}
