#ifndef MYDELEGATE_H
#define MYDELEGATE_H

#include <QStyledItemDelegate>
#include <QModelIndex>
#include <QObject>

namespace Gordon
{
    class MyDelegate : public QStyledItemDelegate
    {
        Q_OBJECT

    public:
        MyDelegate(QObject *parent = nullptr);

        QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
        void setEditorData(QWidget* editor, const QModelIndex& index) const override;
        void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const override;
        void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex&) const override;

        void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
        void drawDecoration(QPainter *painter, const QStyleOptionViewItem &option, const QRect &rect, const QPixmap &pixmap) const;
    signals:

    public slots:

    };
}

#endif // MYDELEGATE_H
