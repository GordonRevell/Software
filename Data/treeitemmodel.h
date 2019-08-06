#ifndef TREEITEMMODEL_H
#define TREEITEMMODEL_H

#include "internaldataitem.h"

#include <QAbstractItemModel>

class TreeItemModel : public QAbstractItemModel
{
    InternalDataItem* _rootItem = nullptr;

public:
    explicit TreeItemModel(InternalDataItem* rootItem);

    int columnCount(const QModelIndex&) const override;
    QModelIndex index(int row, int column, const QModelIndex& parent) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QModelIndex parent(const QModelIndex& index) const override;
    int rowCount(const QModelIndex& parent) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
private:
    InternalDataItem* getParentItem(const QModelIndex& parent) const;
};

#endif // TREEITEMMODEL_H
