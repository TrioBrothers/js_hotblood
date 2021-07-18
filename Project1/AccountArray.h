#pragma once
#include <iostream>
#include<cstdlib>
#include "BankingCommonDecl.h"
#include "Account.h"

typedef Account* Acc_ptr;

using std::cout;
using std::cin;
using std::endl;

class AccountArray {
public:
	AccountArray(int len=100);
	Acc_ptr& operator[](int index);
	Acc_ptr operator[](int index) const;
	~AccountArray();

private:
	Acc_ptr* arr;
	int arrlen;

	//���� ������, ���� ������ private���� �����Ͽ� ���� �� ���� ����
	AccountArray(const AccountArray& arr) {} 
	AccountArray& operator=(const AccountArray& arr) {}
};