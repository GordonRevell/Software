#ifndef DIALWIDGET_H
#define DIALWIDGET_H

#include "localwidget.h"

class DialWidget : public LocalWidget
{
    Q_OBJECT

public:
    DialWidget(QWidget *parent = nullptr);

    DialWidget(const DialWidget& w);

private:
    static bool s_registered;

    static bool registerType(QString name);
};

Q_DECLARE_METATYPE(DialWidget)

#endif // DIALWIDGET_H
