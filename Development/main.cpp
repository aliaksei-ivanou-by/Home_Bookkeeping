#include "include/DataAccess2.h"

void Book_Keeping()
{
	TransactionRepository r_t;
	CategoryRepository arr = r_t.get_categories();
	for (auto i : arr.get_categories())
	{
		std::cout << i << '\n';
	}
}

int main()
{
	Book_Keeping();
	return 0;
}