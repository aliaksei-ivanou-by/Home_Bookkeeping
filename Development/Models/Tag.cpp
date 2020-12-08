#include "Tag.h"

Tag::Tag():
	tagName{ "" }
{}

Tag::Tag(std::string tagNameNew):
	tagName{ tagNameNew }
{}

std::string Tag::getTagName() const
{
	return tagName;
}

void Tag::setTagName(std::string&& tagNameNew)
{
	tagName = std::move(tagNameNew);
}

bool operator<(const Tag& leftTag, const Tag& rightTag)
{
	return (leftTag.getTagName()) < (rightTag.getTagName());
}
std::ostream& operator<<(std::ostream& outputStream, const Tag& tag)
{
	return outputStream << tag.getTagName();
}