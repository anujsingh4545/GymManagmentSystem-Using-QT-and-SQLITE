#ifndef REGISTER_H
#define REGISTER_H
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();


private:
    Ui::Register *ui;
    QSqlDatabase myd;
};

#endif // REGISTER_H
