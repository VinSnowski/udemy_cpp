#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__

class IllegalBalanceException : public std::exception
{
public:
    IllegalBalanceException() {}
    ~IllegalBalanceException() {}

    virtual const char *what() const noexcept override { return "Illegal balance exception! Balance should be a number >=0"; };
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
