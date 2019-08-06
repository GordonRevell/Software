#include "testwidget.h"
#include "dial.h"

#include <QPainter>
#include <QPen>

TestWidget::TestWidget(QWidget *parent) : QWidget(parent)
{
}

void TestWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    Square r(rect());
    Dial dial(r);

    dial.draw(painter);

    QWidget::paintEvent(event);
}
