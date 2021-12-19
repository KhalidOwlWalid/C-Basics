#pragma once

#include <iostream>
#include <string>

class Account
{
    friend std::ostream &operator<<(std::ostream &os, Account &account);
public:
    std::string name;
    double balance;
    Account();
    Account(std::string);
    Account(std::string name, double balance);
    bool deposit(double amount);
    bool withdraw(double amount);
    ~Account();
};