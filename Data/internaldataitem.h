#ifndef INTERNALDATAITEM_H
#define INTERNALDATAITEM_H

#include <string>
#include <vector>

#include <QVariant>

class InternalDataItem
{
    QString _name;
    QString _id;

    InternalDataItem* _parent;
    std::vector<InternalDataItem*>* _children;
public:
    InternalDataItem(const QString& name, const QString& id, InternalDataItem* parent);

    QVariant data(int col);

    InternalDataItem* parent();
    const std::vector<InternalDataItem*>* children();

    InternalDataItem* addChild(InternalDataItem* child);
};

#endif // INTERNALDATAITEM_H
