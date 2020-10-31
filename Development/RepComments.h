#ifndef REPCOMMENTS_H
#define REPCOMMENTS_H

#include "stdafx.h"

class Comments
{
private:
	std::string Comment_Name;
public:
	Comments();
	Comments(std::string name);
	std::string get_name() const;
	void set_name(std::string name);
};

class Rep_Comments
{
private:
	Comments comments;
	std::set<Comments> repository;
public:
	Rep_Comments();
	void add(std::string tag);
	void remove(std::string tag);
	void print() const;
};

#endif