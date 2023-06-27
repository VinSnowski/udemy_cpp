#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"

// Savings Account is a type of Account
//   adds an interest rate
// Withdraw - same as a regular account
// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100)
//      and then the updated amount will be deposited
//

class Trust_Account : public Savings_Account
{
  friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);

private:
  static constexpr const char *def_name = "Unnamed Trust Account";
  static constexpr double def_balance = 0.0;
  static constexpr double def_int_rate = 0.0;
  static constexpr double max_withdraw_percentage = 0.20;
  static constexpr double bonus_amount = 50;
  static constexpr double bonus_min_threshold = 5000;
  int remaining_withdraws = 3;

protected:
  double int_rate;

public:
  Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
  bool deposit(double amount);
  bool withdraw(double amount);
  // Inherits the Account::withdraw methods
};

#endif // _Trust_ACCOUNT_H_
