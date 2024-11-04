#ifndef TELLER_H
#define TELLER_H


#include <string>

class Bank;
class Customer;
class Loan; 


class Teller {
private:
    int id;
    std::string name;
    int pin;
    Bank* bank; // Con trỏ tới ngân hàng nơi giao dịch viên làm việc

public:
    // Constructor
    Teller(int id, int pin,const std::string& name, Bank* bank);

    // Nạp tiền vào tài khoản khách hàng
    bool collectMoney(int customerId, int amount, int accountId);

    // Mở tài khoản mới cho khách hàng
    bool openAccount(int customerId, int initialDeposit);

    // Đóng tài khoản của khách hàng
    bool closeAccount(int customerId, int accountId);

    // Xử lý yêu cầu vay
    bool loanRequest(int customerId, int loanAmount, const std::string& loanType);

    // Cung cấp thông tin khách hàng
    void provideInfo(int customerId);

    // Hiển thị menu cho giao dịch viên
    void displayMenu();

    // Giao diện tương tác của giao dịch viên với ngân hàng
    void interact();

    // Lấy con trỏ tới ngân hàng mà giao dịch viên thuộc về
    Bank* getBank() const;

    // Lấy tên giao dịch viên
    std::string getName() const;

    // Lấy mã PIN của giao dịch viên
    int getPIN() const;

    void interact(Bank *bank);
};

#endif // TELLER_H