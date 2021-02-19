#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Comment.h"

using CommentRepositoryIterator = std::set<std::shared_ptr<Comment>>::iterator;

class CommentRepository
{
private:
	std::set<std::shared_ptr<Comment>> repository;
public:
	CommentRepository();
	void add(Comment commentForAdd);
	void add(std::shared_ptr<Comment> commentForAdd);
	void remove(std::shared_ptr<Comment> commentForRemove);
	size_t size() const;
	void clear();
	CommentRepositoryIterator find(std::shared_ptr<Comment> commentForFind) const;
	CommentRepositoryIterator begin() const;
	CommentRepositoryIterator end() const;
};