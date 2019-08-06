#include "myoptionsdialog.h"
#include "ui_myoptionsdialog.h"
#include "mystandarditemmodel.h"

namespace Gordon
{
    MyOptionsDialog::MyOptionsDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::MyOptionsDialog)
    {
        QStringList headers = { "Name", "Value" };

        ui->setupUi(this);

        _myDelegate = new MyDelegate(this);
        _model = new MyStandardItemModel(4, 2, this);

        _model->setHorizontalHeaderLabels(headers);

        for(int row = 0; row < 3; row++)
        {
            _model->setData(_model->index(row, 0, QModelIndex()), "Test");
            _model->setData(_model->index(row, 1, QModelIndex()), 0);
        }

        _model->setData(_model->index(3, 0, QModelIndex()), "Colour");
        _model->setData(_model->index(3, 1, QModelIndex()), QColor(Qt::red).name(), Qt::DisplayRole);
        _model->setData(_model->index(3, 1, QModelIndex()), QColor(Qt::red), Qt::EditRole);
        _model->setData(_model->index(3, 1, QModelIndex()), QColor(Qt::red), Qt::DecorationRole);

        ui->tableView->setModel(_model);
        ui->tableView->verticalHeader()->hide();
        ui->tableView->setItemDelegate(_myDelegate);
    }

    MyOptionsDialog::~MyOptionsDialog()
    {
        delete ui;
    }
}
