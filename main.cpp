#include <iostream>
#include "Customer.h"
#include "Seller.h"
#include "windows.h"
#include <cstdlib>


using namespace std;

int menu() {
    int choice;
    cout << "Меню:\n";
    cout << "1. Створити Customer\n";
    cout << "2. Створити Seller\n";
    cout << "Ваш вибір: ";
    cin >> choice;
    return choice;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_PERSON = 5;
    Person* personList[MAX_PERSON];

    int i = 0;
    do {
        switch (menu()) {
        case 1:
            personList[i] = new Customer();
            personList[i]->getData();
            break;
        case 2:
            personList[i] = new Seller();
            personList[i]->getData();
            break;
        default:
            cout << "Вашого вибору не існує... Повторіть знову.\n";
            --i;
        }
        i++;
    } while (i < MAX_PERSON);

    cout << "\nДані про персону\n";
    for (int i = 0; i < MAX_PERSON; ++i) {
        cout << personList[i]->toString() << endl;
    }

    cout << "\nto_String:\n";
    for (int i = 0; i < MAX_PERSON; ++i) {
        cout << personList[i]->toString() << endl;
    }

    for (int i = 0; i < MAX_PERSON; ++i) {
        delete personList[i];
    }


    system("pause");
    return 0;
}