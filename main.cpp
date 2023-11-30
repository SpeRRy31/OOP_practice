#include <iostream>
#include "Customer.h"
#include "Seller.h"
#include "windows.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int menu() {
    int choice;
    cout << "Меню:\n";
    cout << "1. Створити Customer\n";
    cout << "2. Створити Seller\n";
    cout << "3. Відобразити все та вийти\n";
    cout << "Ваш вибір: ";
    cin >> choice;
    return choice;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<int> indexVector;
    for (int i = 0; i < 10; i++) {
        indexVector.push_back(2 * i + 1); 
    }

    vector<int> iteratorVector;
    srand(time(0));  
    for (int i = 0; i < 10; i++) {
        iteratorVector.push_back(rand() % 100 * 2); 
    }

    sort(indexVector.begin(), indexVector.end());
    sort(iteratorVector.begin(), iteratorVector.end());
    
    vector<int> mergeVector;
    merge(indexVector.begin(), indexVector.end(), iteratorVector.begin(), iteratorVector.end(), back_inserter(mergeVector));

    cout << "Перший вектор: ";
    for (size_t i = 0; i < indexVector.size(); i++) {
        cout << indexVector[i] << " ";
    }
    cout << endl;

    cout << "Другий вектор: ";
    for (size_t i = 0; i < iteratorVector.size(); i++) {
        cout << iteratorVector[i] << " ";
    }

    cout << endl;

    cout << "Третій вектор: ";
    for (size_t i = 0; i < mergeVector.size(); i++) {
        cout << mergeVector[i] << " ";
    }

    cout << endl;

    vector<Person*> classVector;
    Person* person;
    bool init = true;
    while (init) {
        switch (menu()) {
        case 1:
            person = new Customer();
            person->getData();
            classVector.push_back(person);
            break;
        case 2:
            person = new Seller();
            person->getData();
            classVector.push_back(person);
            break;
        case 3:
            init = false;
            break;
        default:
            cout << "error.. input valid value.\n";
        }

        cout << endl;
    }

    for (int i = 0; i < classVector.size(); i++) {

        cout << classVector[i]->toString() << endl;
    }


    cout << endl;

    system("pause");

    return 0;
}