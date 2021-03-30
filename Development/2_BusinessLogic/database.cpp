#include "home_bookkeeping/2_BusinessLogic/FinanceRepository.h"

//  Class member function
//  Save to database account repository
void FinanceRepository::SaveToDatabaseAccounts() const
{
  char* err;
  int rc = sqlite3_exec(database_, "CREATE TABLE IF NOT EXISTS Accounts(id INT, name varchar(255), amount DOUBLE);", NULL, NULL, &err);
  if (rc != SQLITE_OK)
  {
    std::cout << "error: " << err << '\n';
  }
  size_t j = 0;
  for (auto i = account_repository_.Begin(); i != account_repository_.End(); ++i)
  {
    std::string id = std::to_string(j);
    std::string name = (**i).GetName();
    std::string amount = std::to_string((**i).GetAmount());
    std::string str = "insert into Accounts VALUES(" + id + ", '" + name + "', " + amount + ")";
    rc = sqlite3_exec(database_, str.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
      std::cout << "insert error: " << err << '\n';
    }
    ++j;
  }
}

