#ifndef DIALOGSHOWCUSTOMER_H
#define DIALOGSHOWCUSTOMER_H

#include <QDialog>

#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <list>
#include "Customer.h"

namespace Ui {
class DialogShowCustomer;
}

class DialogShowCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShowCustomer(QWidget *parent = nullptr);
    ~DialogShowCustomer();

public slots:
    void on_createCustomer(Customer *customer);
private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogShowCustomer *ui;
};

#endif // DIALOGSHOWCUSTOMER_H
