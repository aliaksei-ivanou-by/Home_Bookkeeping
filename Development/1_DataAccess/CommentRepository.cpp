#include "CommentRepository.h"

// Default constructor
CommentRepository::CommentRepository()
{}

// Class member function. Add comment to repository
void CommentRepository::add(Comment commentForAdd)
{
	repository.insert(std::make_shared<Comment>(commentForAdd));
}

// Class member function. Add shared pointer to comment to repository
void CommentRepository::add(std::shared_ptr<Comment> commentForAdd)
{
	repository.insert(commentForAdd);
}

// Class member function. Remove shared pointer to comment from repository
void CommentRepository::remove(std::shared_ptr<Comment> commentForRemove)
{
	repository.erase(commentForRemove);
}

// Class member function. Calculate size of repository
size_t CommentRepository::size() const
{
	return repository.size();
}

// Class member function. Clear repository
void CommentRepository::clear()
{
	repository.clear();
}

// Class member function. Find shared pointer to comment in repository
CommentRepositoryIterator CommentRepository::find(std::shared_ptr<Comment> commentForFind) const
{
	return repository.find(commentForFind);
}

// Class member function. Find begin iterator of repository
CommentRepositoryIterator CommentRepository::begin() const
{
	return repository.begin();
}

// Class member function. Find end iterator of repository
CommentRepositoryIterator CommentRepository::end() const
{
	return repository.end();
}