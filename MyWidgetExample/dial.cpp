#include "dial.h"
#include "arc.h"
#include "arcpointf.h"

qreal Dial::borderWidth() const
{
    return _borderWidth;
}

void Dial::setBorderWidth(const qreal &borderWidth)
{
    _borderWidth = borderWidth;
}

Dial::Dial(const Square& square, QObject *parent) : QObject(parent)
{
    _square = new Square(square);
}

void Dial::drawArc(QPainter& painter, Square* rect)
{
    Arc a(6, -135.0, 135.0, Qt::green, Qt::red);

    a.draw(painter, rect);
}

void Dial::drawBorder(QPainter& painter, Square* square, qreal width)
{
    qreal d1 = square->width() / 2.0;
    qreal d2 = d1 - width;
    qreal d3 = d2 - width;

    QPainterPath p;

    p.addEllipse(square->center(), d1, d1);
    p.addEllipse(square->center(), d2, d2);

    QLinearGradient g(QPointF(0, square->top()), QPointF(0, square->bottom()));

    g.setColorAt(0, Qt::white);
    g.setColorAt(1, Qt::black);

    QBrush b(g);

    painter.fillPath(p, b);

    QPainterPath p2;

    p2.addEllipse(square->center(), d2, d2);
    p2.addEllipse(square->center(), d3, d3);

    QLinearGradient g1(QPointF(0, square->top()), QPointF(0, square->bottom()));

    g1.setColorAt(0, Qt::black);
    g1.setColorAt(1, Qt::white);

    QBrush b1(g1);

    painter.fillPath(p2, b1);

    QPainterPath p3;

    p3.addEllipse(square->center(), d3, d3);
    painter.fillPath(p3, b);

    square->adjust(-width * 2.0);
}

Scale& Dial::scale()
{
    return _scale;
}

void Dial::draw(QPainter &painter)
{
    drawBorder(painter, _square, 3);

    _square->adjust(-5);

    drawArc(painter, _square);

    _square->adjust(-2);

    _scale.draw(painter, _square, -135, 135);
}
