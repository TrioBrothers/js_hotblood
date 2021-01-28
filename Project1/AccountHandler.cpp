#pragma once
#include<iostream>
#include<string>
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountHandler.h"
#include "BankingCommonDecl.h"

using std::cout;
using std::cin;
using std::endl;

void AccountHandler::CreateAccount() {
    int sel;
    cout << "[계좌 종류 선택]" << endl;
    cout << "1. 보통 예금 계좌" << endl;
    cout << "2. 신용 신뢰 계좌" << endl;
    cin >> sel;
    if (sel == 1) {
        MakeNormalAccount();
    }
    else if (sel == 2) {
        MakeCreditAccount();
    }
    else {
        cout << "번호를 잘못 선택하였습니다." << endl;
    }
}
void AccountHandler::MakeNormalAccount() {
    cout << "[보통 예금 계좌 개설]" << endl;
    cout << "계좌 ID: "; cin >> tmpID;
    cout << "이름: "; cin >> tmpName;
    cout << "입금액: "; cin >> tmpMoney;
    cout << "이자율 : "; cin >> interRate;
    cout << endl;
    acc[index] = new NormalAccount(tmpID, tmpName, tmpMoney, interRate);
    index++;
}
void AccountHandler::MakeCreditAccount() {
    cout << "[신용 신뢰 계좌 개설]" << endl;
    cout << "계좌 ID: "; cin >> tmpID;
    cout << "이름: "; cin >> tmpName;
    cout << "입금액: "; cin >> tmpMoney;
    cout << "이자율 : "; cin >> interRate;
    cout << "신용등급(1toA, 2toB, 3toC) : "; cin >> creditLevel;
    cout << endl;
    int lev = 0;
    switch (creditLevel) {
    case 1:
        lev = Lev_A; //7
        break;
    case 2:
        lev = Lev_B; //4
        break;
    case 3:
        lev = Lev_C; //2
        break;
    }
    acc[index] = new HighCreditAccount(tmpID, tmpName, tmpMoney, interRate, lev);
    index++;
}
void AccountHandler::Deposit() {
    cout << "[입금]" << endl;
    cout << "계좌 ID : ";
    cin >> tmpID;
    cout << "입금액 : ";
    cin >> tmpMoney;
    for (int i = 0; i < index; i++) {
        if (acc[i]->GetID() == tmpID) {
            acc[i]->Deposit(tmpMoney);
            return;
        }
    }
    PrintNoneAccount();;
}
void AccountHandler::Withdraw() {
    cout << "[출금]" << endl;
    cout << "계좌 ID : ";
    cin >> tmpID;
    cout << "출금액 : ";
    cin >> tmpMoney;
    for (int i = 0; i < index; i++) {
        if (acc[i]->GetID() == tmpID) {
            int tmpBalance = acc[i]->GetBalance();
            if (tmpBalance < tmpMoney) {
                PrintNotEnoughBalance();
                return;
            }
            acc[i]->Withdraw(tmpMoney);
            return;
        }
    }
    PrintNoneAccount();
}

void AccountHandler::PrintNoneAccount() {
    cout << "계좌 정보가 존재하지 않습니다." << endl;
}
void AccountHandler::PrintNotEnoughBalance() {
    cout << "계좌 잔액이 부족합니다." << endl;
}

void AccountHandler::Menu() {

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
            CreateAccount();
            break;
        case 2:
            Deposit();
            break;
        case 3:
            Withdraw();
            break;
        case 4:
            for (int i = 0; i < index; i++) {
                acc[i]->ShowAccount();
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