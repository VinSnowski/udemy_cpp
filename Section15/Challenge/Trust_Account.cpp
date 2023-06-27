
#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate) : Savings_Account{name, balance, int_rate}
{
}

bool Trust_Account::deposit(double amount)
{
  if (amount >= bonus_min_threshold)
  {
    balance += bonus_amount;
  }
  return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
  if (remaining_withdraws > 0 && amount < max_withdraw * balance)
  {
    remaining_withdraws--;
    return Savings_Account::withdraw(amount);
  }
  else
    return false;
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account)
{
  os << "[Trust_Account: " << account.name << ": " << account.balance << ", Remaining Withdraws:" << account.remaining_withdraws << "]";
  return os;
}
