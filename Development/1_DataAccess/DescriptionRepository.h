#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Description.h"

using DescriptionRepositoryIterator = std::set<Description>::iterator;

class DescriptionRepository
{
private:
	std::set<Description> descriptionRepository;
public:
	DescriptionRepository();
	void addDescription(Description descriptionForAdd);
	void removeDescription(Description descriptionForRemove);
	size_t sizeDescriptionRepository() const;
	void clearDescriptionRepository();
	DescriptionRepositoryIterator findDescriptionRepository(Description&& descriptionForFind) const;
};