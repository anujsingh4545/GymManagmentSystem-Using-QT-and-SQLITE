#include "home.h"
#include "ui_home.h"
#include"signupdialog.h"
#include"register.h"
#include"checkhistory.h"
home::home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
    this->setFixedSize(1400,800);
    ui->label_3->setAlignment(Qt::AlignCenter);
     signupDialog get;
     QString get1 = get.pass_value();
     ui->label_5->setText(get1);
}


home::~home()
{
    delete ui;
}

void home::on_pushButton_clicked()
{
  this->destroy();
    this->hide();
    sign.setModal(true);
    sign.exec();
}

void home::on_pushButton_3_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->label_3->setText("");
}

void home::on_pushButton_2_clicked()
{

    if(ui->lineEdit->text()==0){
        ui->label_3->setText("Enter your weight...!");
    }
    else if(ui->lineEdit_2->text()==0){
        ui->label_3->setText("Enter your height...!");
    }
    else{
    QString str = ui->lineEdit->text();
    float a = str.toFloat();
    QString string = ui->lineEdit_2->text();
    float b = string.toFloat();
    float c = a/(b*b);
    QString output = QString::number(c,'f',3);
    if(c<=18.5){
        ui->label_3->setText("BMI : "+ output+" -> Category : Underweight" );
    }
    else if(c>=18.5 && c<=24.9){
        ui->label_3->setText("BMI : "+ output+" -> Category : Normal Weight" );
    }
    else if(c>=25 && c<=29.9){
        ui->label_3->setText("BMI : "+ output+" -> Category : Overweight" );
    }
    else if(c>30){
        ui->label_3->setText("BMI : "+ output+" -> Category : Obesity" );
    }
    }
}

void home::on_pushButton_6_clicked()
{
    this->destroy();
    this->hide();
   Register reg;
   reg.setModal(true);
   reg.exec();
}


void home::on_pushButton_7_clicked()
{
    this->destroy();
    this->hide();
   class checkHistory check;
   check.setModal(true);
   check.exec();

}

