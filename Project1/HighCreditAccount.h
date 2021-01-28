#pragma once
#include <iostream>
#include "Account.h"
#include "NormalAccount.h"

using std::cout;
using std::endl;

class HighCreditAccount : public NormalAccount {
public:
	HighCreditAccount(const int ID, char* name, int balance, int intRate, int credRating)
		:NormalAccount(ID, name, balance, intRate), creditRating(credRating) {}
	virtual void Deposit(int balance) {
		NormalAccount::Deposit(balance);
		Account::Deposit(balance * (creditRating / 100.0));
	}
private:
	int creditRating;
};
