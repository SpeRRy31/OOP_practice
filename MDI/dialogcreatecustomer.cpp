#include "dialogcreatecustomer.h"
#include "ui_dialogcreatecustomer.h"
#include<QMessageBox>
#include<QListWidgetItem>
#include<QListWidget>
#include<QDebug>

DialogCreateCustomer::DialogCreateCustomer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogCreateCustomer)
{
    ui->setupUi(this);
}

DialogCreateCustomer::~DialogCreateCustomer()
{
    delete ui;
}

void DialogCreateCustomer::on_createCustomerBtn_clicked()
{
    int ID = ui->IDEdit->text().toInt();
    QString firstname = ui->firstnameEdit->text();
    QString secondname = ui->secondnameEdit->text();
    QString thirdname = ui->thirdnameEdit->text();
    QString address = ui->addressEdit->text();
    QString number = ui->numberEdit->text();
    float balance = ui->balanceEdit->text().toFloat();

    if (ID==0 || firstname.isEmpty() || firstname.isEmpty() || firstname.isEmpty() || firstname.isEmpty() || firstname.isEmpty() || balance < 0){
        QMessageBox::critical(this, "ПОМИЛКА", "Заповніть усі поля.");
    }
    else{
        customer = new Customer(ID, firstname.toStdString(), secondname.toStdString(), thirdname.toStdString(), address.toStdString(), number.toStdString(), balance);

        qDebug() << QString::fromStdString(customer->toString());

        emit createdCustomer(customer);

        this->close();
    }


}

