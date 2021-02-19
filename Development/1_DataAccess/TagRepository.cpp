#include "TagRepository.h"

TagRepository::TagRepository()
{}

void TagRepository::add(Tag tagForAdd)
{
	repository.insert(std::make_shared<Tag>(tagForAdd));
}

void TagRepository::remove(std::shared_ptr<Tag> tagForRemove)
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

TagRepositoryIterator TagRepository::find(std::shared_ptr<Tag> tagForFind) const
{
	return repository.find(tagForFind);
}

TagRepositoryIterator TagRepository::begin() const
{
	return repository.begin();
}

TagRepositoryIterator TagRepository::end() const
{
	return repository.end();
}