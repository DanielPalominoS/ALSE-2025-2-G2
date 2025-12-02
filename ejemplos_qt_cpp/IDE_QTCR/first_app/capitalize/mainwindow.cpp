#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QString";

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
    QString text;
    text=ui->userInput->text();
    text=text.toUpper();
    ui->outputEdit->setText(text);
}

