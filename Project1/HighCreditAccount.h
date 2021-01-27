#pragma once
#include <iostream>
#include "Account.h"
#include "NormalAccount.h"
#define MAX_LEN 30

using std::cout;
using std::endl;

class HighCreditAccount : public NormalAccount {
private:
	int creditRating;
public:
	HighCreditAccount(const int ID, char* name, int balance, int intRate, int credRating)
		:NormalAccount(ID, name, balance, intRate), creditRating(credRating) {}
	virtual void deposit(int balance) {
		NormalAccount::deposit(balance);
		Account::deposit(balance * (creditRating / 100.0));
	}
};
