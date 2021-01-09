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
	cout << "[���� ����]" << endl;
	cout << "���� ID : ";
	cin >> tmpID;
	accountID[index] = tmpID;
	cout << "�̸� : ";
	cin >> tmpName;
	accountName[index] = tmpName;
	cout << "�Աݾ� : ";
	cin >> tmpPrice;
	accountPrice[index] = tmpPrice;
	index++;
}

void deposit(void) {
	cout << "[�Ա�]" << endl;
	cout << "���� ID : ";
	cin >> tmpID;
	cout << "�Աݾ� : ";
	cin >> tmpPrice;
	for (int i = 0; i < index; i++) {
		if (accountID[i] == tmpID) {
			accountPrice[i] += tmpPrice;
			cout << "�Ա� �Ϸ�";
			break;
		}
		else if (i+1 == index) {
			cout << "���� ������ �������� �ʽ��ϴ�." << endl;
			break;
		}
	}
}

void withdraw(void) {
	cout << "[���]" << endl;
	cout << "���� ID : ";
	cin >> tmpID;
	cout << "��ݾ� : ";
	cin >> tmpPrice;
	for (int i = 0; i < index; i++) {
		if (accountID[i] == tmpID) {
			accountPrice[i] -= tmpPrice;
			cout << "��� �Ϸ�";
			break;
		}
		else if (i+1 == index) {
			cout << "���� ������ �������� �ʽ��ϴ�." << endl;
			break;
		}
	}
}

void showAccount(void) {
	for (int i = 0; i < index; i++) {
		cout << "===============" << endl;
		cout << "���� ID : ";
		cout << accountID[i] << endl;
		cout << "�̸� : ";
		cout << accountName[i] << endl;
		cout << "�ܾ� : ";
		cout << accountPrice[i] << endl;
		cout << "===============" << endl;
	}
}

void exit(void) {
	bankProgram = false;
}

void menu(void) {
	while (bankProgram) {
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
