#include "logindialog.h"
#include "ui_logindialog.h"
#include"mainwindow.h"
#include"signupdialog.h"
#include"moreabout.h"
#include<QMessageBox>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setFixedSize(1400,800);
    ui->label_8->setAlignment(Qt::AlignHCenter);
    ui->lineEdit->setPlaceholderText("Name");
    ui->lineEdit_2->setPlaceholderText("Contact Number");
    ui->lineEdit_4->setPlaceholderText("Username ");
    ui->lineEdit_5->setPlaceholderText("Password");
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("c:/sqlite/login.db");
    if(!mydb.open())
        ui->label_8->setText("Database failed connection");
    else
        ui->label_8->setText("Database connected...!");

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_2_clicked()
{
 ui->lineEdit->setText("");
 ui->lineEdit_2->setText("");
 ui->lineEdit_4->setText("");
 ui->lineEdit_5->setText("");
 ui->label_8->setText("");
}
void LoginDialog::on_pushButton_clicked()
{
    QSqlQuery qry,qry1,qry2;
    QString name,phone,username,password,gender;
    name = ui->lineEdit->text();
    phone=ui->lineEdit_2->text();
    username=ui->lineEdit_4->text();
    bool upper = 0,space =false, upper1 = false, lower = false, number =false;
    QString strPw = ui->lineEdit_5->text();

    QByteArray baPw = strPw.toUtf8();
    for (int i = 0;i<baPw.size();i++)
    {
             baPw [i] = baPw [i] + 2;
    }
    strPw = baPw;
    password = strPw;

    gender= ui->comboBox->currentText();


    QString user = ui->lineEdit_4->text();
    for(int i=0;i<user.length();i++){
        if(user[i]>=65 && user[i]<=90){
            upper = 1;
        }
    }

    QString user1 = ui->lineEdit_4->text();
            for(int i=0;i<user.length();i++){
                if(user[i] == ' '){
                    space = true;
                }
           }

    QString user2 = ui->lineEdit_5->text();
            for(int i=0;i<user2.length();i++){
                 if(user2[i]>=65 && user2[i]<=90 ){
                     upper1 = true;
                  }
            }


                    for(int i=0;i<user2.length();i++){
                         if(user2[i]>=97 && user2[i]<=122 ){
                             lower = true;
                          }
                    }

                            for(int i=0;i<user2.length();i++){
                                 if(user2[i]>=48 && user2[i]<=57 ){
                                     number = true;
                                  }
                            }
    bool ok;
    QString str = ui->lineEdit_2->text();
    quint64 no = str.toLongLong(&ok,10);

    if(ui->lineEdit->text()==0)
   {
        ui->label_8->setText("Please Enter Name...!");
    }
    else if(no<=1000000000 ){
       ui->label_8->setText("Please Enter your phone number...!");
     }
   else if(no>=10000000000){
       ui->label_8->setText("Your phone number is too long...!");
      }

    else if(ui->lineEdit_4->text()==0)
    {
       ui->label_8->setText("Please Enter Your Username...!");
   } 
    else if(upper==1){
       ui->label_8->setText("Username don't contain upper case letters...!");
        }

    else if(space==true){
       ui->label_8->setText("Username don't contain spaces...!");
        }

    else if(ui->lineEdit_5->text()==0)
    {
        ui->label_8->setText("Please Enter Your Password...!");
    }
    else if(user2.length()<5){
       ui->label_8->setText("Password should contain atleast 5 characters...!");
        }
    else if(upper1==0){
       ui->label_8->setText("Password should contain atleast one upper case character...!");
        }
    else if(lower==0){
       ui->label_8->setText("Password should contain atleast one lower case character...!");
        }
   else if(number==0){
      ui->label_8->setText("Password should contain atleast one number...!");
   }

    else{
        if(!mydb.isOpen()){
            qDebug()<<"Database failed ";
        }
         if(qry1.exec("select * from login where username = '"+username+"'")){
            int count =0;
            while(qry1.next()){
                count++;
                }
            if(count==1){
                ui->label_8->setText("Username already exists..!");
            }
            if(count<1){
                if(qry.exec("insert into login (name,gender,phone,username,password)values('"+name+"','"+gender+"','"+phone+"','"+username+"','"+password+"')")){
                  ui->label_8->setText("Data entered move to login page...!");
               }
            }
        }
  }
}
void LoginDialog::on_pushButton_3_clicked()
{  this->destroy(true);
    hide();
    signupDialog signupdialog;
    signupdialog.setModal(true);
    signupdialog.exec();
}

void LoginDialog::on_pushButton_4_clicked()
{
  this->destroy(true);
   hide();
   moreAbout moreabout;
   moreabout.setModal(true);
  moreabout.exec();
}



void LoginDialog::on_pushButton_6_clicked()
{ if(ui->lineEdit_5->echoMode()){
        ui->lineEdit_5->setEchoMode(QLineEdit::Normal);
    }
    else{
       ui->lineEdit_5->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    }

}

