#include "mainwindow.h"

#include "sqlitedbmanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DBManager* dbManager = SqliteDBManager::getInstance();

    // Підключаємось до бази даних
    dbManager->connectToDataBase();

    MainWindow w(dbManager);
    w.show();
    return a.exec();
}
