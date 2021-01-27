#pragma once
#include "Account.h"
#define accAmount 100

class AccountHandler {
private:
    Account* acc[accAmount];
    int index;
public:
    AccountHandler()
        :index(0) {}
    void createAccount();
    void makeNormalAccount();
    void makeCreditAccount();
    void deposit();
    void withdraw();
    void printNoneAccount();
    void printNotEnoughBalance();
    void menu();
};