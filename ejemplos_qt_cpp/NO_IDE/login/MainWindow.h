#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QPushButton;
class QCheckBox;
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoginClicked();
    void onInputChanged();

private:
    QLabel *labelUser;
    QLabel *labelPassword;
    QLineEdit *editUser;
    QLineEdit *editPassword;
    QCheckBox *checkRemember;
    QPushButton *buttonLogin;
    QLabel *labelMessage;

    void setupUI();
    void setupConnections();
};

#endif // MAINWINDOW_H
