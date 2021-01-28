#pragma once
#include "Account.h"
#include "BankingCommonDecl.h"

class AccountHandler {
public:
    AccountHandler()
        :index(0) {}
    void CreateAccount();
    void MakeNormalAccount();
    void MakeCreditAccount();
    void Deposit();
    void Withdraw();
    void PrintNoneAccount();
    void PrintNotEnoughBalance();
    void Menu();
private:
    Account* acc[accAmount];
    int index;
    int tmpID;
    char tmpName[accAmount];
    int tmpMoney;
    int interRate;
    int creditLevel;
};