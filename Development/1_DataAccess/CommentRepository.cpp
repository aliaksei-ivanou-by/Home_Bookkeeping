#include "home_bookkeeping/1_DataAccess/CommentRepository.h"

//  Constructor
//  Default
CommentRepository::CommentRepository()
{}

//  Class member function
//  Add comment (default) to repository
void CommentRepository::Add()
{
  repository_.insert(std::make_shared<Comment>());
  PLOG_INFO << "Add comment to comment repository";
}

//  Class member function
//  Add comment to repository
void CommentRepository::Add(Comment comment)
{
  repository_.insert(std::make_shared<Comment>(comment));
  PLOG_INFO << "Add comment to comment repository";
}

//  Class member function
//  Add comment (shared pointer) to repository
void CommentRepository::Add(std::shared_ptr<Comment> comment)
{
  repository_.insert(comment);
  PLOG_INFO << "Add comment to comment repository";
}

//  Class member function
//  Remove comment (shared pointer) from repository
void CommentRepository::Remove(std::shared_ptr<Comment> comment)
{
  repository_.erase(comment);
  PLOG_INFO << "Remove comment from comment repository";
}

//  Class member function
//  Get name of comment from repository
std::string CommentRepository::GetName(CommentRepositoryIterator comment) const
{
  return (**comment).GetName();
}

//  Class member function
//  Set name of comment from repository
void CommentRepository::SetName(CommentRepositoryIterator comment, const std::string& name)
{
  (**comment).SetName(name);
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
CommentRepositoryIterator CommentRepository::Find(std::shared_ptr<Comment> comment) const
{
  return repository_.find(comment);
}

//  Class member function
//  Find comment with definite name in repository
CommentRepositoryIterator CommentRepository::Find(const std::string& name) const
{
  for (auto i = repository_.begin(); i != repository_.end(); ++i)
  {
    if ((**i).GetName() == name)
    {
      return i;
    }
  }
  return repository_.end();
}

//  Class member function
//  Find begin iterator of repository
CommentRepositoryIterator CommentRepository::Begin() const
{
  return repository_.begin();
}

//  Class member function
//  Find end iterator of repository
CommentRepositoryIterator CommentRepository::End() const
{
  return repository_.end();
}

//  Class member function
//  Make command to insert repository to database to table
std::string CommentRepository::MakeCommandToInsertRepositoryToDatabase(size_t id, CommentRepositoryIterator iterator) const
{
  return "INSERT INTO Comments VALUES(" +
    std::to_string(id)
    + ", '" +
    (**iterator).GetName()
    + "')";
}
