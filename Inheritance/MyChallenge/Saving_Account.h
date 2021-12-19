#pragma once
#include "Account.h"
#include <string>
#include <vector>

using namespace std;

class Saving_Account : public Account
{
    friend std::ostream &operator<<(std::ostream &os, vector<Saving_Account> &list);
public:
    string name;
    double balance;
    double interest_rate;

    Saving_Account(string name, double balance, double interest_rate);
    bool deposit(double amount);
    
    
};
