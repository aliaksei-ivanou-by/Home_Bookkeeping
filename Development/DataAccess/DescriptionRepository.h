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
	std::set<Description> descriptionRepository;
public:
	DescriptionRepository()
	{}
	void addDescription(Description description)
	{
		descriptionRepository.insert(description);
	}
	void removeDescription(Description description)
	{
		descriptionRepository.erase(description);
	}
	std::set<Description> getDescriptionRepository() const
	{
		return descriptionRepository;
	}
	void setDescriptionRepository(std::set<Description>&& descriptions)
	{
		descriptionRepository = descriptions;
	}
};

#endif