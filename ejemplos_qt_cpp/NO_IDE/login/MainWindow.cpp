#include "MainWindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setupUI();
    setupConnections();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI() {
    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    labelUser = new QLabel("Usuario:", this);
    editUser = new QLineEdit(this);
    labelPassword = new QLabel("Contraseña:", this);
    editPassword = new QLineEdit(this);
    editPassword->setEchoMode(QLineEdit::Password);
    checkRemember = new QCheckBox("Recordarme", this);
    buttonLogin = new QPushButton("Iniciar Sesión", this);
    buttonLogin->setEnabled(false);
    labelMessage = new QLabel("", this);
    editPassword->setStyleSheet("background-color : blue");

    layout->addWidget(labelUser);
    layout->addWidget(editUser);
    layout->addWidget(labelPassword);
    layout->addWidget(editPassword);
    layout->addWidget(checkRemember);
    layout->addWidget(buttonLogin);
    layout->addWidget(labelMessage);

    setCentralWidget(central);
    setWindowTitle("Login Qt");
    resize(300, 250);
}

void MainWindow::setupConnections() {
    connect(buttonLogin, &QPushButton::clicked, this, &MainWindow::onLoginClicked);
    connect(editUser, &QLineEdit::textChanged, this, &MainWindow::onInputChanged);
    connect(editPassword, &QLineEdit::textChanged, this, &MainWindow::onInputChanged);
}

void MainWindow::onLoginClicked() {
    QString user = editUser->text();
    QString password = editPassword->text();
    if (user == "admin" && password == "1234")
        labelMessage->setText("\u00a1Login exitoso!");
    else
        labelMessage->setText("Usuario o contraseña incorrectos.");
}

void MainWindow::onInputChanged() {
    bool enable = !editUser->text().isEmpty() && !editPassword->text().isEmpty();
    buttonLogin->setEnabled(enable);
}
