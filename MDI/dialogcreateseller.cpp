#include "dialogcreateseller.h"
#include "ui_dialogcreateseller.h"

#include <QMessageBox>
#include <string>


DialogCreateSeller::DialogCreateSeller(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogCreateSeller)
{
    ui->setupUi(this);
}

DialogCreateSeller::~DialogCreateSeller()
{
    delete ui;
}

void DialogCreateSeller::on_createSellerBtn_clicked()
{
    int ID = ui->IDEdit->text().toInt();
    QString firstname = ui->firstnameEdit->text();
    QString secondname = ui->secondnameEdit->text();
    QString thirdname = ui->thirdnameEdit->text();
    QString address = ui->addressEdit->text();
    QString number = ui->numberEdit->text();
    std::string list[1];
    list[0] = ui->goodsEdit->text().toStdString();


    if (ID==0 || firstname.isEmpty() || firstname.isEmpty() || firstname.isEmpty() || firstname.isEmpty() || firstname.isEmpty() || ui->goodsEdit->text().isEmpty()){
        QMessageBox::critical(this, "ПОМИЛКА", "Заповніть усі поля.");
    }
    else{
        seller = new Seller(ID, firstname.toStdString(), secondname.toStdString(), thirdname.toStdString(), address.toStdString(), number.toStdString(), list);

        qDebug() << QString::fromStdString(seller->toString());

        emit(createdSeller(seller));


        this->close();
    }
}

