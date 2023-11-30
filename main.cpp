#include <iostream>
#include "Customer.h"
#include "Seller.h"
#include "windows.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

int menu() {
    int choice;
    cout << "Меню:\n";
    cout << "1. Створити Customer\n";
    cout << "2. Створити Seller\n";
    cout << "3. Знайти за ID\n";
    cout << "4. Відобразити все та вийти\n";
    cout << "Ваш вибір: ";
    cin >> choice;
    return choice;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    list<int> indexList;
    for (int i = 0; i < 10; i++) {
        indexList.push_back(2 * i + 1);  
    }

    list<int> iteratorList;
    srand(time(0)); 
    for (int i = 0; i < 10; i++) {
        iteratorList.push_back(rand() % 100 * 2);  
    }

    indexList.sort();
    iteratorList.sort();

    list<int> mergeList;
    merge(indexList.begin(), indexList.end(), iteratorList.begin(), iteratorList.end(), back_inserter(mergeList));

    cout << "Перший список: ";
    for (const auto& el : indexList) {
        cout << el << " ";
    }
    cout << endl;

    cout << "Другий список: ";
    for (const auto& el : iteratorList) {
        cout << el << " ";
    }
    cout << endl;

    cout << "Третій список: ";
    for (const auto& el : mergeList) {
        cout << el << " ";
    }
    cout << endl;
    //-----------------------------

    map<int, Person* > personMap;

    Person* person;

    bool init = true;
    while (init) {
        switch (menu()) {
        case 1:
            person = new Customer();
            person->getData();
            personMap[person->getID()] = person;
            break;
        case 2:
            person = new Seller();
            person->getData();
            personMap[person->getID()] = person;
            break;
        case 3: {
            int findID;

            cout << "Введіть ідентифікатор об'єкта для пошуку: ";
            cin >> findID;

            map<int, Person*>::iterator it = personMap.find(findID);

            if (it != personMap.end()) {
                cout << "Знайдено об'єкт:\n";
                cout << it->second->toString() << "\n";
            }
            else {
                cout << "Об'єкт з ID " << findID << " не знайдено.\n";
            }
            break; 
        }
        case 4:
            init = false;
            break;
        default:
            cout << "error.. input valid value.\n";
        }

        cout << endl;
    }

    for (const auto& el : personMap) {
        cout << el.second->toString() << "\n";
    }






    system("pause");

    return 0;
}