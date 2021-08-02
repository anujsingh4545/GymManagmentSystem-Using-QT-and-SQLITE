#ifndef MOREABOUT_H
#define MOREABOUT_H

#include <QDialog>

namespace Ui {
class moreAbout;
}

class moreAbout : public QDialog
{
    Q_OBJECT

public:
    explicit moreAbout(QWidget *parent = nullptr);
    ~moreAbout();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::moreAbout *ui;
};

#endif // MOREABOUT_H
