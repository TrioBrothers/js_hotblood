#pragma once
#include<iostream>
#include<string>
#include "AccountHandler.h"
#include "BankingCommonDecl.h"

using std::cout;
using std::cin;
using std::endl;

int main(void) {
    AccountHandler handler;
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
            handler.CreateAccount();
            break;
        case 2:
            handler.DepositMenu();
            break;
        case 3:
            handler.WithdrawMenu();
            break;
        case 4:
            handler.ShowAccount();
            break;
        case 5:
            handler.DeleteAcc();
            booleanMenu = false;
        }
    }
    return 0;
}