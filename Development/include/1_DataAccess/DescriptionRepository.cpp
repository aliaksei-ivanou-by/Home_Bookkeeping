#include "include/1_DataAccess/DescriptionRepository.h"

DescriptionRepository::DescriptionRepository()
{}

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

void DescriptionRepository::Add()
{
  std::shared_ptr<Description> description_temp = std::make_shared<Description>(Description());
  AddDescription(description_temp);
}

void DescriptionRepository::Add(Description description)
{
  std::shared_ptr<Description> description_temp = std::make_shared<Description>(description);
  AddDescription(description_temp);
}

void DescriptionRepository::Add(std::shared_ptr<Description> description)
{
  AddDescription(description);
}

void DescriptionRepository::Remove(std::shared_ptr<Description> description)
{
  repository_.erase(description);
  PLOG_INFO << "Remove description from description repository";
}

std::string DescriptionRepository::GetName(DescriptionRepositoryIterator description) const
{
  return description->first->GetName();
}

void DescriptionRepository::SetName(DescriptionRepositoryIterator description, const std::string& name)
{
  description->first->SetName(name);
  PLOG_INFO << "Set new name of description in description repository";
}

size_t DescriptionRepository::Size() const
{
  return repository_.size();
}

void DescriptionRepository::Clear()
{
  repository_.clear();
  PLOG_INFO << "Clear description repository";
}

DescriptionRepositoryConstIterator DescriptionRepository::Find(std::shared_ptr<Description> description) const
{
  return repository_.find(description);
}

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

DescriptionRepositoryConstIterator DescriptionRepository::Begin() const
{
  return repository_.begin();

}

DescriptionRepositoryConstIterator DescriptionRepository::End() const
{
  return repository_.end();
}
