#ifndef ARC_H
#define ARC_H

#include "square.h"

#include <QRectF>
#include <QColor>
#include <QPainter>

class Arc
{
    qreal _startAngle;
    qreal _endAngle;

    qreal _sweepAngle;
    qreal _thickness;

    QColor _startColour;
    QColor _endColour;

public:
    Arc(qreal thickness, qreal startAngle, qreal endAngle, const QColor& startColour, const QColor& endColour);

    void draw(QPainter& painter, Square* square);
};

#endif // ARC_H
