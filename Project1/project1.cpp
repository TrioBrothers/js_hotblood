#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std:: string;
using std::istream;
using std::endl;

int num;
int index = 0;
int tmpID;
string tmpName;
int tmpPrice;
int accountID[100];
string accountName[100];
int accountPrice[100];
bool bankProgram = true;

void createAccount(void) {
	cout << "[계좌 개설]" << endl;
	cout << "계좌 ID : ";
	cin >> tmpID;
	accountID[index] = tmpID;
	cout << "이름 : ";
	cin >> tmpName;
	accountName[index] = tmpName;
	cout << "입금액 : ";
	cin >> tmpPrice;
	accountPrice[index] = tmpPrice;
	index++;
}

void deposit(void) {
	cout << "[입금]" << endl;
	cout << "계좌 ID : ";
	cin >> tmpID;
	cout << "입금액 : ";
	cin >> tmpPrice;
	for (int i = 0; i < index; i++) {
		if (accountID[i] == tmpID) {
			accountPrice[i] += tmpPrice;
			cout << "입금 완료";
			break;
		}
		else if (i+1 == index) {
			cout << "계좌 정보가 존재하지 않습니다." << endl;
			break;
		}
	}
}

void withdraw(void) {
	cout << "[출금]" << endl;
	cout << "계좌 ID : ";
	cin >> tmpID;
	cout << "출금액 : ";
	cin >> tmpPrice;
	for (int i = 0; i < index; i++) {
		if (accountID[i] == tmpID) {
			accountPrice[i] -= tmpPrice;
			cout << "출금 완료";
			break;
		}
		else if (i+1 == index) {
			cout << "계좌 정보가 존재하지 않습니다." << endl;
			break;
		}
	}
}

void showAccount(void) {
	for (int i = 0; i < index; i++) {
		cout << "===============" << endl;
		cout << "계좌 ID : ";
		cout << accountID[i] << endl;
		cout << "이름 : ";
		cout << accountName[i] << endl;
		cout << "잔액 : ";
		cout << accountPrice[i] << endl;
		cout << "===============" << endl;
	}
}

void exit(void) {
	bankProgram = false;
}

void menu(void) {
	while (bankProgram) {
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
			showAccount();
			break;
		case 5:
			exit();
			break;
		}

	}
}

int main(void) {

	menu();
	return 0;
}
