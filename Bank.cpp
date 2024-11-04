#include "Bank.h"
#include <iostream>
#include <windows.h> // Dành cho hàm Sleep trên Windows
using namespace std;

Bank::Bank(int id, const std::string& name, const std::string& location)
    : bankId(id), name(name), location(location) {}

void Bank::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

void Bank::addTeller(const Teller& teller) {
    tellers.push_back(teller);
}

void Bank::displayBankInfo() {
    Sleep(500);               
    cout << "\n========= Thông tin Ngân Hàng =========" << endl;
    cout << "Tên Ngân Hàng: " << name << endl;
    cout << "Mã Ngân Hàng: " << bankId << endl;
    cout << "Địa chỉ: " << location << endl;
    cout << "=======================================" << endl;
}

Customer* Bank::findCustomerById(int customerId) {
    for (auto& customer : customers) {
        if (customer.getID() == customerId) {
            return &customer;
        }
    }
    return nullptr;
}

bool Bank::isLoanEligBankible(int loanAmount) const {
    return loanAmount <= 10000; // Ví dụ đơn giản về điều kiện vay
}

std::vector<Customer>* Bank::getCustomers() {
    return &customers;
}

std::vector<Teller>* Bank::getTellers() {
    return &tellers;
}