#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Tag.h"

using TagRepositoryIterator = std::set<Tag>::iterator;

class TagRepository
{
private:
	std::set<Tag> repository;
public:
	TagRepository();
	void add(Tag tagForAdd);
	void remove(Tag tagForRemove);
	size_t size() const;
	void clear();
	TagRepositoryIterator find(Tag&& tagForFind) const;
};