#include <iostream>
#include "bankomat.h"
using namespace std;

int main() {
    Bankomat atm(12345, 100, 1000);

    int initialMoney[10] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    atm.loadMoney(initialMoney);

    cout << "Bankomat status: " << atm.toString() << endl;

    int amountToWithdraw = 2500;
    if (atm.withdrawMoney(amountToWithdraw)) {
        cout << "Withdrawal successful!" << endl;
        cout << "Bankomat status after withdrawal: " << atm.toString() << endl;
    }
    else {
       cout << "Withdrawal failed! Insufficient funds or invalid amount." << endl;
    }

    return 0;
}
