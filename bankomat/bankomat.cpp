#include "bankomat.h"
#include <iostream>
using namespace std;

Bankomat::Bankomat(int id, int minWithdrawal, int maxWithdrawal) : id(id), minWithdrawal(minWithdrawal), maxWithdrawal(maxWithdrawal) {
    currentBalance = 0;
    for (int i = 0; i < 10; ++i) {
        denominations[i] = 0;
    }
}

void Bankomat::loadMoney(int* money) {
    for (int i = 0; i < 10; ++i) {
        denominations[i] += money[i];
        currentBalance += money[i] * (i + 1) * 100; 
    }
}

bool Bankomat::withdrawMoney(int amount) {
    if (amount < minWithdrawal || amount > maxWithdrawal || amount > currentBalance) {
        return false; 
    }

    int remainingAmount = amount;
    for (int i = 9; i >= 0; --i) {
        int notes = std::min(remainingAmount / ((i + 1) * 100), denominations[i]);
        remainingAmount -= notes * (i + 1) * 100;
        denominations[i] -= notes;
    }

    currentBalance -= amount; 
    return true;
}

string Bankomat::toString() {
    return "Current balance: " + to_string(currentBalance);
}
