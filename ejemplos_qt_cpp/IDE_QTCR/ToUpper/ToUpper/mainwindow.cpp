#include "mainwindow.h"
#include "./ui_mainwindow.h"

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
    QString texto=ui->userInput->text();
    ui->outText->setText(texto.toUpper());
}


void MainWindow::on_userInput_textChanged(const QString &arg1)
{

}

