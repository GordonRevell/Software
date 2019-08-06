#ifndef ARCPOINTF_H
#define ARCPOINTF_H

#include "square.h"

#include <QPointF>
#include <QtMath>

#include <math.h>

class ArcPointF : public QPointF
{
public:
    ArcPointF() : QPointF()
    {
    }

    ArcPointF(const QPoint &point) : QPointF(point)
    {
    }

    ArcPointF(qreal xpos, qreal ypos) : QPointF(xpos, ypos)
    {
    }

    ArcPointF(const QPointF& center, qreal radius, qreal angle) : ArcPointF()
    {
        double dy = sin(double(angle) * M_PI / 180.0) * radius;
        double dx = cos(double(angle) * M_PI / 180.0) * radius;

        setX(center.x() + dx);
        setY(center.y() - dy);
    }
};

#endif // ARCPOINTF_H
