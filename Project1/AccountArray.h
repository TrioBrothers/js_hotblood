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

	//복사 생성자, 대입 연산자 private으로 선언하여 복사 및 대입 차단
	AccountArray(const AccountArray& arr) {} 
	AccountArray& operator=(const AccountArray& arr) {}
};