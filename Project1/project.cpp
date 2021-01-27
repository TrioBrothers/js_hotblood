#pragma once
#include<iostream>
#include<string>
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

#define accAmount 100

using std::cout;
using std::cin;
using std::endl;

enum { Lev_A = 7, Lev_B = 4, Lev_C = 2 };

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

void AccountHandler::createAccount() {
    int sel;
    cout << "[���� ���� ����]" << endl;
    cout << "1. ���� ���� ����" << endl;
    cout << "2. �ſ� �ŷ� ����" << endl;
    cin >> sel;
    if (sel == 1) {
        makeNormalAccount();
    }
    else if (sel == 2) {
        makeCreditAccount();
    }
    else {
        cout << "��ȣ�� �߸� �����Ͽ����ϴ�." << endl;
    }
}
void AccountHandler::makeNormalAccount() {
    cout << "[���� ���� ���� ����]" << endl;
    cout << "���� ID: "; cin >> tmpID;
    cout << "�̸�: "; cin >> tmpName;
    cout << "�Աݾ�: "; cin >> tmpMoney;
    cout << "������ : "; cin >> interRate;
    cout << endl;
    acc[index] = new NormalAccount(tmpID, tmpName, tmpMoney, interRate);
    index++;
}
void AccountHandler::makeCreditAccount() {
    cout << "[�ſ� �ŷ� ���� ����]" << endl;
    cout << "���� ID: "; cin >> tmpID;
    cout << "�̸�: "; cin >> tmpName;
    cout << "�Աݾ�: "; cin >> tmpMoney;
    cout << "������ : "; cin >> interRate;
    cout << "�ſ���(1toA, 2toB, 3toC) : "; cin >> creditLevel;
    cout << endl;
    switch (creditLevel) {
    case 1:
        acc[index] = new HighCreditAccount(tmpID, tmpName, tmpMoney, interRate, Lev_A);
        index++;
        break;
    case 2:
        acc[index] = new HighCreditAccount(tmpID, tmpName, tmpMoney, interRate, Lev_B);
        index++;
        break;
    case 3:
        acc[index] = new HighCreditAccount(tmpID, tmpName, tmpMoney, interRate, Lev_C);
        index++;
        break;
    }
}
void AccountHandler::deposit() {
    cout << "[�Ա�]" << endl;
    cout << "���� ID : ";
    cin >> tmpID;
    cout << "�Աݾ� : ";
    cin >> tmpMoney;
    for (int i = 0; i < index; i++) {
        if (acc[i]->getID() == tmpID) {
            acc[i]->deposit(tmpMoney);
            return;
        }
    }
    printNoneAccount();;
}
void AccountHandler::withdraw() {
    cout << "[���]" << endl;
    cout << "���� ID : ";
    cin >> tmpID;
    cout << "��ݾ� : ";
    cin >> tmpMoney;
    for (int i = 0; i < index; i++) {
        if (acc[i]->getID() == tmpID) {
            int tmpBalance = acc[i]->getBalance();
            if (tmpBalance < tmpMoney) {
                printNotEnoughBalance();
                return;
            }
            acc[i]->withdraw(tmpMoney);
            return;
        }
    }
    printNoneAccount();
}

void AccountHandler::printNoneAccount() {
    cout << "���� ������ �������� �ʽ��ϴ�." << endl;
}
void AccountHandler::printNotEnoughBalance() {
    cout << "���� �ܾ��� �����մϴ�." << endl;
}

void AccountHandler::menu() {

    int num;
    bool booleanMenu = true;
    while (booleanMenu) {
        cout << "-----��Menu-----" << endl;
        cout << "1. ���� ����" << endl;
        cout << "2. �� ��" << endl;
        cout << "3. �� ��" << endl;
        cout << "4. ���� ���� ��ü ���" << endl;
        cout << "5. ���α׷� ����" << endl;
        cout << "���� : ";
        cin >> num;

        switch (num)
        {
        case 1:
            createAccount();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            for (int i = 0; i < index; i++) {
                acc[i]->showAccount();
            }
            break;
        case 5:
            for (int i = 0; i < index; i++) {
                delete acc[i];
            }
            booleanMenu = false;
            return;
        }
    }
}

int main(void) {
    AccountHandler handler;
    handler.menu();
    return 0;
}