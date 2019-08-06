#include "treeitemmodel.h"
#include "internaldataitem.h"

TreeItemModel::TreeItemModel(InternalDataItem* rootItem)
{
    _rootItem = rootItem;
}

int TreeItemModel::columnCount(const QModelIndex&) const
{
    return 2;
}

QModelIndex TreeItemModel::index(int row, int column, const QModelIndex& parent) const
{
    QModelIndex result = QModelIndex();

    if (hasIndex(row, column, parent))
    {
        InternalDataItem* parentItem = getParentItem(parent);

        if(parentItem)
        {
            const std::vector<InternalDataItem*>* children = parentItem->children();

            if(children)
            {
                InternalDataItem* childItem = children->at(std::vector<InternalDataItem*>::size_type(row));

                if (childItem)
                {
                    result = createIndex(row, column, childItem);
                }
            }
        }
    }

    return result;
}

QVariant TreeItemModel::data(const QModelIndex& index, int role) const
{
    QVariant result = QVariant();

    if (index.isValid())
    {
        if (role == Qt::DisplayRole)
        {
            InternalDataItem* item = static_cast<InternalDataItem*>(index.internalPointer());

            result = item->data(index.column());
        }
    }

    return result;
}

QModelIndex TreeItemModel::parent(const QModelIndex& index) const
{
    QModelIndex result = QModelIndex();

    if (index.isValid())
    {
        InternalDataItem* childItem = static_cast<InternalDataItem*>(index.internalPointer());

        if(childItem)
        {
            InternalDataItem* parentItem = childItem->parent();

            if (parentItem != _rootItem)
            {
                result =  createIndex(0, 0, parentItem);
            }
        }
    }

    return result;
}

int TreeItemModel::rowCount(const QModelIndex& parent) const
{
    int result = 0;
    InternalDataItem* parentItem = getParentItem(parent);

    if(parentItem)
    {
        const std::vector<InternalDataItem*>* children = parentItem->children();

        if(children)
        {
            result =  int(children->size());
        }
    }

    return result;
}

QVariant TreeItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    QVariant result = QVariant();

    if(role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            result = _rootItem->data(section);
        }
    }

    return result;
}

InternalDataItem* TreeItemModel::getParentItem(const QModelIndex& parent) const
{
    return parent.isValid() ? static_cast<InternalDataItem*>(parent.internalPointer()) : _rootItem;
}
