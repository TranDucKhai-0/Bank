#include "Teller.h"
#include "Account.h"
#include "Bank.h"
#include "Loan.h"
#include "Customer.h"
#include <iostream>
#include <windows.h>

using namespace std;

Teller::Teller(int id, int pin,const std::string& name, Bank* bank)
    : id(id), pin(pin), name(name), bank(bank) {}

bool Teller::collectMoney(int customerId, int amount, int accountId) {
    Customer* customer = bank->findCustomerById(customerId);
    if (!customer) {
        cout << "Không tìm thấy khách hàng.\n";
        return false;
    }
    Account* account = customer->findAccountById(accountId);
    if (account) {
        account->depositMoney(amount);
        cout << "Nạp tiền thành công.\n";
        return true;
    }
    cout << "Không tìm thấy tài khoản.\n";
    return false;
}

bool Teller::openAccount(int customerId, int initialDeposit) {
    Customer* customer = bank->findCustomerById(customerId);
    if (customer) {
        Account* newAccount = new Account(customer->getAccounts().size() + 1, customerId, initialDeposit, customer->getPIN());
        customer->addAccount(newAccount);
        cout << "Mở tài khoản thành công.\n";
        return true;
    }
    cout << "Không tìm thấy khách hàng.\n";
    return false;
}

bool Teller::closeAccount(int customerId, int accountId) {
    Customer* customer = bank->findCustomerById(customerId);
    if (customer && customer->removeAccount(accountId)) {
        cout << "Đóng tài khoản thành công.\n";
        return true;
    }
    cout << "Không thể đóng tài khoản.\n";
    return false;
}

bool Teller::loanRequest(int customerId, int loanAmount, const std::string& loanType) {
    Customer* customer = bank->findCustomerById(customerId);
    if (customer && bank->isLoanEligBankible(loanAmount)) {
        Loan loan(customer->getLoans().size() + 1, loanType, 1, customerId, loanAmount);
        customer->addLoan(loan);
        cout << "Yêu cầu vay thành công.\n";
        return true;
    }
    cout << "Yêu cầu vay không thành công.\n";
    return false;
}

void Teller::provideInfo(int customerId) {
    Customer* customer = bank->findCustomerById(customerId);
    if (customer) {
        customer->viewAccountDetails();
        customer->viewLoanDetails();
    } else {
        cout << "Không tìm thấy khách hàng.\n";
    }
}

void Teller::displayMenu() {
    cout << "1. Nạp tiền\n2. Mở tài khoản\n3. Đóng tài khoản\n4. Xử lý vay\n5. Thông tin khách hàng\n0. Thoát\n";
}

void Teller::interact() {
    int option;
    do {
        displayMenu();
        cout << "Chọn: ";
        cin >> option;
        int customerId, accountId, amount;
        string loanType;
        switch (option) {
            case 1:
                cout << "Customer ID: "; cin >> customerId;
                cout << "Account ID: "; cin >> accountId;
                cout << "Amount: "; cin >> amount;
                collectMoney(customerId, amount, accountId);
                break;
            case 2:
                cout << "Customer ID: "; cin >> customerId;
                cout << "Initial Deposit: "; cin >> amount;
                openAccount(customerId, amount);
                break;
            case 3:
                cout << "Customer ID: "; cin >> customerId;
                cout << "Account ID: "; cin >> accountId;
                closeAccount(customerId, accountId);
                break;
            case 4:
                cout << "Customer ID: "; cin >> customerId;
                cout << "Loan Amount: "; cin >> amount;
                cout << "Loan Type: "; cin >> loanType;
                loanRequest(customerId, amount, loanType);
                break;
            case 5:
                cout << "Customer ID: "; cin >> customerId;
                provideInfo(customerId);
                break;
        }
    } while (option != 0);
}

Bank* Teller::getBank() const {
    return bank;
}

// Lấy tên giao dịch viên
std::string Teller::getName() const{
    return name;
}

// Lấy mã PIN của giao dịch viên
int Teller::getPIN() const{
    return pin;
}
