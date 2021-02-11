#include "TagRepository.h"

TagRepository::TagRepository()
{}

void TagRepository::addTag(Tag tagForAdd)
{
	tagRepository.insert(tagForAdd);
}

void TagRepository::removeTag(Tag tagForRemove)
{
	tagRepository.erase(tagForRemove);
}

size_t TagRepository::sizeTagRepository()
{
	return tagRepository.size();
}