#ifndef DIALOGSHOWCUSTOMER_H
#define DIALOGSHOWCUSTOMER_H

#include <QDialog>

#include <QVBoxLayout>
#include <QSqlTableModel>
#include <QPushButton>
#include "Customer.h"
#include "sqlitedbmanager.h"

class QSqlTableModel;
class DBManager;

namespace Ui {
class DialogShowCustomer;
}

class DialogShowCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShowCustomer(DBManager* dbManager, QWidget *parent = nullptr);
    ~DialogShowCustomer();

public slots:
    void on_createCustomer(Customer *customer);
private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogShowCustomer *ui;
    DBManager* dbManager;
    QSqlTableModel* model;


    void setupModel(const QString& tableName, const QStringList& headers);
    void createUI();
};

#endif // DIALOGSHOWCUSTOMER_H
