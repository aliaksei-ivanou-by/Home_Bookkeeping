#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Tag.h"

using TagRepositoryIterator = std::set<Tag>::iterator;

class TagRepository
{
private:
	std::set<Tag> tagRepository;
public:
	TagRepository();
	void addTag(Tag tagForAdd);
	void removeTag(Tag tagForRemove);
	size_t sizeTagRepository() const;
	void clearTagRepository();
	TagRepositoryIterator findPayeeRepository(Tag&& tagForFind) const;
};