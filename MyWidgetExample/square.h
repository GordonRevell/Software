#ifndef SQUARE_H
#define SQUARE_H

#include <QRectF>

class Square : public QRectF
{
public:
    Square(QRect rect) : Square(rect, 1.0)
    {
    }

    Square(QRect rect, qreal margin)
    {
        QRectF r(rect);

        if (r.width() > r.height())
        {
            qreal a = (r.width() - r.height()) / 2.0;

            r.adjust(margin + a, margin, -margin - a, -margin);
        }
        else
        {
            qreal a = (r.height() - r.width()) / 2.0;

            r.adjust(margin, margin + a, -margin, -margin - a);
        }

        setRect(r.x(), r.y(), r.width(), r.height());
    }

    qreal radius()
    {
        return width() / 2.0;
    }

    void adjust(qreal delta)
    {
        QRectF::adjust(-delta, -delta, delta, delta);
    }

    Square& operator= (const Square& s)
    {
        setRect(s.x(), s.y(), s.width(), s.height());

        return *this;
    }
};

#endif // SQUARE_H
