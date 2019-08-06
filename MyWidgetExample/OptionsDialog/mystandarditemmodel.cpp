#include "mystandarditemmodel.h"

namespace Gordon
{
    MyStandardItemModel::MyStandardItemModel(QObject* parent) : QStandardItemModel(parent)
    {
    }

    MyStandardItemModel::MyStandardItemModel(int rows, int columns, QObject* parent) : QStandardItemModel(rows, columns, parent)
    {
    }

    Qt::ItemFlags MyStandardItemModel::flags(const QModelIndex& index) const
    {
        auto flags = QStandardItemModel::flags(index);

        if(index.column() == 0)
        {
            flags &= ~Qt::ItemIsEditable;
        }
        else
        {
            flags |= Qt::ItemIsEditable;
        }

        return flags;
    }
}
