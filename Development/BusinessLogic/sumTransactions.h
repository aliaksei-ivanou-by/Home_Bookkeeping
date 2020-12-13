#pragma once

#include "../include/stdafx.h"
#include "../include/DataAccess.h"

double sumTransactionsByTransactionTypeFullTime(const FinanceRepository& mainRepository, TransactionType transactionType);

double sumTransactionsByTransactionTypeToday(const FinanceRepository& mainRepository, TransactionType transactionType, Time time);

double sumTransactionsByTransactionTypeThisMonth(const FinanceRepository& mainRepository, TransactionType transactionType, Time time);