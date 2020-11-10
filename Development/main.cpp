#ifndef DATAACCESS2_H
#include "include/DataAccess2.h"
#endif

#ifndef TRANSACTIONSFUNCTIONS_H
#include "BusinessLogic/TransactionsFunctions.h"
#endif

void Book_Keeping()
{
	TransactionRepository r_t;
	default_transaction_repository(r_t);
	print_categories(r_t);
}

int main()
{
	Book_Keeping();
	return 0;
}