#ifndef MYSTANDARDITEMMODEL_H
#define MYSTANDARDITEMMODEL_H

#include <QObject>
#include <QStandardItemModel>

namespace Gordon
{
    class MyStandardItemModel : public QStandardItemModel
    {
    public:

        MyStandardItemModel(QObject* parent = nullptr);
        MyStandardItemModel(int rows, int columns, QObject* parent = nullptr);

        Qt::ItemFlags flags(const QModelIndex& index) const;
    };
}

#endif // MYSTANDARDITEMMODEL_H
