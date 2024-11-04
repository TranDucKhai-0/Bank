#ifndef LOAN_H
#define LOAN_H

#include <string>
//#include "Bank.h"

class Customer;



class Loan {
private:
    int id;
    std::string type;
    int accountId;
    int customerId;
    int amount;

public:
    Loan();
    Loan(int id, const std::string &type, int accountId, int customerId, int amount);

    int getId() const;
    std::string getType() const;
    int getAccountId() const;
    int getCustomerId() const;
    int getMoney() const;

    void setId(int id);
    void setType(const std::string &type);
    void setAccountId(int accountId);
    void setCustomerId(int customerId);
    void setMoney(int amount);

    void displayLoanInfo() const;
};

#endif // LOAN_H