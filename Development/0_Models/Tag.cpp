#include "Tag.h"

Tag::Tag():
	tagName{ "" }
{}

Tag::Tag(std::string tagNameForAdd):
	tagName{ tagNameForAdd }
{}

std::string Tag::getTagName() const
{
	return tagName;
}

void Tag::setTagName(std::string&& tagNameNewForUpdate)
{
	tagName = std::move(tagNameNewForUpdate);
}

bool operator<(const Tag& leftTag, const Tag& rightTag)
{
	return (leftTag.getTagName()) < (rightTag.getTagName());
}
std::ostream& operator<<(std::ostream& outputStream, const Tag& tag)
{
	return outputStream << tag.getTagName();
}