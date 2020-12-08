#pragma once

#include "../include/stdafx.h"

class Tag
{
private:
	std::string tagName;
public:
	Tag();
	Tag(std::string tagNameNew);
	std::string getTagName() const;
	void setTagName(std::string&& tagNameNew);
	friend bool operator<(const Tag& leftTag, const Tag& rightTag);
	friend std::ostream& operator<<(std::ostream& outputStream, const Tag& tag);
};