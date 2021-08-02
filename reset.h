#ifndef RESET_H
#define RESET_H

#include <QDialog>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

namespace Ui {
class reset;
}

class reset : public QDialog
{
    Q_OBJECT

public:
    explicit reset(QWidget *parent = nullptr);
    ~reset();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::reset *ui;
     QSqlDatabase mydb;
};

#endif // RESET_H
