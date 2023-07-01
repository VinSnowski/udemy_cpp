#ifndef __INSUFFICIENT_FUNDS_EXCEPTION_H__
#define __INSUFFICIENT_FUNDS_EXCEPTION_H__

class InsufficientFundsException : public std::exception
{
public:
  InsufficientFundsException() {}
  ~InsufficientFundsException() {}

  virtual const char *what() const noexcept override { return "Insufficient funds exception! Balance is insufficient to perform the operation"; };
};

#endif // __INSUFFICIENT_FUNDS_EXCEPTION_H__
