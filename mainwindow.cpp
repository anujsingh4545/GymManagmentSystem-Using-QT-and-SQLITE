#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"logindialog.h"
#include"signupdialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1400,800);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_1_clicked()
{
    this->destroy();
    hide();
    LoginDialog logindialog;
    logindialog.setModal(true);
    logindialog.exec();

}
void MainWindow::on_pushButton_2_clicked()
{
    this-> hide();
   signupDialog signupdialog;
   signupdialog.setModal(true);
   signupdialog.exec();
}


