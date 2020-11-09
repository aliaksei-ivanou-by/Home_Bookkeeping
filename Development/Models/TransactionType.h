#pragma once

#ifndef TRANSACTIONTYPE_H
#define TRANSACTIONTYPE_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class TransactionType
{
public:
	enum class type
	{
		Income,
		Expences,
		Transfer
	};
};

#endif