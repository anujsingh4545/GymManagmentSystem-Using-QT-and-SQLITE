#include "reset.h"
#include "ui_reset.h"

reset::reset(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reset)
{
    ui->setupUi(this);
    this->setFixedSize(600,600);
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_4->setAlignment(Qt::AlignCenter);
    ui->lineEdit->setPlaceholderText("Username");
    ui->lineEdit_2->setPlaceholderText("Phone Number");
     ui->lineEdit_3->setPlaceholderText("New Password");
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("c:/sqlite/login.db");
    if(!mydb.open())
        ui->label_3->setText("Database failed connection");
    else
        ui->label_3->setText("Database connected...!");


}

reset::~reset()
{
    delete ui;
}

void reset::on_pushButton_2_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->label_3->setText("");
}


void reset::on_pushButton_clicked()
{
    QString phone,username;
    username=ui->lineEdit->text();
    phone=ui->lineEdit_2->text();
    if(!mydb.isOpen()){
        qDebug()<<"Database failed...!";
        return;
    }
    QSqlQuery qry;
    if(qry.exec("select * from login where username = '"+username+"'and phone = '"+phone+"'")){
        int count =0;
        while(qry.next()){
            count++;
        }
        if(count==1){
            qry.first();
                    QString name = qry.value(4).toString();
                    QByteArray baPw = name.toUtf8();
                    for (int i = 0;i<name.size();i++)
                    {
                             baPw [i] = baPw [i] - 2;
                    }
                    name = baPw;

            ui->label_3->setText("Your password is : "+name);
        }
        if(count<1){
            ui->label_3->setText("Username or phone number is not correct !");
        }
    }

}

void reset::on_pushButton_4_clicked()
{
    ui->lineEdit_3->setText("");
    ui->label_4->setText("");
}

void reset::on_pushButton_3_clicked()
{
    QString phone,username;
    username=ui->lineEdit->text();
    phone=ui->lineEdit_2->text();
    if(!mydb.isOpen()){
        qDebug()<<"Database failed...!";
        return;
    }

    QSqlQuery qry;
    if(qry.exec("select * from login where username = '"+username+"'and phone = '"+phone+"'")){
        int count =0;
        while(qry.next()){
            count++;
        }
        if(count==1){

            QString pass1 = ui->lineEdit_3->text();
            QString pass;
            QByteArray baPw = pass1.toUtf8();
            for (int i = 0;i<baPw.size();i++)
            {
                     baPw [i] = baPw [i] + 2;
            }
            pass1 = baPw;
            pass = pass1;
            qry.prepare( "update login set password = '"+pass+"' where username = '"+username+"'and phone = '"+phone+"'");
              if( qry.exec())
                ui->label_4->setText("Updated sucessfully..!");
              else
                ui->label_4->setText("Not updated..!");

        }
        if(count<1){
            ui->label_4->setText("Username or phone number is not correct !");
        }
    }
}

