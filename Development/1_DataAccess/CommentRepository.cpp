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
}

//  Class member function
//  Add comment to repository
void CommentRepository::Add(Comment comment)
{
  repository_.insert(std::make_shared<Comment>(comment));
}

//  Class member function
//  Add comment (shared pointer) to repository
void CommentRepository::Add(std::shared_ptr<Comment> comment)
{
  repository_.insert(comment);
}

//  Class member function
//  Remove comment (shared pointer) from repository
void CommentRepository::Remove(std::shared_ptr<Comment> comment)
{
  repository_.erase(comment);
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
}

//  Class member function
//  Find comment (shared pointer) in repository
CommentRepositoryIterator CommentRepository::Find(std::shared_ptr<Comment> comment) const
{
  return repository_.find(comment);
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
