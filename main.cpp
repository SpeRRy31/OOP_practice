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

    Seller seller1, seller2;
    cout << "������ ���������� ��� �������� 1:\n";
    cin >> seller1;

    cout << "\n������ ���������� ��� �������� 2:\n";
    cin >> seller2;

    cout << "\n���������� ��� �������� 1:\n" << seller1;
    cout << "\n���������� ��� �������� 2:\n" << seller2;

    system("pause");
    return 0;
}