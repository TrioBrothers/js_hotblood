#pragma once
#include "Account.h"
#include "BankingCommonDecl.h"

class AccountHandler {
private:
    Account* acc[accAmount];
    int index;
    int tmpID;
    char tmpName[accAmount];
    int tmpMoney;
    int interRate;
    int creditLevel;
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