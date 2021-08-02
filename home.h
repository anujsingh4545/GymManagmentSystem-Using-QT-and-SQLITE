#ifndef HOME_H
#define HOME_H

#include <QDialog>
#include<signupdialog.h>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
namespace Ui {
class home;
}

class home : public QDialog
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    ~home();
    signupDialog sign;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::home *ui;
    QSqlDatabase mydb;
};

#endif // HOME_H
