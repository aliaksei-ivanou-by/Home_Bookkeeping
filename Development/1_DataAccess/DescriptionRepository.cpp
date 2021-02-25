#include "DescriptionRepository.h"

// Default constructor
DescriptionRepository::DescriptionRepository()
{}

// Class member function. Add description to repository
void DescriptionRepository::add(Description descriptionForAdd)
{
	repository.insert(std::make_shared<Description>(descriptionForAdd));
}

// Class member function. Add shared pointer to description to repository
void DescriptionRepository::add(std::shared_ptr<Description> descriptionForAdd)
{
	repository.insert(descriptionForAdd);
}

// Class member function. Remove shared pointer to description from repository
void DescriptionRepository::remove(std::shared_ptr<Description> descriptionForRemove)
{
	repository.erase(descriptionForRemove);
}

// Class member function. Calculate size of repository
size_t DescriptionRepository::size() const
{
	return repository.size();
}

// Class member function. Clear repository
void DescriptionRepository::clear()
{
	repository.clear();
}

// Class member function. Find shared pointer to description in repository
DescriptionRepositoryIterator DescriptionRepository::find(std::shared_ptr<Description> descriptionForFind) const
{
	return repository.find(descriptionForFind);
}

// Class member function. Find begin iterator of repository
DescriptionRepositoryIterator DescriptionRepository::begin() const
{
	return repository.begin();

}

// Class member function. Find end iterator of repository
DescriptionRepositoryIterator DescriptionRepository::end() const
{
	return repository.end();
}