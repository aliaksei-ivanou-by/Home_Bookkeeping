#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Tag.h"

class TagRepository
{
private:
	std::set<Tag> tagRepository;
public:
	TagRepository();
	void addTag(Tag tagForAdd);
	void removeTag(Tag tagForRemove);
	size_t sizeTagRepository();
};