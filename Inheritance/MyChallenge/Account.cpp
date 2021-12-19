#include "Account.h"

#include <iostream>
using namespace std;

Account::Account()
    : name{"Unnamed Account"}, balance{0.0}
    {
        //cout << "Constructor for unnamed account" << endl;
    }

Account::Account(std::string name)
    : name{name}, balance{0.0}
    {
        //cout << "Constructor for account with name " << name << " and balance " << balance << endl; 
    }

Account::Account(std::string name, double balance)
    : name{name}, balance{balance}
    {
        //cout << "Constructor for account with name " << name << " and balance " << balance << endl;
    }

Account::~Account()
{
    //cout << "Destructor for " << name << endl;
}

bool Account::deposit(double amount)
{
    if (amount > 0)
    {
        balance += amount;
        cout << balance << endl;
        return true;
    }
    else
    {
        cout << "Deposit failed" << endl;
        return false;
    }
}

bool Account::withdraw(double amount)
{
    if (amount <= balance)
    {
        balance -= amount;
        return true;
    }
    else{
        return false;
    }
}

std::ostream &operator<<(std::ostream &os, Account &account)
{
    os << "Name: " << account.name << endl;
    os << "Balance: " << account.balance << endl;
    os << "========================================================================" << endl;
    return os;
}
