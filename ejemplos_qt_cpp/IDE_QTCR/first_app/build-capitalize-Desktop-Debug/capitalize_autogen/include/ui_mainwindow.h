/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLineEdit *outputEdit;
    QLabel *outputLabel;
    QLabel *inputLabel;
    QLineEdit *userInput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(531, 390);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 190, 80, 23));
        outputEdit = new QLineEdit(centralwidget);
        outputEdit->setObjectName(QString::fromUtf8("outputEdit"));
        outputEdit->setGeometry(QRect(260, 240, 113, 23));
        outputEdit->setReadOnly(true);
        outputLabel = new QLabel(centralwidget);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));
        outputLabel->setGeometry(QRect(150, 250, 70, 15));
        inputLabel = new QLabel(centralwidget);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));
        inputLabel->setGeometry(QRect(150, 90, 59, 78));
        userInput = new QLineEdit(centralwidget);
        userInput->setObjectName(QString::fromUtf8("userInput"));
        userInput->setGeometry(QRect(250, 120, 158, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 531, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Capitalize", nullptr));
        outputLabel->setText(QCoreApplication::translate("MainWindow", "Output text", nullptr));
        inputLabel->setText(QCoreApplication::translate("MainWindow", "Input Text", nullptr));
        userInput->setText(QCoreApplication::translate("MainWindow", "type something", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
