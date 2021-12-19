#include "Saving_Account.h"
#include <iostream>
#include <string>
#include <vector>

Saving_Account::Saving_Account(std::string name, double balance, double interest_rate)
    : Account {name, balance}, interest_rate{interest_rate}
    {

    }

bool Saving_Account::deposit(double amount)
{
    amount += amount * (interest_rate/100);
    return Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, Saving_Account &saving_account)
{
    os << "Name: " << saving_account.name << endl;
    os << "Balance: " << saving_account.balance << endl;
    os << "Interest rate: " << saving_account.interest_rate << endl;
    os << "========================================================================" << endl;
    return os;
}

