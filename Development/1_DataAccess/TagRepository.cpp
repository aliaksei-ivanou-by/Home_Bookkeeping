#include "TagRepository.h"

// Default constructor
TagRepository::TagRepository()
{}

// Class member function. Add tag to repository
void TagRepository::add(Tag tagForAdd)
{
	repository.insert(std::make_shared<Tag>(tagForAdd));
}

// Class member function. Add shared pointer to tag to repository
void TagRepository::add(std::shared_ptr<Tag> tagForAdd)
{
	repository.insert(tagForAdd);
}

// Class member function. Remove shared pointer to tag from repository
void TagRepository::remove(std::shared_ptr<Tag> tagForRemove)
{
	repository.erase(tagForRemove);
}

// Class member function. Calculate size of repository
size_t TagRepository::size() const
{
	return repository.size();
}

// Class member function. Clear repository
void TagRepository::clear()
{
	repository.clear();
}

// Class member function. Find shared pointer to tag in repository
TagRepositoryIterator TagRepository::find(std::shared_ptr<Tag> tagForFind) const
{
	return repository.find(tagForFind);
}

// Class member function. Find begin iterator of repository
TagRepositoryIterator TagRepository::begin() const
{
	return repository.begin();
}

// Class member function. Find end iterator of repository
TagRepositoryIterator TagRepository::end() const
{
	return repository.end();
}