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
    int CheckAccountID(int tmpID);
    int CheckAccountBalance(int accNum, int tmpMoney);
    void DepositMenu();
    int Deposit(int tmpID, int tmpMoney);
    void WithdrawMenu();
    int Withdraw(int tmpID, int tmpMoney);
    void ShowAccount();
    void DeleteAcc();
private:
    Account* acc[accAmount];
    int index;
    int tmpID;
    char tmpName[accAmount];
    int tmpMoney;
    int interRate;
    int creditLevel;
    int accNum;
};