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
int AccountHandler::CheckAccountID(int tmpID) {
    accNum = 0;
    for (int i = 0; i < index; i++) {
        if (acc[i]->GetID() == tmpID) {
            accNum = i;
            return 1;
        }
    }
}
int AccountHandler::CheckAccountBalance(int accNum, int tmpMoney) {
    if (acc[accNum]->GetBalance() < tmpMoney) {
        return -1;
    }
}
void AccountHandler::DepositMenu() {
    cout << "[입금]" << endl;
    cout << "계좌 ID : ";
    cin >> tmpID;
    cout << "입금액 : ";
    cin >> tmpMoney;
    int checkDeposit = Deposit(tmpID, tmpMoney);
    if (checkDeposit == 1) {
        cout << "입금을 완료하였습니다." << endl;
    }
    else {
        cout << "계좌 정보가 존재하지 않습니다." << endl;
    }
}
int AccountHandler::Deposit(int tmpID, int tmpMoney) {
    if (CheckAccountID(tmpID) == 1) {
        acc[accNum]->Deposit(tmpMoney);
        return 1;
    }
}
void AccountHandler::WithdrawMenu() {
    cout << "[출금]" << endl;
    cout << "계좌 ID : ";
    cin >> tmpID;
    cout << "출금액 : ";
    cin >> tmpMoney;
    int checkWithdraw = Withdraw(tmpID, tmpMoney);
    if (checkWithdraw == -1) {
        cout << "계좌 잔액이 부족합니다." << endl;
    }
    else if(checkWithdraw == 1){
        cout << "출금을 완료하였습니다." << endl;
    }
    else {
        cout << "계좌 정보가 존재하지 않습니다." << endl;
    }
}
int AccountHandler::Withdraw(int tmpID, int tmpMoney) {
    if (CheckAccountID(tmpID) == 1) {
        if (CheckAccountBalance(accNum, tmpMoney) == -1) {
            return -1;
        }
        else {
            acc[accNum]->Withdraw(tmpMoney);
            return 1;
        }
    }
}
void AccountHandler::ShowAccount() {
    for (int i = 0; i < index; i++) {
        acc[i]->ShowAccount();
    }
}
void AccountHandler::DeleteAcc() {
    for (int i = 0; i < index; i++) {
        delete acc[i];
    }
}