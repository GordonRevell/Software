#include "scale.h"

#include "arcpointf.h"

Scale::Scale(QObject *parent) : QObject(parent)
{
}

int Scale::majorDivisions() const
{
    return _majorDivisions;
}

void Scale::setMajorDivisions(int divisions)
{
    _minorDivisions = divisions;
}

int Scale::minorDivisions() const
{
    return _minorDivisions;
}

void Scale::setMinorDivisions(int divisions)
{
    _majorDivisions = divisions;
}

qreal Scale::majorTickWidth() const
{
    return _majorTickWidth;
}

void Scale::setMajorTickWidth(const qreal &majorTickWidth)
{
    _majorTickWidth = majorTickWidth;
}

qreal Scale::majorTickLength() const
{
    return _majorTickLength;
}

void Scale::setMajorTickLength(const qreal &majorTickLength)
{
    _majorTickLength = majorTickLength;
}

void Scale::draw(QPainter &painter, Square* square, qreal startAngle, qreal endAngle)
{
    qreal angle = startAngle;
    qreal inc = (endAngle - startAngle) / _majorDivisions;

    painter.setPen(QPen(QBrush(Qt::white), _majorTickWidth, Qt::SolidLine));

    for(int i = 0; i < _majorDivisions; i++)
    {
        ArcPointF outer(square->center(), square->radius(), 90 - angle);
        ArcPointF inner(square->center(), square->radius() - _majorTickLength, 90 - angle);

        painter.drawLine(outer, inner);

        for(int j = 1; j <= _minorDivisions; j++)
        {
            qreal a = angle + j * inc / _minorDivisions;

            ArcPointF outer(square->center(), square->radius(), 90 - a);
            ArcPointF inner(square->center(), square->radius() - _majorTickLength / 2, 90 - a);

            painter.drawLine(outer, inner);

        }

        angle += inc;
    }

    ArcPointF outer(square->center(), square->radius(), 90 - angle);
    ArcPointF inner(square->center(), square->radius() - _majorTickLength, 90 - angle);

    painter.drawLine(outer, inner);
}

