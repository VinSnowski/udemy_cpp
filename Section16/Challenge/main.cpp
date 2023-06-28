// Section 16
// Challenge
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;

    // Checking Accounts
    vector<Account *> accounts;

    Account *ptr1;
    Account *ptr2;
    Account *ptr3;

    ptr1 = new Checking_Account();
    ptr2 = new Checking_Account{"Ronald"};
    ptr3 = new Checking_Account{"McDonald", 5000};

    accounts.push_back(ptr1);
    accounts.push_back(ptr2);
    accounts.push_back(ptr3);

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    // Savings Accounts
    vector<Account *> accounts2;

    Account *ptr4;
    Account *ptr5;
    Account *ptr6;

    ptr4 = new Savings_Account();
    ptr5 = new Savings_Account{"Burer"};
    ptr6 = new Savings_Account{"King", 50000};

    accounts2.push_back(ptr4);
    accounts2.push_back(ptr5);
    accounts2.push_back(ptr6);

    display(accounts);
    deposit(accounts, 10000);
    withdraw(accounts, 20000);

    // Trust

    Account *ptr7;
    Account *ptr8;
    Account *ptr9;

    ptr7 = new Trust_Account{"Athos", 10000, 5.0};
    ptr8 = new Trust_Account{"Porthos", 20000, 4.0};
    ptr9 = new Trust_Account{"Aramis", 30000};

    vector<Account *> accounts3;
    accounts3.push_back(ptr7);
    accounts3.push_back(ptr8);
    accounts3.push_back(ptr9);

    display(accounts3);
    deposit(accounts3, 1000);
    withdraw(accounts3, 3000);

    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i = 1; i <= 5; i++)
        withdraw(accounts3, 1000);

    delete ptr1;
    delete ptr2;
    delete ptr3;
    delete ptr4;
    delete ptr5;
    delete ptr6;
    delete ptr7;
    delete ptr8;
    delete ptr9;

    return 0;
}
