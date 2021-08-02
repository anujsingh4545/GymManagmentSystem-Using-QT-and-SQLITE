#include "signupdialog.h"
#include "ui_signupdialog.h"
#include"logindialog.h"
#include"moreabout.h"
#include"home.h"
#include"reset.h"
#include"terms.h"
signupDialog::signupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signupDialog)
{
    ui->setupUi(this);
    this->setFixedSize(1400,800);
//    ui->label_2->setAlignment(Qt::AlignHCenter);
//    ui->label_3->setAlignment(Qt::AlignHCenter);
    ui->label_8->setAlignment(Qt::AlignHCenter);
    ui->lineEdit_2->setPlaceholderText("Username");
    ui->lineEdit->setPlaceholderText("Password");
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("c:/sqlite/login.db");
    if(!mydb.open())
        ui->label_8->setText("Database failed connection");
    else
        ui->label_8->setText("Database connected...!");

}
signupDialog::~signupDialog()
{
    delete ui;
}

void signupDialog::on_pushButton_3_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->label_8->setText("");
    ui->checkBox->isCheckable();
}
QString username,password;
void signupDialog::on_pushButton_2_clicked()
{
    bool upper = 0,space =false, upper1 = false, lower = false, number =false;
    QString user = ui->lineEdit_2->text();
    for(int i=0;i<user.length();i++){
        if(user[i]>=65 && user[i]<=90){
            upper = 1;
        }
    }

    QString user1 = ui->lineEdit_2->text();
            for(int i=0;i<user.length();i++){
                if(user[i] == ' '){
                    space = true;
                }
           }

    QString user2 = ui->lineEdit->text();
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
    if(ui->lineEdit_2->text()==0)
    {
        ui->label_8->setText("Please Enter Username...!");
    }
    else if(upper==1){
       ui->label_8->setText("Username don't contain upper case letters...!");
        }

    else if(space==true){
       ui->label_8->setText("Username don't contain spaces...!");
        }
    else if(ui->lineEdit->text()==0)
    {
        ui->label_8->setText("Please Enter Password...!");
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
    else if(ui->checkBox->isChecked()==0){
         ui->label_8->setText("Please Accept our T&C...!");
    }
    else{

        username = ui->lineEdit_2->text();
        QString strPw = ui->lineEdit->text();
        QByteArray baPw = strPw.toUtf8();
        for (int i = 0;i<baPw.size();i++)
        {
                 baPw [i] = baPw [i] + 2;
        }
        strPw = baPw;
        password = strPw;
        if(!mydb.isOpen()){
            qDebug()<<"Database failed...!";
            return;
        }
        QSqlQuery qry;
        if(qry.exec("select * from login where username = '"+username+"'and password = '"+password+"'")){
            int count =0;
            while(qry.next()){
                count++;
            }
            if(count==1){
                ui->label_8->setText("Signed in sucessfully..!");
                this->destroy();
                this->hide();
                home Home;
                Home.setModal(true);
                Home.exec();
            }
            if(count<1){
                ui->label_8->setText("Username or password not correct...!");
            }
        }
    }
}

void signupDialog::on_pushButton_4_clicked()
{
    this->destroy(true);
        this->hide();
        moreAbout moreabout;
        moreabout.setModal(true);
        moreabout.exec();
}



QString signupDialog::pass_value(){
return username;
}

void signupDialog::on_pushButton_7_clicked()
{
    class terms ter;
    ter.setModal(true);
    ter.exec();
}


void signupDialog::on_pushButton_8_clicked()
{
    this->destroy();
    this->hide();
    signupDialog sign;
    sign.setModal(true);
    sign.exec();
}


void signupDialog::on_pushButton_clicked()
{this->destroy(true);
        this->hide();
       LoginDialog logindialog;
       logindialog.setModal(true);
       logindialog.exec();

}


void signupDialog::on_pushButton_9_clicked()
{
    class reset res;
    res.setModal(true);
    res.exec();
}


void signupDialog::on_pushButton_6_clicked()
{
    if(ui->lineEdit->echoMode()){
        ui->lineEdit->setEchoMode(QLineEdit::Normal);
    }
    else{
       ui->lineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    }

}

