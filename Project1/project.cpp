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
        cout << "[���� ����]" << endl;
        cout << "���� ID : ";
        cin >> tmpID;
        cout << "�̸� : ";
        cin >> tmpName;
        cout << "�Աݾ� : ";
        cin >> tmpMoney;
        acc[index] = new Account(tmpID, tmpName, tmpMoney);
        index++;
    }
    void deposit() {
        cout << "[�Ա�]" << endl;
        cout << "���� ID : ";
        cin >> tmpID;
        cout << "�Աݾ� : ";
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
                return;
            }
        }
    }
    void printNoneAccount() {
        cout << "���� ������ �������� �ʽ��ϴ�." << endl;
    }
    void printNotEnoughBalance() {
        cout << "���� �ܾ��� �����մϴ�." << endl;
    }
};

int main(void) {
    AccountHandler handler;
    return 0;
}