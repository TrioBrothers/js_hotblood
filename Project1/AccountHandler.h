#pragma once
#include "Account.h"
#define accAmount 100

class AccountHandler {
private:
    Account* acc[accAmount];
    int tmpID;
    char tmpName[accAmount];
    int tmpMoney;
    int index;
public:
    AccountHandler() {}
    void createAccount();
    void deposit();
    void withdraw();
    void printNoneAccount();
    void printNotEnoughBalance();
    void menu();
};
