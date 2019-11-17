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

bool WidgetTypeCollection::forEach(ForEachFn forEach)
{
    bool result = false;

    if(forEach)
    {
        for(auto t : _types)
        {
            if(t)
            {
                forEach(t);
            }
        }

        result = true;
    }

    return result;
}
