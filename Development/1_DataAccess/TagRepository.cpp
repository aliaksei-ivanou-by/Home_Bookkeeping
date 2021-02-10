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

std::set<Tag> TagRepository::getTagRepository() const
{
	return tagRepository;
}

void TagRepository::setTagRepository(std::set<Tag>&& tagsForAdd)
{
	tagRepository = tagsForAdd;
}