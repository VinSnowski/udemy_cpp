#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance) : Account{name, balance}
{
}

bool Checking_Account::withdraw(double amount)
{
  double total{amount + flat_fee};
  if (balance < total)
    return false;
  else
  {
    balance -= total;
    return true;
  }
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account)
{
  os << "[Checking_Account: " << account.name << ": " << account.balance << "]";
  return os;
}
