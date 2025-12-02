#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <string>

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


void MainWindow::on_pushButton_clicked()
{
    QString text_;//=QString("Hello " + ui->userNameInput->text());
    text_=ui->userNameInput->text();
    QMessageBox::information(this,"MB", QString("Hello "+ text_));
}

