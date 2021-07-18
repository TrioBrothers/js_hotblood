#pragma once
#include <iostream>
#include "Account.h"
#include "BankingCommonDecl.h"

using std::cout;
using std::endl;


    Account::Account(const int ID, char* name, int balance)
        :accountID(ID), accountBalance(balance) {
        int nameLength = strlen(name) + 1;
        strcpy_s(accountName, nameLength, name);
    }
    Account::Account(const Account& copy)
        :accountID(copy.accountID), accountBalance(copy.accountBalance) {
        int nameLength = strlen(copy.accountName) + 1;
        strcpy_s(accountName, nameLength, copy.accountName);
    }
    Account& Account::operator=(const Account& ref) {
        accountID = ref.accountID;
        delete[]accountName;
        int nameLength = strlen(ref.accountName) + 1;
        strcpy_s(accountName, nameLength, ref.accountName);
        accountBalance = ref.accountBalance;
        return *this;
    }
    int Account::GetID() const {
        return accountID;
    }
    char Account::GetName() const {
        return *accountName;
    }
    int Account::GetBalance() const {
        return accountBalance;
    }
    void Account::SetBalance(int balance) {
        accountBalance = balance;
    }
    void Account::Deposit(int money) {
        accountBalance += money;
    }
    void Account::Withdraw(int money) {
        accountBalance -= money;
    }
    void Account::ShowAccount() const {
        cout << "°èÁÂ ID : ";
        cout << accountID << endl;
        cout << "ÀÌ¸§ : ";
        cout << accountName << endl;
        cout << "ÀÜ¾× : ";
        cout << accountBalance << endl;
    }
    Account::~Account() {
    }