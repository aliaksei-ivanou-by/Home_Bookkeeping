#include "Tag.h"

// Default constructor
Tag::Tag():
	tagName{ "" }
{}

// Constructor with the setting of the name of the tag
Tag::Tag(const std::string& tagNameForAdd):
	tagName{ tagNameForAdd }
{}

// Class member function. Get the name of the tag
std::string Tag::getTagName() const
{
	return tagName;
}

// Class member function. Set the name of the tag
void Tag::setTagName(const std::string& tagNameNewForUpdate)
{
	tagName = tagNameNewForUpdate;
}

// Class member function. Operator < for sorting tags
bool operator<(const Tag& leftTag, const Tag& rightTag)
{
	return (leftTag.getTagName()) < (rightTag.getTagName());
}

// Class member function. Print tag
std::ostream& operator<<(std::ostream& outputStream, const Tag& tag)
{
	return outputStream << tag.getTagName();
}