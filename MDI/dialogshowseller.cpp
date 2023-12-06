#include "dialogshowseller.h"
#include "ui_dialogshowseller.h"

DialogShowSeller::DialogShowSeller(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogShowSeller)
{
    ui->setupUi(this);
}

DialogShowSeller::~DialogShowSeller()
{
    delete ui;
}

void DialogShowSeller::on_createdSeller(Seller *seller)
{
    QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(seller->toString()));
    ui->listWidget->addItem(item);
    qDebug() << "addData";
}

void DialogShowSeller::on_pushButton_clicked()
{
    this->close();
}

