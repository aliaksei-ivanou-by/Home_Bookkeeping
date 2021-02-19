#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Description.h"

using DescriptionRepositoryIterator = std::set<std::shared_ptr<Description>>::iterator;

class DescriptionRepository
{
private:
	std::set<std::shared_ptr<Description>> repository;
public:
	DescriptionRepository();
	void add(Description descriptionForAdd);
	void add(std::shared_ptr<Description> descriptionForAdd);
	void remove(std::shared_ptr<Description> descriptionForRemove);
	size_t size() const;
	void clear();
	DescriptionRepositoryIterator find(std::shared_ptr<Description> descriptionForFind) const;
	DescriptionRepositoryIterator begin() const;
	DescriptionRepositoryIterator end() const;
};