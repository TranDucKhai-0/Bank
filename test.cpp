#ifndef TELLER_H
#define TELLER_H

#include <string>
#include "Bank.h"

using namespace std;

class Teller {
private:
    int bankId, PIN;
    string Name;
    Bank *parentBank = nullptr; // con trỏ trở ngược lại vị trí của Bank
public:
    

    // Constructor
    Teller(int id, int PIN, const std:string& name, Bank *bank); // nhập thông tin Teller
    // Get the parent bank
    Bank* Teller::getParentBank() const {
    return parentBank;
}

    // Get teller's name
    std::string Teller::getName() const {
    return Name;
}

    // Get teller's PIN
    int Teller::getPIN() const {
    return PIN;
}

    // nhận tiền từ khách hàng và nạp vào tài khoản
void Teller::CollectMoney(int customerId, int money, int accountId) const{
        if (parentBank) {
        bool success = parentBank->depositToAccount(customerId, accountId, money);
        if (success) {
            std::cout << "Successfully deposited " << money << " to account " << accountId << ".\n";
        } else {
            std::cout << "Deposit failed. Account or customer ID might be invalid.\n";
        }
    } else {
        std::cout << "Teller is not linked to a bank.\n";
    }
}
    // Chức năng mở tài khoản
    bool Teller::OpenAccount(int customerId, int money) const{
        if (parentBank) {
        int newAccountId = parentBank->createAccount(customerId, initialDeposit);
        if (newAccountId != -1) {
            std::cout << "Account created with ID " << newAccountId << " for customer " << customerId << ".\n";
            return true;
        } else {
            std::cout << "Account creation failed.\n";
        }
    }
    return false;
}
    // Chức năng đóng tài khoản 
    int Teller::CloseAccount(int customerId, int accountId) const{
        if (parentBank) {
        int balance = parentBank->closeAccount(customerId, accountId);
        if (balance != -1) {
            std::cout << "Account " << accountId << " closed. Balance returned: " << balance << ".\n";
        } else {
            std::cout << "Failed to close account. Account or customer ID might be invalid.\n";
        }
        return balance;
    }
    return -1;
}

    // Chức năng giải quyết yêu cần vay
    bool LoanRequest(int customerId, int loanMoney,const string& type) const{
         if (parentBank) {
        bool approved = parentBank->processLoanRequest(customerId, loanAmount, type);
        if (approved) {
            std::cout << "Loan approved for " << loanAmount << ".\n";
            return true;
        } else {
            std::cout << "Loan request denied.\n";
        }
    }
    return false;
}
    // Lấy thông tin khách hàng
    void Teller::ProvideInfo(int customerId) const{
         if (parentBank) {
        std::string info = parentBank->getCustomerInfo(customerId);
        if (!info.empty()) {
            std::cout << "Customer Information: " << info << "\n";
        } else {
            std::cout << "No information found for customer ID " << customerId << ".\n";
        }
    } else {
        std::cout << "Teller is not linked to a bank.\n";
    }
}
    // lấy giá trị name
    string getName();
    // lấy giá trị mã PIN
    int getPIN();
    // Hàm giao diện Teller
    void Teller::Interface_Teller(const Bank *bank) const{
        if (bank) {
        std::cout << "Teller interface accessed. Teller is connected to bank: " << bank->getName() << "\n";
        // Further operations can be added here for interaction
    } else {
        std::cout << "No bank connection found for this teller.\n";
    }
} 

};
#endif // TELLER_H