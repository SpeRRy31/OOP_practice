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

    system("pause");
    return 0;
}