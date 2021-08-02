#include "moreabout.h"
#include "ui_moreabout.h"
#include"signupdialog.h"
moreAbout::moreAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::moreAbout)
{
    ui->setupUi(this);
    this->setFixedSize(1400,800);
    ui->label_2->setAlignment(Qt::AlignHCenter);
    ui->label_3->setAlignment(Qt::AlignHCenter);
    ui->label_4->setAlignment(Qt::AlignHCenter);
    ui->label_4->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label_4->setOpenExternalLinks(true);
    ui->label_4->setTextFormat(Qt::RichText);
    ui->label_4->setText("<a href=\"http://www.facebook.com\">Facebook</a>");
    ui->label_3->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label_3->setOpenExternalLinks(true);
    ui->label_3->setTextFormat(Qt::RichText);
    ui->label_3->setText("<a href=\"http://www.instagram.com\">Instagram</a>");
    ui->label_2->setOpenExternalLinks(true);
    ui->label_2->setTextFormat(Qt::RichText);
    ui->label_2->setText("<a href=\"http://www.youtube.com\">YouTube</a>");

}

moreAbout::~moreAbout()
{
    delete ui;
}

void moreAbout::on_pushButton_clicked()
{
    this->destroy();
    this->hide();
    signupDialog sign;
    sign.setModal(true);
    sign.exec();

}

int next = 1;
void moreAbout::on_pushButton_3_clicked()
{   if(next==5){
        next =0;
    }
    if(next==0){
    ui->label->setStyleSheet("border-top-left-radius:90px;border-bottom-right-radius:90px;background-image: url(:/image/1.PNG)");
    }
    if(next==1){
    ui->label->setStyleSheet("border-top-left-radius:90px;border-bottom-right-radius:90px;background-image: url(:/image/2.PNG)");
    }
    if(next==2){
    ui->label->setStyleSheet("border-top-left-radius:90px;border-bottom-right-radius:90px;background-image: url(:/image/3.PNG)");
    }
    if(next==3){
    ui->label->setStyleSheet("border-top-left-radius:90px;border-bottom-right-radius:90px;background-image: url(:/image/4.PNG)");
    }
    if(next==4){
    ui->label->setStyleSheet("border-top-left-radius:90px;border-bottom-right-radius:90px;background-image: url(:/image/5.PNG)");
    }
    if(next==5){
    ui->label->setStyleSheet("border-top-left-radius:90px;border-bottom-right-radius:90px;background-image: url(:/image/6.PNG)");
    }
    next++;
}


void moreAbout::on_pushButton_2_clicked()
{
    if(next==-1){
            next =5;
        }
        if(next==0){
        ui->label->setStyleSheet("border-top-left-radius:90px;border-bottom-right-radius:90px;background-image: url(:/image/1.PNG)");
        }
        if(next==1){
        ui->label->setStyleSheet("border-top-left-radius:90px;border-bottom-right-radius:90px;background-image: url(:/image/2.PNG)");
        }
        if(next==2){
        ui->label->setStyleSheet("border-top-left-radius:90px;border-bottom-right-radius:90px;background-image: url(:/image/3.PNG)");
        }
        if(next==3){
        ui->label->setStyleSheet("border-top-left-radius:90px;border-bottom-right-radius:90px;background-image: url(:/image/4.PNG)");
        }
        if(next==4){
        ui->label->setStyleSheet("border-top-left-radius:90px;border-bottom-right-radius:90px;background-image: url(:/image/5.PNG)");
        }
        if(next==5){
        ui->label->setStyleSheet("border-top-left-radius:90px;border-bottom-right-radius:90px;background-image: url(:/image/6.PNG)");
        }
        next--;
}

