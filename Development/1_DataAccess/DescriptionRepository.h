#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Description.h"

using DescriptionRepositoryIterator = std::set<Description>::iterator;

class DescriptionRepository
{
private:
	std::set<Description> repository;
public:
	DescriptionRepository();
	void add(Description descriptionForAdd);
	void remove(Description descriptionForRemove);
	size_t size() const;
	void clear();
	DescriptionRepositoryIterator find(const Description& descriptionForFind) const;
	DescriptionRepositoryIterator begin() const;
	DescriptionRepositoryIterator end() const;
};