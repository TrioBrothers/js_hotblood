#pragma once
#include <iostream>
#include "BankingCommonDecl.h"

using std::cout;
using std::endl;

class Account {
public:
    Account(const int ID, char* name, int balance);
    Account(const Account& copy);
    Account& operator=(const Account& ref);
    int GetID() const;
    char GetName() const;
    int GetBalance() const;
    void SetBalance(int balance);
    virtual void Deposit(int money);
    void Withdraw(int money);
    void ShowAccount() const;
    ~Account();
private:
    int accountID;
    char accountName[MAX_LEN];
    int accountBalance;
};