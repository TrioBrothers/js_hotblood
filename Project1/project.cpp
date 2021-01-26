#include<iostream>
#include<string>
#include "Account.h"

#define accAmount 100

using std::cout;
using std::cin;
using std::endl;

class AccountHandler {
private:
    Account* acc[accAmount];
    int tmpID;
    char tmpName[accAmount];
    int tmpMoney;
    int index = 0;
public:
    AccountHandler() {
        menu();
    }
    void createAccount() {
        cout << "[계좌 개설]" << endl;
        cout << "계좌 ID : ";
        cin >> tmpID;
        cout << "이름 : ";
        cin >> tmpName;
        cout << "입금액 : ";
        cin >> tmpMoney;
        acc[index] = new Account(tmpID, tmpName, tmpMoney);
        index++;
    }
    void deposit() {
        cout << "[입금]" << endl;
        cout << "계좌 ID : ";
        cin >> tmpID;
        cout << "입금액 : ";
        cin >> tmpMoney;
        for (int i = 0; i < index; i++) {
            if (acc[i]->getID() == tmpID) {
                int tmpBalance = acc[i]->getBalance();
                tmpBalance += tmpMoney;
                acc[i]->setBalance(tmpBalance);
                return;
            }
        }
        printNoneAccount();
    }
    void withdraw() {
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
                tmpBalance -= tmpMoney;
                acc[i]->setBalance(tmpBalance);
                return;
            }
        }
        printNoneAccount();
    }
    void menu() {

        int num;
        while (true) {
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
                return;
            }
        }
    }
    void printNoneAccount() {
        cout << "계좌 정보가 존재하지 않습니다." << endl;
    }
    void printNotEnoughBalance() {
        cout << "계좌 잔액이 부족합니다." << endl;
    }
};

int main(void) {
    AccountHandler handler;
    return 0;
}