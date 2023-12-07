#ifndef DIALOGSHOWSELLER_H
#define DIALOGSHOWSELLER_H

#include <QDialog>

#include <QSqlTableModel>
#include "sqlitedbmanager.h"

class QSqlTableModel;
class DBManager;

#include "Seller.h"

namespace Ui {
class DialogShowSeller;
}

class DialogShowSeller : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShowSeller(DBManager* dbManager, QWidget *parent = nullptr);
    ~DialogShowSeller();

public slots:
    void on_createdSeller(Seller *seller);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogShowSeller *ui;
    DBManager* dbManager;
    QSqlTableModel* model;
    void setupModel(const QString& tableName, const QStringList& headers);
    void createUI();
};

#endif // DIALOGSHOWSELLER_H
