#include <iostream>
#include "Customer.h"
#include "windows.h"
#include <cstdlib>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Customer customer1, customer2, customer3;
    cin >> customer1 >> customer2 >> customer3;
    cout << customer1 << customer2 << customer3 << "\n";

    if (customer1 == customer2) {
        cout << "��'���� 1 �� 2 ���.\n";
    }
    else {
        cout << "��'���� 1 �� 2 �� ���.\n";
    }

    system("pause");
    return 0;
}