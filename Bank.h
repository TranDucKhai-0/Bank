#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include "Customer.h"
#include "Teller.h"
#include "Account.h"
//#include "Loan.h"

//class Customer;
//class Teller;


class Bank {
private:
    int bankId;
    std::string name;
    std::string location;
    std::vector<Customer> customers;
    std::vector<Teller> tellers;

public:
    // Constructor
    Bank(int id, const std::string& name, const std::string& location);

    // Thêm khách hàng
    void addCustomer(const Customer& customer);

    // Thêm giao dịch viên
    void addTeller(const Teller& teller);

    // Hiển thị thông tin ngân hàng
    void displayBankInfo();

    // Tìm khách hàng theo ID
    Customer* findCustomerById(int customerId);

    // Kiểm tra điều kiện vay
    bool isLoanEligBankible(int loanAmount) const;

    // Trả về danh sách khách hàng
    std::vector<Customer>* getCustomers();

    // Trả về danh sách giao dịch viên
    std::vector<Teller>* getTellers();
};

#endif // BANK_H