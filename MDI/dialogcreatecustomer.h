#ifndef DIALOGCREATECUSTOMER_H
#define DIALOGCREATECUSTOMER_H

#include <QDialog>
#include "Customer.h"

namespace Ui {
class DialogCreateCustomer;
}

class DialogCreateCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreateCustomer(QWidget *parent = nullptr);
    ~DialogCreateCustomer();

signals:
    void createdCustomer(Customer *customer);

private slots:
    void on_createCustomerBtn_clicked();

private:
    Ui::DialogCreateCustomer *ui;

    Customer *customer;
};

#endif // DIALOGCREATECUSTOMER_H
