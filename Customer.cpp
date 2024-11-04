#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(int id, int pin, const string& name, const string& address, const string& phoneNo)
    : id(id), pin(pin), name(name), address(address), phoneNo(phoneNo) {}

int Customer::getID() const { return id; }
int Customer::getPIN() const { return pin; }
string Customer::getName() const { return name; }
string Customer::getAddress() const { return address; }
string Customer::getPhoneNo() const { return phoneNo; }

void Customer::addAccount(Account* account) {
    accounts.push_back(account);
}

Account* Customer::findAccountById(int accountId) const {
    for (auto account : accounts) {
        if (account->getId() == accountId) {
            return account;
        }
    }
    return nullptr;
}

bool Customer::removeAccount(int accountId) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if ((*it)->getId() == accountId) {
            accounts.erase(it);
            return true;
        }
    }
    return false;
}

void Customer::depositMoney(int amount, int accountId) {
    Account* account = findAccountById(accountId);
    if (account) {
        account->depositMoney(amount);
        addTransaction("Nạp " + to_string(amount) + " vào tài khoản ID " + to_string(accountId));
    } else {
        cout << "Lỗi: Không tìm thấy tài khoản với ID " << accountId << endl;
    }
}

bool Customer::withdrawMoney(int amount, int accountId) {
    Account* account = findAccountById(accountId);
    if (account && account->withdrawMoney(amount)) {
        addTransaction("Rút " + to_string(amount) + " từ tài khoản ID " + to_string(accountId));
        return true;
    } else {
        cout << "Lỗi: Không đủ số dư hoặc không tìm thấy tài khoản với ID " << accountId << endl;
        return false;
    }
}

void Customer::addLoan(const Loan& loan) {
    loans.push_back(loan);
    addTransaction("Thêm khoản vay ID " + to_string(loan.getId()) + " với số tiền " + to_string(loan.getMoney()));
}

void Customer::addTransaction(const string& transaction) {
    transactionHistory.push_back(transaction);
}

void Customer::viewAccountDetails() const {
    cout << "Chi tiết tài khoản của khách hàng ID " << id << ":\n";
    for (const auto& account : accounts) {
        cout << "Tài khoản ID: " << account->getId() << ", Số dư: " << account->getBalance() << endl;
    }
}

void Customer::viewLoanDetails() const {
    cout << "Chi tiết khoản vay của khách hàng ID " << id << ":\n";
    for (const auto& loan : loans) {
        cout << "Khoản vay ID: " << loan.getId() << ", Loại: " << loan.getType() << ", Số tiền: " << loan.getMoney() << endl;
    }
}

const vector<string>& Customer::getTransactionHistory() const {
    return transactionHistory;
}

const vector<Account*>& Customer::getAccounts() const {
    return accounts;
}

const vector<Loan>& Customer::getLoans() const {
    return loans;
}

void Customer::applyForLoan(const string& type, int amount) {
    Loan loan(loans.size() + 1, type, accounts.size() + 1, id, amount);
    addLoan(loan);
    addTransaction("Yêu cầu vay " + type + " với số tiền " + to_string(amount));
    cout << "Yêu cầu vay " << type << " với số tiền " << amount << " đã được thêm vào danh sách khoản vay.\n";
}