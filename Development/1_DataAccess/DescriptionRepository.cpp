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

size_t DescriptionRepository::sizeDescriptionRepository()
{
	return descriptionRepository.size();
}