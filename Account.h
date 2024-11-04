#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
//#include "Bank.h"

class Account {
private:
    int id;
    int customerId;
    int balance;
    int pin;

public:
    Account(int id, int customerId, int balance, int pin);

    int getId() const;
    int getCustomerId() const;
    int getBalance() const;

    void depositMoney(int amount);
    bool withdrawMoney(int amount);
    bool verifyPin(int enteredPin) const;
    void displayAccountInfo(int enteredPin) const;
};

#endif // ACCOUNT_H