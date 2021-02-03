#include "AccountArray.h"
#include "Account.h"
#include "BankingCommonDecl.h"

AccountArray::AccountArray(int len) : arrlen(len) {
	arr = new Acc_ptr[len];
}
Acc_ptr& AccountArray::operator[](int index) {
	if (index < 0 || index >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[index];
}
Acc_ptr AccountArray::operator[](int index) const {
	if (index < 0 || index >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[index];
}
AccountArray::~AccountArray() {
	delete[] arr;
}