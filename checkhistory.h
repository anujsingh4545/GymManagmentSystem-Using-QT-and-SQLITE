#ifndef CHECKHISTORY_H
#define CHECKHISTORY_H

#include <QDialog>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

namespace Ui {
class checkHistory;
}

class checkHistory : public QDialog
{
    Q_OBJECT

public:
    explicit checkHistory(QWidget *parent = nullptr);
    ~checkHistory();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::checkHistory *ui;
    QSqlDatabase mydb;
};

#endif // CHECKHISTORY_H
