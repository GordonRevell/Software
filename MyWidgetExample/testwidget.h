#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include "square.h"

#include <QObject>
#include <QWidget>

class TestWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TestWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event);

signals:

public slots:
};

#endif // TESTWIDGET_H
