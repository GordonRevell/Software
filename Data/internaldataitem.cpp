#include "internaldataitem.h"

#include <QString>

InternalDataItem::InternalDataItem(const QString &name, const QString &id, InternalDataItem* parent)
{
    _name = name;
    _id = id;
    _parent = parent;

    _children = new std::vector<InternalDataItem*>();
}

QVariant InternalDataItem::data(int col)
{
    QVariant result = QVariant();

    switch(col)
    {
        case 0:
            result.setValue(_name);
            break;
        case 1:
            result.setValue(_id);
            break;
    }

    return result;
}

InternalDataItem* InternalDataItem::parent()
{
    return _parent;
}

const std::vector<InternalDataItem*>* InternalDataItem::children()
{
    return _children;
}

InternalDataItem* InternalDataItem::addChild(InternalDataItem* child)
{
    _children->push_back(child);

    return child;
}
