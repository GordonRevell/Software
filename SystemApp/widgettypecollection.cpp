#include "widgettypecollection.h"

WidgetTypeCollection::WidgetTypeCollection(QObject *parent) : QObject(parent)
{
}

WidgetTypeCollection::~WidgetTypeCollection()
{
}

bool WidgetTypeCollection::add(WidgetType* type)
{
    bool result = false;

    if(type)
    {
        _types.push_back(type);

        result = true;
    }

    return result;
}
