#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(int id, int customerId, int balance, int pin)
    : id(id), customerId(customerId), balance(balance), pin(pin) {}

int Account::getId() const { return id; }
int Account::getCustomerId() const { return customerId; }
int Account::getBalance() const { return balance; }

void Account::depositMoney(int amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Đã nạp " << amount << " vào tài khoản." << endl;
    } else {
        cout << "Số tiền nạp không hợp lệ." << endl;
    }
}

bool Account::withdrawMoney(int amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Đã rút " << amount << " từ tài khoản." << endl;
        return true;
    } else {
        cout << "Số tiền rút không hợp lệ hoặc không đủ số dư." << endl;
        return false;
    }
}

bool Account::verifyPin(int enteredPin) const {
    return enteredPin == pin;
}

void Account::displayAccountInfo(int enteredPin) const {
    if (verifyPin(enteredPin)) {
        cout << "Account ID: " << id << endl;
        cout << "Customer ID: " << customerId << endl;
        cout << "Balance: $" << balance << endl;
    } else {
        cout << "Incorrect PIN. Access denied." << endl;
    }
}