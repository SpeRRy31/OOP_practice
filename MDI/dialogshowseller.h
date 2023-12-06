#ifndef DIALOGSHOWSELLER_H
#define DIALOGSHOWSELLER_H

#include <QDialog>

#include "Seller.h"

namespace Ui {
class DialogShowSeller;
}

class DialogShowSeller : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShowSeller(QWidget *parent = nullptr);
    ~DialogShowSeller();

public slots:
    void on_createdSeller(Seller *seller);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogShowSeller *ui;
};

#endif // DIALOGSHOWSELLER_H
