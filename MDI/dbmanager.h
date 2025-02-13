#ifndef DBMANAGER_H
#define DBMANAGER_H

//#include "message.h"
#include "Customer.h"
#include "Seller.h"
#include <QSqlDatabase>

// Абстрактний клас (інтерфейс) для роботи з базою даних
class DBManager {
public:
    // Суто віртуальний метод для підключення до бази даних
    virtual void connectToDataBase() = 0;

    // Суто віртуальний метод для отримання обробника (хендлера) підключення до БД
    virtual QSqlDatabase getDB() = 0;

    // Суто віртуальний метод для вставки записів у таблицю
    virtual bool inserIntoCustomerTable(const Customer& customer) = 0;

    virtual bool inserIntoSellerTable(const Seller& seller) = 0;
};

#endif // DBMANAGER_H
