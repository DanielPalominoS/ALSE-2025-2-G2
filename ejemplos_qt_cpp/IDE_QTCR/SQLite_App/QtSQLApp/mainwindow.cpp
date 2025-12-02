#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(nullptr)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/dsps/QT/2025-1/SQLite_App/QtSQLApp/products.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
    } else {
        QMessageBox::information(this, "Database", "Connected to SQLite database.");
    }
    qDebug() << "Connected to DB?" << db.isOpen();
    QSqlQuery query("SELECT * FROM products");
    while (query.next()) {
        qDebug() << "Found table:" << query.value(0).toString()<<" "<<query.value(1).toString()<<" "<<query.value(2).toString()<<" ";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    if (model) delete model;
    if (db.isOpen()) db.close();
}


void MainWindow::on_loadButton_clicked()
{
//    if (model) delete model;
//    model = new QSqlTableModel(this, db);
//    model->setTable("products");
//    model->select();
//    ui->tableView->setModel(model);
    QMessageBox::information(this, "Debug", "Button clicked");

    if (!db.isOpen()) {
        QMessageBox::warning(this, "Database", "Not connected");
        return;
    }

    if (model) delete model;
    model = new QSqlTableModel(this, db);
    model->setTable("products");

    if (!model->select()) {
        QMessageBox::critical(this, "SQL Error", model->lastError().text());
    }

    ui->tableView->setModel(model);
}

