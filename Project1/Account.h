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
        cout << "°èÁÂ ID : ";
        cout << AccountID << endl;
        cout << "ÀÌ¸§ : ";
        cout << AccountName << endl;
        cout << "ÀÜ¾× : ";
        cout << AccountBalance << endl;
    }
    ~Account() {
        delete AccountName;
    }
};