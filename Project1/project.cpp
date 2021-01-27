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
    cout << "[계좌 종류 선택]" << endl;
    cout << "1. 보통 예금 계좌" << endl;
    cout << "2. 신용 신뢰 계좌" << endl;
    cin >> sel;
    if (sel == 1) {
        makeNormalAccount();
    }
    else if (sel == 2) {
        makeCreditAccount();
    }
    else {
        cout << "번호를 잘못 선택하였습니다." << endl;
    }
}
void AccountHandler::makeNormalAccount() {
    cout << "[보통 예금 계좌 개설]" << endl;
    cout << "계좌 ID: "; cin >> tmpID;
    cout << "이름: "; cin >> tmpName;
    cout << "입금액: "; cin >> tmpMoney;
    cout << "이자율 : "; cin >> interRate;
    cout << endl;
    acc[index] = new NormalAccount(tmpID, tmpName, tmpMoney, interRate);
    index++;
}
void AccountHandler::makeCreditAccount() {
    cout << "[신용 신뢰 계좌 개설]" << endl;
    cout << "계좌 ID: "; cin >> tmpID;
    cout << "이름: "; cin >> tmpName;
    cout << "입금액: "; cin >> tmpMoney;
    cout << "이자율 : "; cin >> interRate;
    cout << "신용등급(1toA, 2toB, 3toC) : "; cin >> creditLevel;
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
    cout << "[입금]" << endl;
    cout << "계좌 ID : ";
    cin >> tmpID;
    cout << "입금액 : ";
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
    cout << "[출금]" << endl;
    cout << "계좌 ID : ";
    cin >> tmpID;
    cout << "출금액 : ";
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
    cout << "계좌 정보가 존재하지 않습니다." << endl;
}
void AccountHandler::printNotEnoughBalance() {
    cout << "계좌 잔액이 부족합니다." << endl;
}

void AccountHandler::menu() {

    int num;
    bool booleanMenu = true;
    while (booleanMenu) {
        cout << "-----ㅡMenu-----" << endl;
        cout << "1. 계좌 개설" << endl;
        cout << "2. 입 금" << endl;
        cout << "3. 출 금" << endl;
        cout << "4. 계좌 정보 전체 출력" << endl;
        cout << "5. 프로그램 종료" << endl;
        cout << "선택 : ";
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