#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "File_tam.cpp"

using namespace std;

// Hàm giao diện Teller
void Interface_Customer(Customer &pObject)
{
    bool logic = true; // biến dừng vòng lặp
    while (logic)
    {
        Sleep(500); // delay 0.5s xuất ra màn hình
    }
}

// Hàm giao diện Teller
void Interface_Teller(Teller &pObject)
{
    bool logic = true; // biến dừng vòng lặp
    while (logic)
    {
        Sleep(500); // delay 0.5s xuất ra màn hình

        cout << "Welcome Teller: " << pObject.getName() << endl;
        cout << "" << endl;
    }
}

// Hàm tìm Name và PIN trong cùng 1 đối tượng thuộc vector chứ dữ liệu Khách hàng
Customer *Search_Customer(vector<Customer> &vector, string name, int PIN)
{
    int n = vector.size(); // lấy độ dài vector hiện tại

    // so sánh name và PIN của đối tượng với đối tượng có trong vector dữ liệu khách hàng
    for(Customer &pObject : vector) {
        if(pObject.getName() == name && pObject.getPIN() == PIN) return &pObject; // trả về địa chỉ đối tượng
    }
    return NULL;
}

// Hàm tìm Name và PIN trong cùng 1 đối tượng thuộc vector chứ dữ liệu Teller
Teller *Search_Teller(vector<Teller> &vector, string name, int PIN)
{
    int n = vector.size(); // lấy độ dài vector hiện tại

    // so sánh name và PIN của đối tượng với đối tượng có trong vector dữ liệu Teller
    for(Teller &pObject : vector) {
        if(pObject.getName() == name && pObject.getPIN() == PIN) return &pObject; // trả về địa chỉ đối tượng
    }
    return NULL;
}

// đăng nhập bằng Name và PIN, Name == tên tài Khoản, PIN == pass, giống TK vs MK khi đăng nhập ứng dụng
// Hàm đăng nhập cho đối tượng Customer
void Login_Customer(vector<Customer> vector)
{
    int PIN;
    string name;
    Customer *pObject = NULL; // biến chứ địa chỉ đối tượng
    cout << "Name: ";
    cin >> name; // nhập tên
    cout << "PIN: ";
    cin >> PIN; // nhập mã PIN

    pObject = Search_Customer(vector, name, PIN);

    // kiểm tra con trỏ có trống không
    if (pObject != NULL)
    {
        // xuất giao diện của Teller
        Interface_Customer(*pObject);
    }
    else
    {
        cout << "Name hoặc PIN không chính xác!" << endl;
        delete pObject;         // xóa ponter, tránh tràn bộ nhớ
        Login_Customer(vector); // gọi lại hàm khi gặp lỗi
    }
} //

// Hàm đăng nhập cho đối tượng Teller
void Login_Teller(vector<Teller> vector)
{
    int PIN;
    string name;
    Teller *pObject = NULL; // biến chứ địa chỉ đối tượng
    cout << "Name: ";
    cin >> name; // nhập tên
    cout << "PIN: ";
    cin >> PIN; // nhập mã PIN

    pObject = Search_Teller(vector, name, PIN);

    // kiểm tra con trỏ có trống không
    if (pObject != NULL)
    {
        // xuất giao diện của Teller
        Interface_Teller(*pObject);
    }
    else
    {
        cout << "Name hoặc PIN không chính xác!" << endl;
        delete pObject;       // xóa ponter, tránh tràn bộ nhớ
        Login_Teller(vector); // gọi lại hàm khi gặp lỗi
    }
} //

// lựa chọn đăng nhập giữa Teller vs Customer
void Select_Login(vector<Customer> vector_customer, vector<Teller> vector_teller)
{
    int x;
    cout << "Bạn muốn đăng nhập với tư cách nào?" << endl;
    cout << "1. Teller" << endl;
    cout << "2. Customer" << endl;
    cin >> x;
    switch (x)
    {
    case 1:
        Login_Teller(vector_teller); // đăng nhập bằng tài khoản của Teller
        break;
    case 2:
        Login_Customer(vector_customer); // đăng nhập bằng tài khoản của Customer
        break;
    default:
        cout << "Không hợp lệ!" << endl;              // in lỗi
        Select_Login(vector_customer, vector_teller); // chọn lại
    }
} //

// xuất giao diện Bank
void Interface_Bank(Bank object)
{
    Sleep(500);                                          // Delay 0.5s
    cout << "Bank: " << object.getName() << endl;        // xuất tên của Bank
    cout << "BankID: " << object.getId() << endl;        // xuất ID của Bank
    cout << "Address: " << object.getLocation() << endl; // xuất địa chỉ của Bank


}
