#include "include/1_DataAccess/TagRepository.h"

TagRepository::TagRepository()
{}

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

void TagRepository::Add()
{
  std::shared_ptr<Tag> tag_temp = std::make_shared<Tag>(Tag());
  AddTag(tag_temp);
}

void TagRepository::Add(Tag tag)
{
  std::shared_ptr<Tag> tag_temp = std::make_shared<Tag>(tag);
  AddTag(tag_temp);
}

void TagRepository::Add(std::shared_ptr<Tag> tag)
{
  AddTag(tag);
}

void TagRepository::Remove(std::shared_ptr<Tag> tag)
{
  repository_.erase(tag);
  PLOG_INFO << "Remove tag from tag repository";
}

std::string TagRepository::GetName(TagRepositoryIterator tag) const
{
  return tag->first->GetName();
}

void TagRepository::SetName(TagRepositoryIterator tag, const std::string& name)
{
  tag->first->SetName(name);
  PLOG_INFO << "Set new name of tag in tag repository";
}

size_t TagRepository::Size() const
{
  return repository_.size();
}

void TagRepository::Clear()
{
  repository_.clear();
  PLOG_INFO << "Clear tag repository";
}

TagRepositoryConstIterator TagRepository::Find(std::shared_ptr<Tag> tag) const
{
  return repository_.find(tag);
}

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

TagRepositoryConstIterator TagRepository::Begin() const
{
  return repository_.begin();
}

TagRepositoryConstIterator TagRepository::End() const
{
  return repository_.end();
}
