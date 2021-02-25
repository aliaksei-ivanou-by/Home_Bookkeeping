#pragma once
#include "../include/stdafx.h"
#include "../0_Models/Description.h"

/*
Class DescriptionRepository
Includes repository of descriptions.

Constructors:
	Default

Class member functions:
	Add description to repository
	Add shared pointer to description to repository
	Remove shared pointer to description from repository
	Calculate size of repository
	Clear repository
	Find shared pointer to description in repository
	Find begin iterator of repository
	Find end iterator of repository
*/

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