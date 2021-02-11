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