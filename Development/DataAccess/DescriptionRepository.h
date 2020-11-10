#pragma once

#ifndef DESCRIPTIONREPOSITORY_H
#define DESCRIPTIONREPOSITORY_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

#ifndef DESCRIPTION_H
#include "../Models/Description.h"
#endif

class DescriptionRepository
{
private:
	std::set<Description> repository;
public:
	DescriptionRepository() {}
	void add(Description name)
	{
		repository.insert(name);
	}
	void remove(Description name)
	{
		repository.erase(name);
	}
};

#endif