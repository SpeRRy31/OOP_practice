#include "dialogcreateseller.h"
#include "ui_dialogcreateseller.h"

#include <QMessageBox>

#include "logfile.h"
LogFile l("logFile.txt");


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
    try {
        int ID = ui->IDEdit->text().toInt();
        QString firstname = ui->firstnameEdit->text();
        QString secondname = ui->secondnameEdit->text();
        QString thirdname = ui->thirdnameEdit->text();
        QString address = ui->addressEdit->text();
        QString number = ui->numberEdit->text();
        QString product = ui->goodsEdit->text();

        if (ID==0 || firstname.isEmpty() || secondname.isEmpty() || thirdname.isEmpty() || address.isEmpty() || number.isEmpty() || product.isEmpty()){
            QMessageBox::critical(this, "помилка", "Поля не заповнені або заповнені не правильно.");
        }
        else{
            seller = new Seller(ID, firstname.toStdString(), secondname.toStdString(), thirdname.toStdString(), address.toStdString(), number.toStdString(), product.toStdString());

            qDebug() << QString::fromStdString(seller->toString());

            emit createdSeller(seller);


            this->close();
        }
    } catch (const std::exception& e) {
        l.logError(e.what());
    }
}

