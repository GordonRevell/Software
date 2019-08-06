#ifndef GISMO_H
#define GISMO_H

#include <QObject>

class Gismo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Gismo* parent READ parent WRITE setParent)
    Q_PROPERTY(QString name READ name WRITE setName)

public:
    explicit Gismo(QObject* parent = nullptr);
    virtual ~Gismo();

    Gismo* parent() const;
    void setParent(Gismo* parent);

    QString name() const;
    void setName(const QString &name);

    QString path();

signals:

public slots:

private:
    Gismo* _parent = nullptr;
    QString _name = "";
};

#endif // GISMO_H
