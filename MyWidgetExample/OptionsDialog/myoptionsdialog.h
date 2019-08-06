#ifndef MYOPTIONSDIALOG_H
#define MYOPTIONSDIALOG_H

#include "mydelegate.h"

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class MyOptionsDialog;
}

namespace Gordon
{
    class MyOptionsDialog : public QDialog
    {
        Q_OBJECT

    public:
        explicit MyOptionsDialog(QWidget* parent = nullptr);
        ~MyOptionsDialog();

    private:
        Ui::MyOptionsDialog* ui;

        QStandardItemModel* _model;
        MyDelegate* _myDelegate;
    };
}

#endif // MYOPTIONSDIALOG_H
