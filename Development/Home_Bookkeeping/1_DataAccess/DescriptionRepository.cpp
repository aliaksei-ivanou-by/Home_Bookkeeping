#include "Home_Bookkeeping/1_DataAccess/DescriptionRepository.h"

//  Constructor
//  Default
DescriptionRepository::DescriptionRepository()
{}

//  Class member function (private)
//  Add comment (shared pointer) to repository
void DescriptionRepository::AddDescription(std::shared_ptr<Description> description)
{
  for (auto& i : repository_)
  {
    if (i.first->GetName() == description->GetName())
    {
      ++i.second;
      PLOG_INFO << "Add description to description repository (counter + 1)";
      return;
    }
  }
  repository_[description] = 1;
  PLOG_INFO << "Add description to description repository";
}

//  Class member function
//  Add description (default) to repository
void DescriptionRepository::Add()
{
  std::shared_ptr<Description> description_temp = std::make_shared<Description>(Description());
  AddDescription(description_temp);
}

//  Class member function
//  Add description to repository
void DescriptionRepository::Add(Description description)
{
  std::shared_ptr<Description> description_temp = std::make_shared<Description>(description);
  AddDescription(description_temp);
}

//  Class member function
//  Add description (shared pointer) to repository
void DescriptionRepository::Add(std::shared_ptr<Description> description)
{
  AddDescription(description);
}

//  Class member function
//  Remove description (shared pointer) from repository
void DescriptionRepository::Remove(std::shared_ptr<Description> description)
{
  repository_.erase(description);
  PLOG_INFO << "Remove description from description repository";
}

//  Class member function
//  Get name of description from repository
std::string DescriptionRepository::GetName(DescriptionRepositoryIterator description) const
{
  return description->first->GetName();
}

//  Class member function
//  Set name of description from repository
void DescriptionRepository::SetName(DescriptionRepositoryIterator description, const std::string& name)
{
  description->first->SetName(name);
  PLOG_INFO << "Set new name of description in description repository";
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
  PLOG_INFO << "Clear description repository";
}

//  Class member function
//  Find description (shared pointer) in repository
DescriptionRepositoryConstIterator DescriptionRepository::Find(std::shared_ptr<Description> description) const
{
  return repository_.find(description);
}

//  Class member function
//  Find description with definite name in repository
DescriptionRepositoryConstIterator DescriptionRepository::Find(const std::string& name) const
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
DescriptionRepositoryConstIterator DescriptionRepository::Begin() const
{
  return repository_.begin();

}

//  Class member function
//  Find end iterator of repository
DescriptionRepositoryConstIterator DescriptionRepository::End() const
{
  return repository_.end();
}
