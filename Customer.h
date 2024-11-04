#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Account.h"
#include "Loan.h"

class Customer {
private:
    int id;
    int pin;
    std::string name;
    std::string address;
    std::string phoneNo;
    std::vector<Account*> accounts;
    std::vector<Loan> loans;
    std::vector<std::string> transactionHistory;

public:
    Customer(int id, int pin, const std::string& name, const std::string& address, const std::string& phoneNo);

    int getID() const;
    int getPIN() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getPhoneNo() const;

    void addAccount(Account* account);
    Account* findAccountById(int accountId) const;
    bool removeAccount(int accountId);
    void depositMoney(int amount, int accountId);
    bool withdrawMoney(int amount, int accountId);
    void addLoan(const Loan& loan);
    void addTransaction(const std::string& transaction);
    void viewAccountDetails() const;
    void viewLoanDetails() const;
    const std::vector<std::string>& getTransactionHistory() const;
    const std::vector<Account*>& getAccounts() const;

    // Thêm hàm getLoans()
    const std::vector<Loan>& getLoans() const;

    void applyForLoan(const std::string& type, int amount);
};

#endif // CUSTOMER_H