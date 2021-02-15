#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Comment.h"

using CommentRepositoryIterator = std::set<Comment>::iterator;

class CommentRepository
{
private:
	std::set<Comment> repository;
public:
	CommentRepository();
	void add(Comment commentForAdd);
	void remove(Comment commentForRemove);
	size_t size() const;
	void clear();
	CommentRepositoryIterator find(const Comment& commentForFind) const;
	CommentRepositoryIterator begin() const;
	CommentRepositoryIterator end() const;
};