#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Payee.h"

using PayeeRepositoryIterator = std::set<Payee>::iterator;

class PayeeRepository
{
private:
	std::set<Payee> repository;
public:
	PayeeRepository();
	void add(Payee payeeForAdd);
	void remove(Payee payeeForRemove);
	size_t size() const;
	void clear();
	PayeeRepositoryIterator find(const Payee& payeeForFind) const;
	PayeeRepositoryIterator begin() const;
	PayeeRepositoryIterator end() const;
};