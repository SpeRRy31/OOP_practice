#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->CreateCustomer = new DialogCreateCustomer;
    this->ShowCustomer = new DialogShowCustomer;
    connect(CreateCustomer, &DialogCreateCustomer::createdCustomer, ShowCustomer, &DialogShowCustomer::on_createCustomer);

    this->CreateSeller = new DialogCreateSeller;
    this->ShowSeller = new DialogShowSeller;
    connect(CreateSeller, &DialogCreateSeller::createdSeller, ShowSeller, &DialogShowSeller::on_createdSeller);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    CreateCustomer->setModal(true);
    CreateCustomer->exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    CreateSeller->setModal(true);
    CreateSeller->exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    ShowCustomer->setModal(true);
    ShowCustomer->exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    ShowSeller->setModal(true);
    ShowSeller->exec();
}


void MainWindow::on_pushButton_5_clicked()
{
    QApplication::exit();
}

