#ifndef LOCALWIDGET_H
#define LOCALWIDGET_H

#include <QDockWidget>

#include <iostream>

class LocalWidget : public QDockWidget
{
    Q_OBJECT

public:
    LocalWidget(QWidget *parent = nullptr);
    LocalWidget(const LocalWidget& w);

    template<typename T> static bool registerType(QString name)
    {
        auto c = name.toStdString();
        int id = qRegisterMetaType<T>(c.c_str());

        s_idList.push_back(id);

        return (id != QMetaType::UnknownType);
    }

    static QDockWidget* createLocalWidget(QString name)
    {
        QDockWidget* result = nullptr;

        auto c = name.toStdString();
        int id = QMetaType::type(c.c_str());

        if(id != QMetaType::UnknownType)
        {
            auto dock = reinterpret_cast<QDockWidget*>(QMetaType::create(id));

            if(dock)
            {
                QString objectName = dock->metaObject()->className() + QString::number(s_count++);

                dock->setObjectName(objectName);

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

private:
    static unsigned int s_count;
    static std::vector<int> s_idList;

};

#endif // LOCALWIDGET_H
