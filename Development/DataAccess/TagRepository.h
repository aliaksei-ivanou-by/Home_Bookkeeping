#pragma once

#include "../include/stdafx.h"
#include "../Models/Tag.h"

class TagRepository
{
private:
	std::set<Tag> tagRepository;
public:
	TagRepository();
	void addTag(Tag tagForAdd);
	void removeTag(Tag tagForRemove);
	std::set<Tag> getTagRepository() const;
	void setTagRepository(std::set<Tag>&& tagsForAdd);
};