#include "localwidget.h"

unsigned int LocalWidget::s_count = 0;
WidgetTypeCollection* LocalWidget::s_widgetTypes = nullptr;
std::vector<LocalWidget*>* LocalWidget::s_widgets = nullptr;

LocalWidget::LocalWidget(QWidget *parent) : QDockWidget(parent)
{
}

LocalWidget::LocalWidget(const LocalWidget&)
{
}

QByteArray LocalWidget::save()
{
    QByteArray result;
    QDataStream out(&result, QIODevice::WriteOnly);

    if(s_widgets)
    {
        out << int(s_widgets->size());

        for(std::vector<LocalWidget*>::iterator it = s_widgets->begin(); it != s_widgets->end(); it++)
        {
            LocalWidget* w = *it;

            if(w)
            {
                std::cout << w->type()->name().toStdString() << " " << w->objectName().toStdString() << std::endl;

                out << w->type()->name();
                out << w->objectName();
            }
        }
    }

    return result;
}

bool LocalWidget::restore(const QByteArray& widgets)
{
    QDataStream in(widgets);
    int numWidgets;

    in >> numWidgets;


    for(int i = 0; i < numWidgets; i++)
    {
        QString type;
        QString objectName;

        in >> type;
        in >> objectName;

        auto widgetType = s_widgetTypes->find(type);

        if(widgetType)
        {
            std::cout << "Restore: " << widgetType->name().toStdString() << std::endl;
        }
    }

    return false;
}

void LocalWidget::closeEvent(QCloseEvent*)
{
    std::vector<LocalWidget*>::iterator i = std::find(s_widgets->begin(), s_widgets->end(), this);

    if (i != s_widgets->end())
    {
        s_widgets->erase(i);
    }
}

WidgetType* LocalWidget::type() const
{
    return _type;
}

void LocalWidget::setType(WidgetType* type)
{
    _type = type;
}
