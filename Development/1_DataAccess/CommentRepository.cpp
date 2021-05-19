#include "home_bookkeeping/1_DataAccess/CommentRepository.h"

//  Constructor
//  Default
CommentRepository::CommentRepository()
{}

//  Class member function (private)
//  Add comment (shared pointer) to repository
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

//  Class member function
//  Add comment (default) to repository
void CommentRepository::Add()
{
  std::shared_ptr<Comment> comment_temp = std::make_shared<Comment>(Comment());
  AddComment(comment_temp);
}

//  Class member function
//  Add comment to repository
void CommentRepository::Add(Comment comment)
{
  std::shared_ptr<Comment> comment_temp = std::make_shared<Comment>(comment);
  AddComment(comment_temp);
}

//  Class member function
//  Add comment (shared pointer) to repository
void CommentRepository::Add(std::shared_ptr<Comment> comment)
{
  AddComment(comment);
}

//  Class member function
//  Remove comment (shared pointer) from repository
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

//  Class member function
//  Get name of comment from repository
std::string CommentRepository::GetName(CommentRepositoryIterator comment) const
{
  return comment->first->GetName();
}

//  Class member function
//  Set name of comment from repository
void CommentRepository::SetName(CommentRepositoryIterator comment, const std::string& name)
{
  comment->first->SetName(name);
  PLOG_INFO << "Set new name of comment in comment repository";
}

//  Class member function
//  Calculate size of repository
size_t CommentRepository::Size() const
{
  return repository_.size();
}

//  Class member function
//  Clear repository
void CommentRepository::Clear()
{
  repository_.clear();
  PLOG_INFO << "Clear comment repository";
}

//  Class member function
//  Find comment (shared pointer) in repository
CommentRepositoryConstIterator CommentRepository::Find(std::shared_ptr<Comment> comment) const
{
  return repository_.find(comment);
}

//  Class member function
//  Find comment with definite name in repository
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

//  Class member function
//  Find begin iterator of repository
CommentRepositoryConstIterator CommentRepository::Begin() const
{
  return repository_.begin();
}

//  Class member function
//  Find end iterator of repository
CommentRepositoryConstIterator CommentRepository::End() const
{
  return repository_.end();
}
