#pragma once

#ifndef TAG_H
#define TAG_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class Tag
{
private:
	std::string tagName;
public:
	Tag()
		: tagName{ "" }
	{}
	Tag(std::string tagName)
		: tagName{ tagName }
	{}
	std::string getTagName() const
	{
		return this->tagName;
	}
	void setTagName(std::string&& tagName)
	{
		this->tagName = tagName;
	}
	friend bool operator<(const Tag& leftTag, const Tag& rightTag)
	{
		return (leftTag.getTagName()) < (rightTag.getTagName());
	}
	friend std::ostream& operator<<(std::ostream& outputStream, const Tag& tag)
	{
		return outputStream << tag.getTagName();
	}
};

#endif