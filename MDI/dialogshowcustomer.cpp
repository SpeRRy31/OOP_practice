#include "dialogshowcustomer.h"
#include "ui_dialogshowcustomer.h"

DialogShowCustomer::DialogShowCustomer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogShowCustomer)
{
    ui->setupUi(this);
}

DialogShowCustomer::~DialogShowCustomer()
{
    delete ui;
}

void DialogShowCustomer::on_createCustomer(Customer *customer)
{
    QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(customer->toString()));
    ui->listWidget->addItem(item);
    qDebug() << "addData";
}

void DialogShowCustomer::on_pushButton_clicked()
{
    this->close();
}

