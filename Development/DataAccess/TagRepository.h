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
	std::set<Tag> repository;
public:
	TagRepository() {}
	void add(Tag name)
	{
		repository.insert(name);
	}
	void remove(Tag name)
	{
		repository.erase(name);
	}
};

#endif