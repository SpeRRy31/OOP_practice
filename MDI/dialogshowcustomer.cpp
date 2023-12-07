#include "dialogshowcustomer.h"
#include "ui_dialogshowcustomer.h"

DialogShowCustomer::DialogShowCustomer(DBManager* dbManager, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogShowCustomer), dbManager(dbManager)
{
    if (!dbManager) {
        qDebug() << "Неправильний вказівник DBManager у конструкторі DialogPrintSong";
        // Обробте помилку, можливо, закрийте діалогове вікно або покажіть повідомлення про помилку
        // в залежності від логіки вашого додатка.
        return;
    }

    ui->setupUi(this);

    this->setupModel(TABLE_CUSTOMER ,
                     QStringList() << tr("id")
                                   << tr("firstname")
                                   << tr("secondname")
                                   << tr("thirdname")
                                   << tr("address")
                                   << tr("number_card")
                                   << tr("balance")
                     );

    model->select();
    this->createUI();
}

void DialogShowCustomer::setupModel(const QString& tableName, const QStringList& headers) {
    /* Виконуємо ініціалізацію моделі представлення даних
     * з вказанням імені таблиці в базі даних, до якої
     * буде виконуватись звернення
     * */
    model = new QSqlTableModel(this, dbManager->getDB());
    model->setTable(tableName);

    // Встановлюємо назви стовпців в таблиці із сортуванням даних
    for (int i = 0, j = 0; i < model->columnCount(); i++, j++) {
        model->setHeaderData(i, Qt::Horizontal, headers[j]);
    }
    // Встановлюємо сортування по збільшення даних по нульовому стовпцю
    model->setSort(0, Qt::AscendingOrder);
}

void DialogShowCustomer::createUI() {
    ui->tableView->setModel(model);     // Встановлюємо модель на TableView
    ui->tableView->setColumnHidden(0, true);    // Приховуємо колонку з  id записів таблиці БД
    // Дозволяємо виділення рядків
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Встановлюємо режим виділення лише одного рядка в таблиці
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Встановлюємо розмір колонок по вмісту
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ; // Виконуємо вибірку даних із таблиці
}

DialogShowCustomer::~DialogShowCustomer()
{
    delete ui;

    if (model)
        delete model;
}

void DialogShowCustomer::on_createCustomer(Customer *customer)
{
    if (!dbManager->inserIntoCustomerTable(*customer)) {
        qDebug() << "Error inserting data into the database.";}

    model->select();
}

void DialogShowCustomer::on_pushButton_clicked()
{
    this->close();
}

