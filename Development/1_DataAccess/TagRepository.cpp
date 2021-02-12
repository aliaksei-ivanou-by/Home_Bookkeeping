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

void TagRepository::clearTagRepository()
{
	tagRepository.clear();
}

TagRepositoryIterator TagRepository::findPayeeRepository(Tag&& tagForFind)
{
	return tagRepository.find(std::move(tagForFind));
}