#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Customer.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Customer customer1;
bool objCreated=false;

void MainWindow::on_createClassBtn_clicked()
{
    if (!ui->IDEdit->text().isEmpty() && !ui->firstnameEdit->text().isEmpty() &&
        !ui->secindnameEdit->text().isEmpty() && !ui->thirdnaeEdit->text().isEmpty() &&
        !ui->addressEdit->text().isEmpty() && !ui->numberEdit->text().isEmpty() &&
        !ui->balanceEdit->text().isEmpty()) {

        customer1.init(ui->IDEdit->text().toInt(), ui->firstnameEdit->text().toStdString(), ui->secindnameEdit->text().toStdString(), ui->thirdnaeEdit->text().toStdString(),
                           ui->addressEdit->text().toStdString(), ui->numberEdit->text().toStdString(), ui->balanceEdit->text().toFloat());
        objCreated=true;

        QMessageBox infoBox;
        infoBox.setIcon(QMessageBox::Information);
        infoBox.setWindowTitle("Клас створено");
        infoBox.setText(QString::fromStdString(customer1.toString()));
        infoBox.exec();


    }
    else {
        QMessageBox errorBox;
        errorBox.setIcon(QMessageBox::Critical);
        errorBox.setWindowTitle("Помилка");
        errorBox.setText("Заповніть усі поля");
        errorBox.exec();
    }
}


void MainWindow::on_exitBtn_clicked()
{
    QApplication::exit();
}


void MainWindow::on_setobjBtn_clicked()
{
    if (objCreated){
        QMessageBox infoBox;
        infoBox.setIcon(QMessageBox::Information);
        infoBox.setWindowTitle("Дані про клас");
        infoBox.setText(QString::fromStdString(customer1.toString()));
        infoBox.exec();
    }
    else {
        QMessageBox errorBox;
        errorBox.setIcon(QMessageBox::Critical);
        errorBox.setWindowTitle("Помилка");
        errorBox.setText("Об'єкт не створено");
        errorBox.exec();
    }

}

