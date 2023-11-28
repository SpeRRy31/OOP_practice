#include <iostream>
#include "Customer.h"
#include "Seller.h"
#include "windows.h"
#include <cstdlib>
#include "vector.cpp"

using namespace std;

int menu() {
    int choice;
    cout << "Меню:\n";
    cout << "1. Створити Customer\n";
    cout << "2. Створити Seller\n";
    cout << "3. Вихід\n";
    cout << "Ваш вибір: ";
    cin >> choice;
    return choice;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    /*
    Vector<int> array;

    for (int i = 0; i < 50; i += 3) {
        array.push_back(i);
    }

    for (int i = 0; i < array.getSize(); i++) {
        cout << array.at(i) << endl;
    }
    */
    Vector<Seller> seller_vector;
    Seller seller1, seller2;
    seller1.getData();
    seller2.getData();

    seller_vector.push_back(seller1);
    seller_vector.push_back(seller2);

    seller_vector.display();

    cin.get();
    return 0;
}