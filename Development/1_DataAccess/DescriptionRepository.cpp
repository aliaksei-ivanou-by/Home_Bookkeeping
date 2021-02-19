#include "DescriptionRepository.h"

DescriptionRepository::DescriptionRepository()
{}

void DescriptionRepository::add(Description descriptionForAdd)
{
	repository.insert(std::make_shared<Description>(descriptionForAdd));
}

void DescriptionRepository::add(std::shared_ptr<Description> descriptionForAdd)
{
	repository.insert(descriptionForAdd);
}

void DescriptionRepository::remove(std::shared_ptr<Description> descriptionForRemove)
{
	repository.erase(descriptionForRemove);
}

size_t DescriptionRepository::size() const
{
	return repository.size();
}

void DescriptionRepository::clear()
{
	repository.clear();
}

DescriptionRepositoryIterator DescriptionRepository::find(std::shared_ptr<Description> descriptionForFind) const
{
	return repository.find(descriptionForFind);
}

DescriptionRepositoryIterator DescriptionRepository::begin() const
{
	return repository.begin();

}

DescriptionRepositoryIterator DescriptionRepository::end() const
{
	return repository.end();
}