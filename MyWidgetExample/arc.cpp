#include "arc.h"
#include "arcpointf.h"

Arc::Arc(qreal thickness, qreal startAngle, qreal endAngle, const QColor& startColour, const QColor& endColour)
{
    _sweepAngle = startAngle < endAngle ? endAngle - startAngle : startAngle - endAngle;
    _thickness = thickness;

    _startAngle = 90.0 - startAngle;
    _endAngle = 90.0 - endAngle;

    _startColour = startColour;
    _endColour = endColour;
}

void Arc::draw(QPainter &painter, Square* square)
{
    auto c = square->center();

    ArcPointF outer1(c, square->radius(), _startAngle);
    ArcPointF outer2(c, square->radius(), _endAngle);
    ArcPointF inner1(c, square->radius() - _thickness, _startAngle);
    ArcPointF inner2(c, square->radius() - _thickness, _endAngle);
    QPainterPath path;

    path.moveTo(outer1);
    path.arcTo(QRectF(square->x(), square->y(), square->width(), square->height()), _startAngle, -_sweepAngle);
    path.lineTo(inner2);
    path.arcTo(QRectF(square->x() + _thickness, square->y() + _thickness, square->width() - _thickness * 2.0, square->height() - _thickness * 2.0), _endAngle, _sweepAngle);
    path.lineTo(outer1);

    QConicalGradient gradient;

    gradient.setCenter(c);
    gradient.setAngle(_endAngle);
    gradient.setColorAt(0, _endColour);
    gradient.setColorAt(_sweepAngle / 360.0, _startColour);

    QBrush brush(gradient);

    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawPath(path);

    square->adjust(-_thickness);
}
