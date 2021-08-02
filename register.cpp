#include "register.h"
#include "ui_register.h"
#include"home.h"
#include<QMessageBox>
#include<mail.h>
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    Register::setWindowOpacity(100);

    this->setFixedSize(1400,800);
     ui->label->setWindowFlags(Qt::FramelessWindowHint);
     ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_7->setAlignment(Qt::AlignCenter);
    myd = QSqlDatabase::addDatabase("QSQLITE");
    myd.setDatabaseName("c:/sqlite/details.db");
    if(!myd.open())
        ui->label_7->setText("Database failed connection");
    else
        ui->label_7->setText("Database connected...!");
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
  this->destroy();
    this->hide();
  home ho;
  ho.setModal(true);
  ho.exec();
}

void Register::on_pushButton_5_clicked()
{
    ui->lineEdit_4->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->label_7->setText("");
}

void Register::on_pushButton_4_clicked()
{
    QSqlQuery qry,qry1;
    QString name,gender,age,phone,membership,timing;
    name = ui->lineEdit_4->text();
    gender = ui->comboBox_6->currentText();
    age = ui->lineEdit_6->text();
    phone = ui->lineEdit_7->text();
    membership = ui->comboBox_4->currentText();
    timing = ui->comboBox_5->currentText();
    bool ok;
    QString str = ui->lineEdit_7->text();
    quint64 no = str.toLongLong(&ok,10);

    if(ui->lineEdit_4->text()==0)
   {
        ui->label_7->setText("Please Enter Name...!");
    }
   else if(ui->lineEdit_6->text()==0)
   {
        ui->label_7->setText("Please Enter your age...!");
    }
    else if(no<=1000000000 ){
       ui->label_7->setText("Please Enter your phone number...!");
     }
   else if(no>=10000000000){
       ui->label_7->setText("Your phone number is too long...!");
      }
    else{
        if(!myd.isOpen()){
            qDebug()<<"Database failed ";
        }

        if(qry1.exec("select * from details where phone = '"+phone+"'")){
           int count =0;
           while(qry1.next()){
               count++;
               }
           if(count==1){
               ui->label_7->setText("Phone number already exists..!");
           }
           if(count<1){
               if(qry.exec("insert into details (name,gender,age,phone,membership,timing) values ('"+name+"','"+gender+"','"+age+"','"+phone+"','"+membership+"','"+timing+"')")){
                    ui->label_7->setText("Data entered sucessfully...!");
                    QMessageBox msgbox;
                    msgbox.setWindowTitle("INFO");
                    msgbox.setIcon(QMessageBox::Information);
                    msgbox.setText("Thank you , your form has been submitted sucessfully...!");
                    msgbox.exec();
               }
              }
           }

    }
}





