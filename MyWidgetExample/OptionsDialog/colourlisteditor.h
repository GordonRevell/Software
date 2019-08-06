#ifndef COLOURLISTEDITOR_H
#define COLOURLISTEDITOR_H

#include <QComboBox>

class ColourListEditor : public QComboBox
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor USER true)

public:
    ColourListEditor(QWidget* widget = nullptr);

public:
    QColor color() const;
    void setColor(QColor c);

private:
    void populateList();
};

#endif // COLOURLISTEDITOR_H
