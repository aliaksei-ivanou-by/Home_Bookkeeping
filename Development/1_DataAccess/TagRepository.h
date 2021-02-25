#pragma once
#include "../include/stdafx.h"
#include "../0_Models/Tag.h"

/*
Class TagRepository
Includes repository of tags.

Constructors:
	Default

Class member functions:
	Add tag to repository
	Add shared pointer to tag to repository
	Remove shared pointer to tag from repository
	Calculate size of repository
	Clear repository
	Find shared pointer to tag in repository
	Find begin iterator of repository
	Find end iterator of repository
*/

using TagRepositoryIterator = std::set<std::shared_ptr<Tag>>::iterator;

class TagRepository
{
private:
	std::set<std::shared_ptr<Tag>> repository;
public:
	TagRepository();

	void add(Tag tagForAdd);
	void add(std::shared_ptr<Tag> tagForAdd);

	void remove(std::shared_ptr<Tag> tagForRemove);

	size_t size() const;

	void clear();

	TagRepositoryIterator find(std::shared_ptr<Tag> tagForFind) const;

	TagRepositoryIterator begin() const;
	TagRepositoryIterator end() const;
};