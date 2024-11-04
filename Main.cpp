#include <iostream>
#include <string>
#include "Bank.h"
#include "Teller.h"
#include "Customer.h"

using namespace std;

int main() {
    // Khởi tạo ngân hàng
    Bank skyBank(113, "Sky Bank", "Sao Hỏa");

    // Khởi tạo giao dịch viên với tên là "Khai Dep Trai"
    // Sử dụng std::string để đảm bảo hàm khởi tạo nhận đúng kiểu dữ liệu
    Teller khai(1, 1234, std::string("Khai Dep Trai"), &skyBank);
    skyBank.addTeller(khai);

    // Khởi tạo khách hàng
    Customer customer1(101, 5678, "Nguyen Van A", "123 Sao Hỏa", "0912345678");
    Customer customer2(102, 4321, "Tran Thi B", "456 Sao Hỏa", "0987654321");

    // Thêm khách hàng vào ngân hàng
    skyBank.addCustomer(customer1);
    skyBank.addCustomer(customer2);

    // Hiển thị thông tin ngân hàng
    skyBank.displayBankInfo();

    // Hiển thị thông tin giao dịch viên
    cout << "\n=== Giao diện giao dịch viên ===\n";
    khai.interact();

    // Thực hiện một số giao dịch mẫu
    cout << "\n=== Thực hiện các giao dịch mẫu ===\n";

    // Giao dịch viên Khai giúp khách hàng mở tài khoản mới
    khai.openAccount(customer1.getID(), 1000); // Mở tài khoản cho customer1 với số dư ban đầu là 1000
    khai.openAccount(customer2.getID(), 1500); // Mở tài khoản cho customer2 với số dư ban đầu là 1500

    // Giao dịch viên Khai giúp khách hàng nạp tiền vào tài khoản
    khai.collectMoney(customer1.getID(), 500, 1); // Nạp 500 vào tài khoản ID 1 của customer1
    khai.collectMoney(customer2.getID(), 700, 2); // Nạp 700 vào tài khoản ID 2 của customer2

    // Khách hàng A thực hiện nạp và rút tiền từ tài khoản
    customer1.depositMoney(1000, 1);  // Khách hàng A nạp 1000 vào tài khoản ID 1
    customer1.withdrawMoney(300, 1);   // Khách hàng A rút 300 từ tài khoản ID 1

    // Khách hàng B xin vay
    cout << "\n=== Yêu cầu vay tiền ===\n";
    if (khai.loanRequest(customer2.getID(), 2000, "Personal Loan")) {
        customer2.applyForLoan("Personal Loan", 2000); // Lưu yêu cầu vay trong lịch sử giao dịch của khách hàng B
        cout << "Yêu cầu vay của khách hàng đã được chấp nhận.\n";
    } else {
        cout << "Yêu cầu vay của khách hàng không thành công.\n";
    }

    // Kiểm tra thông tin tài khoản của khách hàng
    cout << "\n=== Kiểm tra thông tin tài khoản khách hàng ===\n";
    customer1.viewAccountDetails();
    customer2.viewAccountDetails();

    // Kiểm tra thông tin khoản vay
    cout << "\n=== Thông tin khoản vay ===\n";
    customer2.viewLoanDetails();

    // Đăng nhập và kiểm tra tính năng
    cout << "\n=== Kiểm tra đăng nhập ===\n";
    // Giả sử có một hàm đăng nhập cho giao dịch viên (nếu cần thiết)
    // Select_Login(skyBank.getCustomers(), skyBank.getTellers()); // Bỏ qua phần đăng nhập nếu không được định nghĩa

    return 0;
}