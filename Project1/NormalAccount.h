#pragma once
#include <iostream>
#include "Account.h"
#define MAX_LEN 30

using std::cout;
using std::endl;

class NormalAccount : public Account {
private:
	int interestRate;
public:
	NormalAccount(const int ID, char* name, int balance, int intRate)
		:Account(ID, name, balance), interestRate(intRate) {}
	virtual void deposit(int balance) {
		Account::deposit(balance);
		Account::deposit(balance * (interestRate / 100.0));
	}
};