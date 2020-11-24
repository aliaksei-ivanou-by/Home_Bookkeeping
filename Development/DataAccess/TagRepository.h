#pragma once

#ifndef TAGREPOSITORY_H
#define TAGREPOSITORY_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

#ifndef TAG_H
#include "../Models/Tag.h"
#endif

class TagRepository
{
private:
	std::set<Tag> tagRepository;
public:
	TagRepository()
	{}
	void addTag(Tag tag)
	{
		tagRepository.insert(tag);
	}
	void removeTag(Tag tag)
	{
		tagRepository.erase(tag);
	}
	std::set<Tag> getTagRepository() const
	{
		return tagRepository;
	}
	void setTagRepository(std::set<Tag>&& tags)
	{
		tagRepository = tags;
	}
};

#endif