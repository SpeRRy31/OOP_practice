#include <iostream>
#include "Customer.h"
#include "Seller.h"
#include "windows.h"
#include <cstdlib>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Customer customer1;
    cout << "¬вед≥ть ≥нформац≥ю про покупц€:\n";
    cin >> customer1;

    Seller seller1;
    cout << "¬вед≥ть ≥нформац≥ю про продавц€:\n";
    cin >> seller1;

    cout << customer1.toString();

    cout << "\n≤нформац≥€ про продавц€:\n" << seller1;

    system("pause");
    return 0;
}