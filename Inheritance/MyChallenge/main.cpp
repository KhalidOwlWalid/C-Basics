#include <iostream>
#include <list>
#include <vector>
#include "Account.h"
#include "Saving_Account.h"

using namespace std;

void print(vector<Account> &accounts)
{
    for (auto &acc: accounts)
    {
        cout << acc << endl;
    }
}

void print

int main()
{
    
    // Create account
    vector<Account> accounts;

    accounts.push_back(Account {});
    accounts.push_back(Account {"Khalid"});
    accounts.push_back(Account {"Alia", 1000.0});

    //cout << accounts << endl;
    print(accounts);

    vector<Saving_Account> saving_accounts;

    saving_accounts.push_back(Saving_Account{"Khalid", 1000.0, 20});
    saving_accounts.push_back(Saving_Account{"Alia", 2000.0, 30});

    print(saving_accounts);

    

    return 0;
}