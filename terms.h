#ifndef TERMS_H
#define TERMS_H

#include <QDialog>

namespace Ui {
class terms;
}

class terms : public QDialog
{
    Q_OBJECT

public:
    explicit terms(QWidget *parent = nullptr);
    ~terms();

private:
    Ui::terms *ui;
};

#endif // TERMS_H
