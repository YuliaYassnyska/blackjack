#include "dealer.h"

#include <QPainter>

namespace Scene
{
Dealer::Dealer()
{
}

QRectF Dealer::boundingRect() const
{
    return QRectF(0, 0, 500, 200);
}

void Dealer::updateCardsPos()
{
}

void Dealer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const int penWidth{ 1 };
    const int cornerRadius{ 5 };
    QRect rect{ boundingRect().toRect() };
    QRect borderRect{ QRect{ rect.x() + penWidth, rect.y() + penWidth, rect.width() - penWidth * 2,
                             rect.height() - penWidth * 2 } };

    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawRoundedRect(borderRect, cornerRadius, cornerRadius);
}
} // namespace Scene
