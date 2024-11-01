#include <iostream>
#include <string>
#include <vector>
#include "File_tam.cpp"
#include "Fuction.cpp"



int main() {
    Bank Sky;
    Sky.setId(113); // đặt ID cho Bank
    Sky.setName("Sky"); // đặt tên cho Bank
    Sky.setLocation("Sao Hỏa"); // Nhập địa chỉ cho Bank

    vector<Customer> vector_customer; // vector chứa dữ liệu của các khách hàng
    vector<Teller> vector_teller; // vector chứa dữ liệu của các teller

    // nhập thông tin của khách hàng Khải
    Customer KhaiDepTrai;
    KhaiDepTrai.setId(1); // nhập id cho đối tượng khải
    KhaiDepTrai.setPIN(1); // Nhập mã PIN cho đối tượng khải
    KhaiDepTrai.setName("Khai super handsome"); // nhập tên cho đối tượng khải
    //int Khai_id = KhaiDepTrai.getId();

    vector_customer.push_back(KhaiDepTrai); // thêm đối tượng Khải vào vector dữ liệu khách hàng

    

    return 0;
}
