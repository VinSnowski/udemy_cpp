#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"

// Savings Account is a type of Account
//   adds an interest rate
// Withdraw - same as a regular account
// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100)
//      and then the updated amount will be deposited
//

class Checking_Account : public Account
{
  friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);

private:
  static constexpr const char *def_name = "Unnamed Checking Account";
  static constexpr double def_balance = 0.0;
  static constexpr double flat_fee = 1.50;

protected:
  double int_rate;

public:
  Checking_Account(std::string name = def_name, double balance = def_balance);
  bool withdraw(double amount);
  // Inherits the Account::withdraw methods
};

#endif // _CHECKING_ACCOUNT_H_
