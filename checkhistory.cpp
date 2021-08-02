#include "checkhistory.h"
#include "ui_checkhistory.h"
#include"home.h"
#include<qmessagebox.h>
checkHistory::checkHistory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkHistory)
{
    ui->setupUi(this);
    this->setFixedSize(1400,800);
   ui->label_3->setAlignment(Qt::AlignCenter);


   mydb = QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("c:/sqlite/details.db");
   if(!mydb.open())
       ui->label_3->setText("Database failed connection");
   else
       ui->label_3->setText("Database connected...!");

}
checkHistory::~checkHistory()
{
    delete ui;
}

void checkHistory::on_pushButton_clicked()
{
    this->destroy();
    this->hide();
    class home ho;
    ho.setModal(true);
    ho.exec();
}


void checkHistory::on_pushButton_2_clicked()
{
    this->destroy();
    this->hide();
    checkHistory check;
    check.setModal(true);
    check.exec();
}


void checkHistory::on_pushButton_7_clicked()
{
    ui->lineEdit_2->setText("");
    ui->label_3->setText("");
    ui->label_17->setText("");
    ui->label_18->setText("");
    ui->label_19->setText("");
    ui->label_20->setText("");
    ui->label_21->setText("");
    ui->label_22->setText("");
}

bool check=false;
void checkHistory::on_pushButton_6_clicked()
{
    bool ok;
    QString str = ui->lineEdit_2->text();
    quint64 no = str.toLongLong(&ok,10);

    if(no<=1000000000 ){
       ui->label_3->setText("Enter phone number correctly !");
     }
   else if(no>=10000000000){
       ui->label_3->setText("Your phone number is to long !");
      }
  else{
        QSqlQuery qry;
    QString phone;
    phone=ui->lineEdit_2->text();
    if(!mydb.isOpen()){
        qDebug()<<"Database failed...!";
        return;
    }

    if(qry.exec("select * from details where phone = '"+phone+"'")){
        int count =0;
        while(qry.next()){
            count++;
        }
        if(count==1){
            qry.first();
                    QString name = qry.value(0).toString();
                    QString gender = qry.value(1).toString();
                    QString age = qry.value(2).toString();
                    QString phone = qry.value(3).toString();
                    QString membership = qry.value(4).toString();
                    QString timing = qry.value(5).toString();
            ui->label_17->setText(name);
            ui->label_18->setText(gender);
            ui->label_19->setText(age);
            ui->label_20->setText(phone);
            ui->label_21->setText(membership);
            ui->label_22->setText(timing);
            check=true;
            ui->label_3->setText("Fetched data sucessfully...!");
        }
        if(count<1){
            ui->label_3->setText("phone number didn,t found !");
        }
    }
   }
}


void checkHistory::on_pushButton_14_clicked()
{
    QMessageBox mess;

    if(check ==false){
       mess.setText("Enter Phone Number correctly...!");
       mess.setWindowTitle("WARNING");
       mess.setIcon(QMessageBox::Warning);
       mess.exec();
     }
   else if(check ==true){
        QSqlQuery qry1;
        QString phone;
        phone=ui->lineEdit_2->text();
        qry1.prepare( "delete from details where phone = '"+phone+"'");
          if( qry1.exec()){
              mess.setText("Form deleted sucessfully...!");
              mess.setWindowTitle("INFO");
              mess.setIcon(QMessageBox::Information);
              mess.exec();}
          else{
              mess.setText("Please try again...!");
              mess.setWindowTitle("WARNING");
              mess.setIcon(QMessageBox::Warning);
              mess.exec();
          }

      }


}

