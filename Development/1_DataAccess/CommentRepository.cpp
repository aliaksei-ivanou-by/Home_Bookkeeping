#include "CommentRepository.h"

CommentRepository::CommentRepository()
{}

void CommentRepository::add(Comment commentForAdd)
{
	repository.insert(std::make_shared<Comment>(commentForAdd));
}

void CommentRepository::add(std::shared_ptr<Comment> commentForAdd)
{
	repository.insert(commentForAdd);
}

void CommentRepository::remove(std::shared_ptr<Comment> commentForRemove)
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

CommentRepositoryIterator CommentRepository::find(std::shared_ptr<Comment> commentForFind) const
{
	return repository.find(commentForFind);
}

CommentRepositoryIterator CommentRepository::begin() const
{
	return repository.begin();
}

CommentRepositoryIterator CommentRepository::end() const
{
	return repository.end();
}