#ifndef BANKOMAT_H
#define BANKOMAT_H
#include <string>
using namespace std;

class Bankomat {
private:
    int id;
    int currentBalance;
    int minWithdrawal;
    int maxWithdrawal;
    int denominations[10]; 

public:
    Bankomat(int id, int minWithdrawal, int maxWithdrawal);
    void loadMoney(int* money);
    bool withdrawMoney(int amount);
    string toString();
};

#endif