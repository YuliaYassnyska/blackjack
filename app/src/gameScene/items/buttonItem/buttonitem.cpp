#include "buttonitem.h"

#include <QPainter>

namespace Scene
{
ButtonItem::ButtonItem(const QString &imagePath, std::function<void(void)> callback)
    : _image{ QPixmap(imagePath).scaled(boundingRect().size().toSize()) }, _callback{ callback }
{
}

QRectF ButtonItem::boundingRect() const
{
    return QRectF(0, 0, 70, 70);
}

void ButtonItem::paint(QPainter *painter, const QStyleOptionGraphicsItem * /*option*/,
                       QWidget *widget)
{
    const int penWidth{ 1 };
    const int cornerRadius{ 50 };
    QRect rect{ boundingRect().toRect() };
    QRect borderRect{ QRect{ rect.x() + penWidth, rect.y() + penWidth, rect.width() - penWidth * 2,
                             rect.height() - penWidth * 2 } };

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setBackgroundMode(Qt::BGMode::OpaqueMode);
    painter->setBackground(Qt::white);
    painter->setBrush(_image);
    painter->drawRoundedRect(borderRect, cornerRadius, cornerRadius);
}

void ButtonItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    _callback();
}

} // namespace Scene
