#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dbmanager.h"
#include "sqlitedbmanager.h"

MainWindow::MainWindow(DBManager* dbManager,  QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), dbManager(dbManager)
{
    ui->setupUi(this);

    this->CreateCustomer = new DialogCreateCustomer;
    this->ShowCustomer = new DialogShowCustomer(this->dbManager, this);
    connect(CreateCustomer, &DialogCreateCustomer::createdCustomer, ShowCustomer, &DialogShowCustomer::on_createCustomer);

    this->CreateSeller = new DialogCreateSeller;
    this->ShowSeller = new DialogShowSeller(this->dbManager, this);
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
    CreateSeller->setModal(false);
    CreateSeller->exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    ShowCustomer->setModal(true);
    ShowCustomer->exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    ShowSeller->setModal(false);
    ShowSeller->exec();
}


void MainWindow::on_pushButton_5_clicked()
{
    QApplication::exit();
}

