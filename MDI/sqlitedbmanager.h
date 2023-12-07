#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

#include "dbmanager.h"

/* Директиви імен таблиці, полів таблиці і бази даних */
#define DATABASE_HOST_NAME   "ExampleDataBase"
#define DATABASE_FILE_NAME   "DataBase.sqlite"

#define TABLE_CUSTOMER                      "customers"
#define TABLE_CUSTOMER_ID                   "id"
#define TABLE_CUSTOMER_FIRSTNAME            "firstname"
#define TABLE_CUSTOMER_SECONDNAME           "secondname"
#define TABLE_CUSTOMER_THIRDNAME            "thirdname"
#define TABLE_CUSTOMER_ADDRESS              "address"
#define TABLE_CUSTOMER_NUMBER               "number_card"
#define TABLE_CUSTOMER_BALANCE              "balance"


#define TABLE_SELLER                      "sellers"
#define TABLE_SELLER_ID                   "id"
#define TABLE_SELLER_FIRSTNAME            "firstname"
#define TABLE_SELLER_SECONDNAME           "secondname"
#define TABLE_SELLER_THIRDNAME            "thirdname"
#define TABLE_SELLER_ADDRESS              "address"
#define TABLE_SELLER_NUMBER               "number_card"
#define TABLE_SELLER_GOODS                "goods"



// Клас, який реалізує логіку абстрактного класу DBManager для роботи із БД SQLite
class SqliteDBManager : public DBManager {

public:
    // Метод для отримання екземпляру даного класу (патерн Singleton)
    static SqliteDBManager* getInstance();

    // Метод для підключення до бази даних
    void connectToDataBase() override;

    // Метод для отримання обробника (хендлера) підключення до БД
    QSqlDatabase getDB() override;

    // Метод для вставки записів у таблицю
    bool inserIntoCustomerTable(const Customer& customer) override;
    bool inserIntoSellerTable(const Seller& seller) override;

private:
    // Обробник підключення до БД, через який буде виконуватись робота із БД
    QSqlDatabase db;

    static SqliteDBManager* instance;

    // Приватний конструктор
    SqliteDBManager();

    // Внутрішні методи для роботи з базою даних
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTables();
};

#endif // DATABASE_H
