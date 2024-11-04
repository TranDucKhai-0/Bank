#include "Loan.h"
#include <iostream>
using namespace std;

Loan::Loan() : type(""), amount(0) {}

Loan::Loan(int id, const string &type, int accountId, int customerId, int amount)
    : id(id), type(type), accountId(accountId), customerId(customerId), amount(amount) {}

int Loan::getId() const { return id; }
string Loan::getType() const { return type; }
int Loan::getAccountId() const { return accountId; }
int Loan::getCustomerId() const { return customerId; }
int Loan::getMoney() const { return amount; }

void Loan::setId(int id) { this->id = id; }
void Loan::setType(const string &type) { this->type = type; }
void Loan::setAccountId(int accountId) { this->accountId = accountId; }
void Loan::setCustomerId(int customerId) { this->customerId = customerId; }
void Loan::setMoney(int amount) { this->amount = amount; }

void Loan::displayLoanInfo() const {
    cout << "Loan ID: " << id << endl;
    cout << "Type: " << type << endl;
    cout << "Account ID: " << accountId << endl;
    cout << "Customer ID: " << customerId << endl;
    cout << "Amount: " << amount << endl;
}