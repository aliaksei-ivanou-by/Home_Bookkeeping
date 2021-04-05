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
//  Make command to create table for repository in database
std::string CommentRepository::MakeCommandToCreateRepositoryInDatabase() const
{
  return "CREATE TABLE IF NOT EXISTS Comments(id INTEGER NOT NULL PRIMARY KEY, name VARCHAR(255) NOT NULL);";
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

//  Class member function
//  Make command to remove table for repository from database
std::string CommentRepository::MakeCommandToRemoveRepositoryFromDatabase() const
{
  return "DROP TABLE IF EXISTS Comments";
}
