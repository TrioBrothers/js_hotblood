#pragma once
#include <iostream>
#include "BankingCommonDecl.h"

using std::cout;
using std::endl;

class Account {
private:
    const int AccountID;
    char AccountName[MAX_LEN];
    int AccountBalance;

public:
    Account(const int ID, char* name, int balance);
    Account(const Account& copy);
    int getID() const;
    char getName() const;
    int getBalance() const;
    void setBalance(int balance);
    virtual void deposit(int money);
    void withdraw(int money);
    void showAccount() const;
    ~Account();
};