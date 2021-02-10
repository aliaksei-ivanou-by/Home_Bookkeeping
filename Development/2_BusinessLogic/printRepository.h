#pragma once

#include "../include/stdafx.h"
#include "../include/1_DataAccess.h"

void printAccounts(const FinanceRepository& mainRepository);

void printCategories(const FinanceRepository& mainRepository);

void printCurrencies(const FinanceRepository& mainRepository);

void printTransactions(const FinanceRepository& mainRepository);