#include "TagRepository.h"

TagRepository::TagRepository()
{}

void TagRepository::add(Tag tagForAdd)
{
	repository.insert(tagForAdd);
}

void TagRepository::remove(Tag tagForRemove)
{
	repository.erase(tagForRemove);
}

size_t TagRepository::size() const
{
	return repository.size();
}

void TagRepository::clear()
{
	repository.clear();
}

TagRepositoryIterator TagRepository::find(Tag&& tagForFind) const
{
	return repository.find(std::move(tagForFind));
}

TagRepositoryIterator TagRepository::begin() const
{
	return repository.begin();
}

TagRepositoryIterator TagRepository::end() const
{
	return repository.end();
}