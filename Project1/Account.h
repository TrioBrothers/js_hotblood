#include <iostream>

using std::cout;
using std::endl;

class Account {
private:
    const int AccountID;
    char* AccountName;
    int AccountBalance;

public:
    Account(const int ID, char* name, int balance)
        :AccountID(ID), AccountBalance(balance) {
        int nameLength = strlen(name) + 1;
        AccountName = new char[nameLength];
        strcpy_s(AccountName, nameLength, name);
    }
    Account(const Account& copy)
        :AccountID(copy.AccountID), AccountBalance(copy.AccountBalance) {
        int nameLength = strlen(copy.AccountName) + 1;
        AccountName = new char[nameLength];
        strcpy_s(AccountName, nameLength, copy.AccountName);
    }
    int getID() const {
        return AccountID;
    }
    char getName() {
        return *AccountName;
    }
    int getBalance() {
        return AccountBalance;
    }
    void setBalance(int balance) {
        AccountBalance = balance;
    }
    void showAccount() const {
        cout << "계좌 ID : ";
        cout << AccountID << endl;
        cout << "이름 : ";
        cout << AccountName << endl;
        cout << "잔액 : ";
        cout << AccountBalance << endl;
    }
    ~Account() {
        delete AccountName;
    }
};