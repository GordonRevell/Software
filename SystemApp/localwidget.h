#ifndef LOCALWIDGET_H
#define LOCALWIDGET_H

#include <QDockWidget>

class LocalWidget : public QDockWidget
{
    Q_OBJECT

public:
    LocalWidget(QWidget *parent = nullptr);
    LocalWidget(const LocalWidget& w);
};

#endif // LOCALWIDGET_H
