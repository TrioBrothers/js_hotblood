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
    cout << "[���� ���� ����]" << endl;
    cout << "1. ���� ���� ����" << endl;
    cout << "2. �ſ� �ŷ� ����" << endl;
    cin >> sel;
    if (sel == 1) {
        MakeNormalAccount();
    }
    else if (sel == 2) {
        MakeCreditAccount();
    }
    else {
        cout << "��ȣ�� �߸� �����Ͽ����ϴ�." << endl;
    }
}
void AccountHandler::MakeNormalAccount() {
    cout << "[���� ���� ���� ����]" << endl;
    cout << "���� ID: "; cin >> tmpID;
    cout << "�̸�: "; cin >> tmpName;
    cout << "�Աݾ�: "; cin >> tmpMoney;
    cout << "������ : "; cin >> interRate;
    cout << endl;
    acc[index] = new NormalAccount(tmpID, tmpName, tmpMoney, interRate);
    index++;
}
void AccountHandler::MakeCreditAccount() {
    cout << "[�ſ� �ŷ� ���� ����]" << endl;
    cout << "���� ID: "; cin >> tmpID;
    cout << "�̸�: "; cin >> tmpName;
    cout << "�Աݾ�: "; cin >> tmpMoney;
    cout << "������ : "; cin >> interRate;
    cout << "�ſ���(1toA, 2toB, 3toC) : "; cin >> creditLevel;
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
    cout << "[�Ա�]" << endl;
    cout << "���� ID : ";
    cin >> tmpID;
    cout << "�Աݾ� : ";
    cin >> tmpMoney;
    int checkDeposit = Deposit(tmpID, tmpMoney);
    if (checkDeposit == 1) {
        cout << "�Ա��� �Ϸ��Ͽ����ϴ�." << endl;
    }
    else {
        cout << "���� ������ �������� �ʽ��ϴ�." << endl;
    }
}
int AccountHandler::Deposit(int tmpID, int tmpMoney) {
    if (CheckAccountID(tmpID) == 1) {
        acc[accNum]->Deposit(tmpMoney);
        return 1;
    }
}
void AccountHandler::WithdrawMenu() {
    cout << "[���]" << endl;
    cout << "���� ID : ";
    cin >> tmpID;
    cout << "��ݾ� : ";
    cin >> tmpMoney;
    int checkWithdraw = Withdraw(tmpID, tmpMoney);
    if (checkWithdraw == -1) {
        cout << "���� �ܾ��� �����մϴ�." << endl;
    }
    else if(checkWithdraw == 1){
        cout << "����� �Ϸ��Ͽ����ϴ�." << endl;
    }
    else {
        cout << "���� ������ �������� �ʽ��ϴ�." << endl;
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