#include "home_bookkeeping/1_DataAccess/DescriptionRepository.h"

//  Constructor
//  Default
DescriptionRepository::DescriptionRepository()
{}

//  Class member function
//  Add description (default) to repository
void DescriptionRepository::Add()
{
  repository_.insert(std::make_shared<Description>());
}

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
//  Get name of description from repository
std::string DescriptionRepository::GetName(DescriptionRepositoryIterator description) const
{
  return (**description).GetName();
}

//  Class member function
//  Set name of description from repository
void DescriptionRepository::SetName(DescriptionRepositoryIterator description, const std::string& name)
{
  (**description).SetName(name);
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
//  Find description with definite name in repository
DescriptionRepositoryIterator DescriptionRepository::Find(const std::string& name) const
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

//  Class member function
//  Make command to create table for repository in database
std::string DescriptionRepository::MakeCommandToCreateRepositoryInDatabase() const
{
  return "CREATE TABLE IF NOT EXISTS Descriptions(id INTEGER NOT NULL PRIMARY KEY, name VARCHAR(255) NOT NULL);";
}

//  Class member function
//  Make command to insert repository to database to table
std::string DescriptionRepository::MakeCommandToInsertRepositoryToDatabase(size_t id, DescriptionRepositoryIterator iterator) const
{
  return "INSERT INTO Descriptions VALUES(" +
    std::to_string(id)
    + ", '" +
    (**iterator).GetName()
    + "')";
}

//  Class member function
//  Make command to remove table for repository from database
std::string DescriptionRepository::MakeCommandToRemoveRepositoryFromDatabase() const
{
  return "DROP TABLE IF EXISTS Descriptions";
}
