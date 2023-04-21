#include "dibitem.h"

#include <QPainter>

namespace Scene
{
DibItem::DibItem(const QString &imagePath)
    : _image{ QPixmap(imagePath).scaled(boundingRect().size().toSize()) }
{
}

QRectF DibItem::boundingRect() const
{
    return QRectF(0, 0, 70, 70);
}

void DibItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *widget)
{
    const int penWidth{ 1 };
    const int cornerRadius{ 50 };
    QRect rect{ boundingRect().toRect() };
    QRect borderRect{ QRect{ rect.x() + penWidth, rect.y() + penWidth, rect.width() - penWidth * 2,
                             rect.height() - penWidth * 2 } };

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::white);
    painter->setBackgroundMode(Qt::BGMode::OpaqueMode);
    painter->setBackground(Qt::white);
    painter->setBrush(_image);
    painter->drawRoundedRect(borderRect, cornerRadius, cornerRadius);
}
} // namespace Scene
