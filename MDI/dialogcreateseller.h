#ifndef DIALOGCREATESELLER_H
#define DIALOGCREATESELLER_H

#include <QDialog>

#include "Seller.h"

namespace Ui {
class DialogCreateSeller;
}

class DialogCreateSeller : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreateSeller(QWidget *parent = nullptr);
    ~DialogCreateSeller();
signals:
    void createdSeller(Seller *seller);
private slots:
    void on_createSellerBtn_clicked();

private:
    Ui::DialogCreateSeller *ui;
    Seller *seller;
};

#endif // DIALOGCREATESELLER_H
