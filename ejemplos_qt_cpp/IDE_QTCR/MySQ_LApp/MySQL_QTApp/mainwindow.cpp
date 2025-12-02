#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(nullptr)
{
    ui->setupUi(this);
    connect(ui->btnRunQuery, &QPushButton::clicked, this, &MainWindow::on_btnRunQuery_clicked);
    connectToMySQL();
    populateTables();
}

MainWindow::~MainWindow() {
    delete ui;
    if (model) delete model;
    if (db.isOpen()) db.close();
}

void MainWindow::connectToMySQL() {
    qDebug() << "Available drivers:" << QSqlDatabase::drivers();

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("sakila");
    db.setUserName("dsps");
    db.setPassword("P4ssw0rd_1234");
    /*
QPushButton{background-color: rgb(96, 157, 255);}
QTextEdit{background-color: rgb(255, 157, 96);}
QComboBox#comboTables{color: rgb(255, 157, 96);}
*/

    if (!db.open()) {
        QMessageBox::critical(this, "Error de conexión", db.lastError().text());
    }
}

void MainWindow::populateTables() {
    if (!db.isOpen()) return;

    QSqlQuery query("SHOW TABLES");
    while (query.next()) {
        ui->comboTables->addItem(query.value(0).toString());
    }
}

void MainWindow::on_comboTables_currentTextChanged(const QString &tableName) {
    if (model) delete model;

    model = new QSqlQueryModel(this);
    model->setQuery("SELECT * FROM " + tableName, db);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}
void MainWindow::on_btnRunQuery_clicked() {
    if (!db.isOpen()) {
        ui->txtQueryOutput->setPlainText("Database not connected.");
        return;
    }

    QSqlQuery query(db);
    // Example: top 5 most rented films from sakila
    QString sql = R"(
        SELECT f.title, COUNT(*) as rentals
        FROM rental r
        JOIN inventory i ON r.inventory_id = i.inventory_id
        JOIN film f ON i.film_id = f.film_id
        GROUP BY f.title
        ORDER BY rentals DESC
        LIMIT 5
    )";

    if (!query.exec(sql)) {
        ui->txtQueryOutput->setPlainText("Query failed:\n" + query.lastError().text());
        return;
    }

    QString result;
    while (query.next()) {
        QString title = query.value("title").toString();
        int count = query.value("rentals").toInt();
        result += QString("%1 — %2 rentals\n").arg(title, QString::number(count));
    }

    if (result.isEmpty())
        result = "No results.";

    ui->txtQueryOutput->setPlainText(result);
}

