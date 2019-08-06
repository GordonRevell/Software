#ifndef SCALE_H
#define SCALE_H

#include "square.h"

#include <QObject>
#include <QPainter>

class Scale : public QObject
{
    Q_OBJECT

    Q_PROPERTY(qreal majorDivisions MEMBER _majorDivisions READ majorDivisions WRITE setMajorDivisions)
    Q_PROPERTY(qreal minorDivisions MEMBER _mminorDivisions READ minorDivisions WRITE setMinorDivisions)

    Q_PROPERTY(qreal majorTickWidth MEMBER _majorTickWidth READ majorTickWidth WRITE setMajorTickWidth)
    Q_PROPERTY(qreal majorTickLength MEMBER _majorTickLength READ majorTickLength WRITE setMajorTickLength)

    int _majorDivisions = 10;
    int _minorDivisions = 5;

    qreal _majorTickWidth = 2;
    qreal _majorTickLength = 10;

public:
    explicit Scale(QObject *parent = nullptr);

    int majorDivisions() const;
    void setMajorDivisions(int divisions);
    int minorDivisions() const;
    void setMinorDivisions(int divisions);

    qreal majorTickWidth() const;
    void setMajorTickWidth(const qreal &majorTickWidth);
    qreal majorTickLength() const;
    void setMajorTickLength(const qreal &majorTickLength);

    void draw(QPainter& painter, Square* square, qreal startAngle, qreal endAngle);

signals:

public slots:
};

#endif // SCALE_H
