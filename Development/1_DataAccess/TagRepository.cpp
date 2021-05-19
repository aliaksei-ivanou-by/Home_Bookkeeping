#include "home_bookkeeping/1_DataAccess/TagRepository.h"

//  Constructor
//  Default
TagRepository::TagRepository()
{}

//  Class member function (private)
//  Add tag (shared pointer) to repository
void TagRepository::AddTag(std::shared_ptr<Tag> tag)
{
  for (auto& i : repository_)
  {
    if (i.first->GetName() == tag->GetName())
    {
      ++i.second;
      PLOG_INFO << "Add tag to tag repository (counter + 1)";
      return;
    }
  }
  repository_[tag] = 1;
  PLOG_INFO << "Add tag to tag repository";
}

//  Class member function
//  Add tag (default) to repository
void TagRepository::Add()
{
  std::shared_ptr<Tag> tag_temp = std::make_shared<Tag>(Tag());
  AddTag(tag_temp);
}

//  Class member function
//  Add tag to repository
void TagRepository::Add(Tag tag)
{
  std::shared_ptr<Tag> tag_temp = std::make_shared<Tag>(tag);
  AddTag(tag_temp);
}

//  Class member function
//  Add tag (shared pointer) to repository
void TagRepository::Add(std::shared_ptr<Tag> tag)
{
  AddTag(tag);
}

//  Class member function
//  Remove tag (shared pointer) from repository
void TagRepository::Remove(std::shared_ptr<Tag> tag)
{
  repository_.erase(tag);
  PLOG_INFO << "Remove tag from tag repository";
}

//  Class member function
//  Get name of tag from repository
std::string TagRepository::GetName(TagRepositoryIterator tag) const
{
  return tag->first->GetName();
}

//  Class member function
//  Set name of tag from repository
void TagRepository::SetName(TagRepositoryIterator tag, const std::string& name)
{
  tag->first->SetName(name);
  PLOG_INFO << "Set new name of tag in tag repository";
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
  PLOG_INFO << "Clear tag repository";
}

//  Class member function
//  Find tag (shared pointer) in repository
TagRepositoryConstIterator TagRepository::Find(std::shared_ptr<Tag> tag) const
{
  return repository_.find(tag);
}

//  Class member function
//  Find tag with definite name in repository
TagRepositoryConstIterator TagRepository::Find(std::string name) const
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
TagRepositoryConstIterator TagRepository::Begin() const
{
  return repository_.begin();
}

//  Class member function
//  Find end iterator of repository
TagRepositoryConstIterator TagRepository::End() const
{
  return repository_.end();
}
