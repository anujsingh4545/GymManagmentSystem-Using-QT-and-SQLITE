#include "terms.h"
#include "ui_terms.h"

terms::terms(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::terms)
{
    ui->setupUi(this);
    this->setFixedSize(600,600);
}

terms::~terms()
{
    delete ui;
}
