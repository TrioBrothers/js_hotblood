#pragma once
#include<iostream>
#include<string>
#include "AccountHandler.h"
#include "BankingCommonDecl.h"

int main(void) {
    AccountHandler handler;
    handler.Menu();
    return 0;
}