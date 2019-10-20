#ifndef DIALWIDGET_H
#define DIALWIDGET_H

#include "localwidget.h"

class DialWidget : public LocalWidget
{
    Q_OBJECT

public:
    DialWidget(QWidget *parent = nullptr);

private:
    static bool s_registered;
};

#endif // DIALWIDGET_H
