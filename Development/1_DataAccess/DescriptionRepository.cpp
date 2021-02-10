#include "DescriptionRepository.h"

DescriptionRepository::DescriptionRepository()
{}

void DescriptionRepository::addDescription(Description descriptionForAdd)
{
	descriptionRepository.insert(descriptionForAdd);
}

void DescriptionRepository::removeDescription(Description descriptionForRemove)
{
	descriptionRepository.erase(descriptionForRemove);
}

std::set<Description> DescriptionRepository::getDescriptionRepository() const
{
	return descriptionRepository;
}

void DescriptionRepository::setDescriptionRepository(std::set<Description>&& descriptionsForAdd)
{
	descriptionRepository = descriptionsForAdd;
}