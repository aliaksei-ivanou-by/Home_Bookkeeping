#include "include/1_DataAccess/CommentRepository.h"

CommentRepository::CommentRepository()
{}

void CommentRepository::AddComment(std::shared_ptr<Comment> comment)
{
  for (auto& i : repository_)
  {
    if (i.first->GetName() == comment->GetName())
    {
      ++i.second;
      PLOG_INFO << "Add comment to comment repository (counter + 1)";
      return;
    }
  }
  repository_[comment] = 1;
  PLOG_INFO << "Add comment to comment repository";
}

void CommentRepository::Add()
{
  std::shared_ptr<Comment> comment_temp = std::make_shared<Comment>(Comment());
  AddComment(comment_temp);
}

void CommentRepository::Add(Comment comment)
{
  std::shared_ptr<Comment> comment_temp = std::make_shared<Comment>(comment);
  AddComment(comment_temp);
}

void CommentRepository::Add(std::shared_ptr<Comment> comment)
{
  AddComment(comment);
}

void CommentRepository::Remove(std::shared_ptr<Comment> comment)
{
  auto iterator = repository_.find(comment);
  if (iterator != repository_.end())
  {
    repository_.erase(iterator);
    PLOG_INFO << "Remove comment from comment repository";
  }
  else
  {
    PLOG_ERROR << "Comment repository haven't got comment '" << comment->GetName() << "'";
  }
}

std::string CommentRepository::GetName(CommentRepositoryIterator comment) const
{
  return comment->first->GetName();
}

void CommentRepository::SetName(CommentRepositoryIterator comment, const std::string& name)
{
  comment->first->SetName(name);
  PLOG_INFO << "Set new name of comment in comment repository";
}

size_t CommentRepository::Size() const
{
  return repository_.size();
}

void CommentRepository::Clear()
{
  repository_.clear();
  PLOG_INFO << "Clear comment repository";
}

CommentRepositoryConstIterator CommentRepository::Find(std::shared_ptr<Comment> comment) const
{
  return repository_.find(comment);
}

CommentRepositoryConstIterator CommentRepository::Find(const std::string& name) const
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

CommentRepositoryConstIterator CommentRepository::Begin() const
{
  return repository_.begin();
}

CommentRepositoryConstIterator CommentRepository::End() const
{
  return repository_.end();
}
