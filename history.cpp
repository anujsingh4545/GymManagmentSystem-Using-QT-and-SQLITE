#include "history.h"
#include "ui_history.h"

History::History(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
    this->setFixedSize(1200,800);
}

History::~History()
{
    delete ui;
}
