#ifndef DIAL_H
#define DIAL_H

#include "square.h"
#include "scale.h"

#include <QObject>
#include <QPainter>

class Dial : public QObject
{
    Q_OBJECT

    Square* _square;

public:
    explicit Dial(const Square& square, QObject *parent = nullptr);

    qreal borderWidth() const;
    void setBorderWidth(const qreal &borderWidth);

signals:

public slots:

public:
    void draw(QPainter& painter);

    Scale& scale();

private:
    void drawArc(QPainter& painter, Square* rect);
    void drawBorder(QPainter& painter, Square* rect, qreal width);

    qreal _borderWidth = 3;
    Scale _scale;
};

#endif // DIAL_H
