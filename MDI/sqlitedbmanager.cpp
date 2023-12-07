#include "sqlitedbmanager.h"

#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDate>
#include <QDebug>

SqliteDBManager* SqliteDBManager::instance = nullptr;

SqliteDBManager::SqliteDBManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOST_NAME);
    db.setDatabaseName(DATABASE_FILE_NAME);
}

// Метод для отримання екземпляру даного класу (патерн Singleton)
SqliteDBManager* SqliteDBManager::getInstance() {
    if (instance == nullptr) {
        instance = new SqliteDBManager();
    }
    return instance;
}

// Метод для підключення до бази даних
void SqliteDBManager::connectToDataBase() {
    /* Перед підключенням до бази даних виконуємо перевірку на її існування.
     * В залежності від результату виконуємо відкриття бази даних або її відновлення
     * */
    if (QFile(DATABASE_FILE_NAME).exists()) {
        this->openDataBase();
    } else {
        this->restoreDataBase();
    }
}

// Метод для отримання обробника підключення до БД
QSqlDatabase SqliteDBManager::getDB() {
    return db;
}

// Метод відновлення бази даних
bool SqliteDBManager::restoreDataBase() {
    if (this->openDataBase()) {
        if (!this->createTables()) {
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не вдалось відновити базу даних";
        return false;
    }
}

// Метод для відкриття бази даних
bool SqliteDBManager::openDataBase() {
    /* База даних відкривається по вказаному шляху
     * та імені бази даних, якщо вона існує
     * */
    if (db.open()) {
        return true;
    } else
        return false;
}

// Метод закриття бази даних
void SqliteDBManager::closeDataBase() {
    db.close();
}

// Метод для створення таблиці в базі даних
bool SqliteDBManager::createTables() {
    /* В даному випадку використовується фурмування сирого SQL-запиту
     * з наступним його виконанням.
     * */
    QSqlQuery query;
    if (!query.exec("CREATE TABLE " TABLE_CUSTOMER " ("
                    TABLE_CUSTOMER_ID              " INTEGER PRIMARY KEY AUTOINCREMENT, "
                    TABLE_CUSTOMER_FIRSTNAME       " VARCHAR(255)    NOT NULL,"
                    TABLE_CUSTOMER_SECONDNAME      " VARCHAR(255)    NOT NULL,"
                    TABLE_CUSTOMER_THIRDNAME       " VARCHAR(255)    NOT NULL,"
                    TABLE_CUSTOMER_ADDRESS         " VARCHAR(255)    NOT NULL,"
                    TABLE_CUSTOMER_NUMBER          " VARCHAR(255)    NOT NULL,"
                    TABLE_CUSTOMER_BALANCE         " REAL            NOT NULL"
                    " )"
                    )) {
        qDebug() << "DataBase: error of create " << TABLE_CUSTOMER;
        qDebug() << query.lastError().text();
    } else if (!query.exec("CREATE TABLE " TABLE_SELLER " ("
                    TABLE_SELLER_ID              " INTEGER PRIMARY KEY AUTOINCREMENT, "
                    TABLE_SELLER_FIRSTNAME       " VARCHAR(255)    NOT NULL,"
                    TABLE_SELLER_SECONDNAME      " VARCHAR(255)    NOT NULL,"
                    TABLE_SELLER_THIRDNAME       " VARCHAR(255)    NOT NULL,"
                    TABLE_SELLER_ADDRESS         " VARCHAR(255)    NOT NULL,"
                    TABLE_SELLER_NUMBER          " VARCHAR(255)    NOT NULL,"
                    TABLE_SELLER_GOODS           " VARCHAR(255)    NOT NULL"
                    " )"
                    )) {
        qDebug() << "DataBase: error of create " << TABLE_SELLER;
        qDebug() << query.lastError().text();
    } else
        return true;
    return false;
}

// Метод для вставки записів у таблицю messages
bool SqliteDBManager::inserIntoCustomerTable(const Customer& customer) {
    // SQL-запит формується із об'єкта класу Message
    QSqlQuery query;
    /*
     * Спочатку SQL-запит формується з ключами, які потім зв'язуються методом bindValue
     * для підставки даних із об'єкта класу Message
     * */
    query.prepare("INSERT INTO " TABLE_CUSTOMER " ( "
                  TABLE_CUSTOMER_FIRSTNAME     ", "
                  TABLE_CUSTOMER_SECONDNAME    ", "
                  TABLE_CUSTOMER_THIRDNAME     ", "
                  TABLE_CUSTOMER_ADDRESS       ", "
                  TABLE_CUSTOMER_NUMBER        ", "
                  TABLE_CUSTOMER_BALANCE " ) "
                  "VALUES (:first, :second, :third, :address, :number, :balance )");
    query.bindValue(":first", QString::fromStdString(customer.getFirstname()));
    query.bindValue(":second", QString::fromStdString(customer.getSecondname()));
    query.bindValue(":third", QString::fromStdString(customer.getThirdname()));
    query.bindValue(":address", QString::fromStdString(customer.getAddress()));
    query.bindValue(":number", QString::fromStdString(customer.getNumber()));
    query.bindValue(":balance", customer.getBalance());

    // Після чого виконується запит методом exec()
    if (!query.exec()) {
        qDebug() << "error insert into " << TABLE_CUSTOMER;
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();

        return false;
    } else
        return true;
}

bool SqliteDBManager::inserIntoSellerTable(const Seller& seller) {
    // SQL-запит формується із об'єкта класу Message
    QSqlQuery query;
    /*
     * Спочатку SQL-запит формується з ключами, які потім зв'язуються методом bindValue
     * для підставки даних із об'єкта класу Message
     * */
    query.prepare("INSERT INTO " TABLE_SELLER " ( "
                  TABLE_SELLER_FIRSTNAME     ", "
                  TABLE_SELLER_SECONDNAME    ", "
                  TABLE_SELLER_THIRDNAME     ", "
                  TABLE_SELLER_ADDRESS       ", "
                  TABLE_SELLER_NUMBER        ", "
                  TABLE_SELLER_GOODS " ) "
                  "VALUES (:first, :second, :third, :address, :number, :goods )");
    query.bindValue(":first", QString::fromStdString(seller.getFirstname()));
    query.bindValue(":second", QString::fromStdString(seller.getSecondname()));
    query.bindValue(":third", QString::fromStdString(seller.getThirdname()));
    query.bindValue(":address", QString::fromStdString(seller.getAddress()));
    query.bindValue(":number", QString::fromStdString(seller.getNumber()));
    query.bindValue(":goods", QString::fromStdString(seller.getProduct()));

    // Після чого виконується запит методом exec()
    if (!query.exec()) {
        qDebug() << "error insert into " << TABLE_SELLER;
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();

        return false;
    } else
        return true;
}
