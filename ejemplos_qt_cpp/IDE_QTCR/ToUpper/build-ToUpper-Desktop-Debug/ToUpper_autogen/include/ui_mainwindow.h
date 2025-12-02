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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *textLabel;
    QLineEdit *userInput;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *outLabel;
    QLineEdit *outText;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(382, 289);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(102, 201, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("logo eci.png")));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textLabel = new QLabel(centralwidget);
        textLabel->setObjectName(QString::fromUtf8("textLabel"));

        horizontalLayout->addWidget(textLabel);

        userInput = new QLineEdit(centralwidget);
        userInput->setObjectName(QString::fromUtf8("userInput"));

        horizontalLayout->addWidget(userInput);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 255, 83);\n"
"background-color: rgb(23, 38, 66);"));

        verticalLayout->addWidget(pushButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        outLabel = new QLabel(centralwidget);
        outLabel->setObjectName(QString::fromUtf8("outLabel"));

        horizontalLayout_2->addWidget(outLabel);

        outText = new QLineEdit(centralwidget);
        outText->setObjectName(QString::fromUtf8("outText"));
        outText->setEchoMode(QLineEdit::Normal);

        horizontalLayout_2->addWidget(outText);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 382, 20));
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
        label->setText(QString());
        textLabel->setText(QCoreApplication::translate("MainWindow", "Texto:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Pasar m\303\241yusculas", nullptr));
        outLabel->setText(QCoreApplication::translate("MainWindow", "Resultado", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
