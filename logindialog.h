#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include <QDialog>
#include<mainwindow.h>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::LoginDialog *ui;
    QSqlDatabase mydb;
};

#endif // LOGINDIALOG_H
