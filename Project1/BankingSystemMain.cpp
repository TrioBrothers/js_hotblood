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