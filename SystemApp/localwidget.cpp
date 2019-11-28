#include "localwidget.h"

#include <QMainWindow>

LocalWidget::LocalWidget(QWidget *parent) : QDockWidget(parent)
{
}

LocalWidget::LocalWidget(const LocalWidget& w) : QDockWidget()
{
    QWidget* parent = reinterpret_cast<QWidget*>(w.parent());

    setParent(parent);
}

QByteArray LocalWidget::save()
{
    QByteArray result;
    QDataStream out(&result, QIODevice::WriteOnly);

    out << int(s_widgets.size());

    for(LocalWidget* w : s_widgets)
    {
        if(w)
        {
            std::cout << "Save: " << w->type()->name().toStdString() << " " << w->objectName().toStdString() << std::endl;

            out << w->type()->name();
            out << w->objectName();
        }
    }

    return result;
}

bool LocalWidget::restore(const QByteArray& widgets, QMainWindow* mainWindow)
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

        WidgetType* widgetType = nullptr;

        for(auto t : s_types)
        {
            int x = QString::compare(type, t->name(), Qt::CaseInsensitive);

            if(x == 0)
            {
                widgetType = t;

                break;
            }
        }

        if(widgetType)
        {
            std::cout << "Restore: " << widgetType->name().toStdString() << " " << objectName.toStdString() << std::endl;

            QDockWidget* dock = createLocalWidget(widgetType, objectName);

            if(dock)
            {
                mainWindow->addDockWidget(Qt::RightDockWidgetArea, dock);
            }
        }
    }

    return false;
}

void LocalWidget::closeEvent(QCloseEvent*)
{
    std::vector<LocalWidget*>::iterator i = std::find(s_widgets.begin(), s_widgets.end(), this);

    if (i != s_widgets.end())
    {
        std::cout << "Close: " << _type->name().toStdString() << " " << objectName().toStdString() << std::endl;

        s_widgets.erase(i);
    }
}

std::vector<WidgetType*> LocalWidget::widgetTypes()
{
    return s_types;
}

LocalWidget* LocalWidget::createWidget(const QString& name)
{
    LocalWidget* result = nullptr;

    auto c = name.toStdString();
    int id = QMetaType::type(c.c_str());

    if(id != QMetaType::UnknownType)
    {
        LocalWidget* dock = reinterpret_cast<LocalWidget*>(QMetaType::create(id));

        if(dock)
        {
            result = dock;
        }
        else
        {
            std::cout << "Cannot create " << c << " class" << std::endl;
        }
    }
    else
    {
        std::cout << "Cannot find " << c << " class" << std::endl;
    }

    return result;
}

QString LocalWidget::createObjectName(const QString& typeName)
{
    QString result;
    std::vector<QString> names;

    for(auto w : s_widgets)
    {
        QString n = w->objectName();
        int x = QString::compare(n.left(typeName.length()), typeName, Qt::CaseInsensitive);

        if(x == 0)
        {
            names.push_back(n);
        }
    }

    int count = 0;

    result = typeName + QString::number(count++);

    while(std::find(names.begin(), names.end(), result) != names.end())
    {
        result = typeName + QString::number(count++);
    }

    return result;
}

WidgetType* LocalWidget::type() const
{
    return _type;
}

void LocalWidget::setType(WidgetType* type)
{
    _type = type;
}
