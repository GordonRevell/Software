#include "mydelegate.h"
#include "colourlisteditor.h"

#include <QSize>
#include <QSpinBox>
#include <QComboBox>
#include <QPainter>

namespace Gordon
{
    MyDelegate::MyDelegate(QObject *parent) : QStyledItemDelegate(parent)
    {
        QStringList colorNames = QColor::colorNames();

        for(auto n : colorNames)
        {
        }
    }

    QWidget* MyDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
    {
        QWidget* result = QStyledItemDelegate::createEditor(parent, option, index);

        if(index.column() > 0)
        {
            if(index.row() < 3)
            {
                QSpinBox* editor = new QSpinBox(parent);

                editor->setMinimum(0);
                editor->setMaximum(100);

                result = editor;
            }
            else
            {
                ColourListEditor* editor = new ColourListEditor(parent);

                result = editor;
            }
        }

        return result;
    }

    void MyDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
    {
        if(QSpinBox* edit = qobject_cast<QSpinBox*>(editor))
        {
            edit->setValue(index.model()->data(index, Qt::EditRole).toInt());
        }
        else if(ColourListEditor* edit = qobject_cast<ColourListEditor*>(editor))
        {
            edit->setColor(index.model()->data(index, Qt::EditRole).value<QColor>());
        }
        else
        {
        }
    }

    void MyDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
    {
        if(QSpinBox* edit = qobject_cast<QSpinBox*>(editor))
        {
            edit->interpretText();
            model->setData(index, edit->value(), Qt::EditRole);
        }
        else if(ColourListEditor* edit = qobject_cast<ColourListEditor*>(editor))
        {
            model->setData(index, edit->color().name(), Qt::DisplayRole);
            model->setData(index, edit->color(), Qt::EditRole);
            model->setData(index, edit->color(), Qt::DecorationRole);
        }
        else
        {
        }
    }

    void MyDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex&) const
    {
        editor->setGeometry(option.rect);
    }

    void MyDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
    {
        QStyledItemDelegate::paint(painter, option, index);
    }

    void MyDelegate::drawDecoration(QPainter* painter, const QStyleOptionViewItem& option, const QRect& rect, const QPixmap& pixmap) const
    {
        painter->save();

        painter->setBrush(QBrush(Qt::red));
        painter->drawRect(rect);

        painter->restore();
    }
}
