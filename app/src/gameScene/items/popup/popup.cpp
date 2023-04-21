#include "popup.h"
#include "items/buttonItem/buttonitem.h"

#include <QGraphicsScene>
#include <QPainter>

namespace Scene
{
Popup::Popup(std::function<void()> callback, const QString &imagePath)
    : _restartButton{ new ButtonItem(imagePath, callback) }
{
    hide();
    setZValue(200);
}

QRectF Popup::boundingRect() const
{
    return QRectF(0, 0, 950, 600);
}

void Popup::updateText(QString text)
{
    _text = text;
}

void Popup::setupContent()
{
    scene()->addItem(_restartButton);
    _restartButton->setParentItem(this);
    QPointF buttonPos{ (boundingRect().width() - _restartButton->boundingRect().width()) / 2,
                       (boundingRect().height() - _restartButton->boundingRect().height()) / 2
                           + 100 };
    _restartButton->setPos(buttonPos);
}

void Popup::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const int penWidth{ 1 };
    const int cornerRadius{ 5 };
    QRect rect{ boundingRect().toRect() };
    QRect borderRect{ QRect{ rect.x() + penWidth, rect.y() + penWidth, rect.width() - penWidth * 2,
                             rect.height() - penWidth * 2 } };

    QPen pen(Qt::white);
    QFont font("serif", 40, 60);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->setOpacity(0.7);
    painter->drawRoundedRect(borderRect, cornerRadius, cornerRadius);
    painter->setOpacity(1);
    painter->setFont(font);
    painter->setPen(pen);
    painter->drawText(borderRect, Qt::AlignCenter, _text);
}
} // namespace Scene
