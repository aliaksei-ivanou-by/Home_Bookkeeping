#include "DescriptionRepository.h"

DescriptionRepository::DescriptionRepository()
{}

void DescriptionRepository::add(Description descriptionForAdd)
{
	repository.insert(descriptionForAdd);
}

void DescriptionRepository::remove(Description descriptionForRemove)
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

DescriptionRepositoryIterator DescriptionRepository::find(Description&& descriptionForFind) const
{
	return repository.find(std::move(descriptionForFind));
}