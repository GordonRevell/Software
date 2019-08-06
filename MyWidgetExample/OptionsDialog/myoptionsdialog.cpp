#include "myoptionsdialog.h"
#include "ui_myoptionsdialog.h"

MyOptionsDialog::MyOptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyOptionsDialog)
{
    ui->setupUi(this);
}

MyOptionsDialog::~MyOptionsDialog()
{
    delete ui;
}
