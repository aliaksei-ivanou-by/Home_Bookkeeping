#include "CommentRepository.h"

CommentRepository::CommentRepository()
{}

void CommentRepository::add(Comment commentForAdd)
{
	repository.insert(commentForAdd);
}

void CommentRepository::remove(Comment commentForRemove)
{
	repository.erase(commentForRemove);
}

size_t CommentRepository::size() const
{
	return repository.size();
}

void CommentRepository::clear()
{
	repository.clear();
}

CommentRepositoryIterator CommentRepository::find(Comment&& commentForFind) const
{
	return repository.find(std::move(commentForFind));
}