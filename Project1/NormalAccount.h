#pragma once
#include <iostream>
#include "Account.h"

using std::cout;
using std::endl;

class NormalAccount : public Account {
private:
	int interestRate;
public:
	NormalAccount(const int ID, char* name, int balance, int intRate)
		:Account(ID, name, balance), interestRate(intRate) {}
	virtual void Deposit(int balance) {
		Account::Deposit(balance);
		Account::Deposit(balance * (interestRate / 100.0));
	}
};