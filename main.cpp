#include <iostream>
#include "Customer.h"
#include "windows.h"
#include <cstdlib>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Customer customer;
    cin >> customer;
    cout << customer << "\n";

    system("pause");
    return 0;
}