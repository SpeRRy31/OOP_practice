#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSqlTableModel>
class QSqlTableModel;
class DBManager;

#include "dialogcreatecustomer.h"
#include "dialogcreateseller.h"
#include "dialogshowcustomer.h"
#include "dialogshowseller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:

    ~MainWindow();
    explicit MainWindow(DBManager* dbManrage, QWidget* parent = nullptr);
private:
    DBManager* dbManager;

    //QSqlTableModel* model;






private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();
private:
    Ui::MainWindow *ui;

    DialogCreateCustomer *CreateCustomer;
    DialogShowCustomer *ShowCustomer;
    DialogCreateSeller *CreateSeller;
    DialogShowSeller *ShowSeller;

};
#endif // MAINWINDOW_H
