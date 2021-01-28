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
void AccountHandler::Deposit() {
    cout << "[�Ա�]" << endl;
    cout << "���� ID : ";
    cin >> tmpID;
    cout << "�Աݾ� : ";
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
    cout << "[���]" << endl;
    cout << "���� ID : ";
    cin >> tmpID;
    cout << "��ݾ� : ";
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
    cout << "���� ������ �������� �ʽ��ϴ�." << endl;
}
void AccountHandler::PrintNotEnoughBalance() {
    cout << "���� �ܾ��� �����մϴ�." << endl;
}

void AccountHandler::Menu() {

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