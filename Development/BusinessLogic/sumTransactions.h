#pragma once

#include "../include/stdafx.h"
#include "../include/DataAccess.h"

double sumTransactionsByTransactionType(const FinanceRepository& mainRepository, TransactionType transactionType);