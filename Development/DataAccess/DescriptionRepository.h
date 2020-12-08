#pragma once

#include "../include/stdafx.h"
#include "../Models/Description.h"

class DescriptionRepository
{
private:
	std::set<Description> descriptionRepository;
public:
	DescriptionRepository();
	void addDescription(Description descriptionForAdd);
	void removeDescription(Description descriptionForRemove);
	std::set<Description> getDescriptionRepository() const;
	void setDescriptionRepository(std::set<Description>&& descriptionsForAdd);
};