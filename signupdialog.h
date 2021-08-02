#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

namespace Ui {
class signupDialog;
}

class signupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit signupDialog(QWidget *parent = nullptr);
    ~signupDialog();
    QString pass_value();

private slots:


    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();


    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::signupDialog *ui;
    QSqlDatabase mydb;
};

#endif // SIGNUPDIALOG_H
