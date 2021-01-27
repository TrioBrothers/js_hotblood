#pragma once
#include <iostream>
#include "Account.h"
#include "BankingCommonDecl.h"

using std::cout;
using std::endl;


    Account::Account(const int ID, char* name, int balance)
        :AccountID(ID), AccountBalance(balance) {
        int nameLength = strlen(name) + 1;
        strcpy_s(AccountName, nameLength, name);
    }
    Account::Account(const Account& copy)
        :AccountID(copy.AccountID), AccountBalance(copy.AccountBalance) {
        int nameLength = strlen(copy.AccountName) + 1;
        strcpy_s(AccountName, nameLength, copy.AccountName);
    }
    int Account::getID() const {
        return AccountID;
    }
    char Account::getName() const {
        return *AccountName;
    }
    int Account::getBalance() const {
        return AccountBalance;
    }
    void Account::setBalance(int balance) {
        AccountBalance = balance;
    }
    void Account::deposit(int money) {
        AccountBalance += money;
    }
    void Account::withdraw(int money) {
        AccountBalance -= money;
    }
    void Account::showAccount() const {
        cout << "°èÁÂ ID : ";
        cout << AccountID << endl;
        cout << "ÀÌ¸§ : ";
        cout << AccountName << endl;
        cout << "ÀÜ¾× : ";
        cout << AccountBalance << endl;
    }
    Account::~Account() {
    }