#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{
    // test your code here
    // Trust_Account at the moment does not throw an InsufficientFundsException because
    // it should have its own exception, as the withdraw can fail even if the funds are sufficient
    // but the withdraw >= 20% funds
    try
    {
        Trust_Account a = Trust_Account("Johnny", -100);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    Savings_Account sa = Trust_Account("Rhodey", 1000);

    try
    {
        sa.withdraw(2000);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout
        << "Program completed successfully" << std::endl;
    return 0;
}
