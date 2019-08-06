#ifndef MYOPTIONSDIALOG_H
#define MYOPTIONSDIALOG_H

#include <QDialog>

namespace Ui {
class MyOptionsDialog;
}

class MyOptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyOptionsDialog(QWidget *parent = nullptr);
    ~MyOptionsDialog();

private:
    Ui::MyOptionsDialog *ui;
};

#endif // MYOPTIONSDIALOG_H
