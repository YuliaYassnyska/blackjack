#include "themeitem.h"

#include <QPainter>

namespace Scene
{
ThemeItem::ThemeItem(const QString &text, std::function<void()> callback)
    : _text{ text }, _callback{ callback }
{
    setFlag(GraphicsItemFlag::ItemIsSelectable);
}

QRectF ThemeItem::boundingRect() const
{
    return QRectF(0, 0, 100, 50);
}

void ThemeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const int penWidth{ 1 };
    const int cornerRadius{ 5 };
    QRect rect{ boundingRect().toRect() };
    QRect borderRect{ QRect{ rect.x() + penWidth, rect.y() + penWidth, rect.width() - penWidth * 2,
                             rect.height() - penWidth * 2 } };

    QPen pen(Qt::white);
    QFont font("Serif", 16, 60);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);
    painter->setBrush(Qt::black);
    painter->drawRoundedRect(borderRect, cornerRadius, cornerRadius);
    painter->setFont(font);
    painter->setPen(pen);
    painter->drawText(borderRect, Qt::AlignCenter, _text);
}

void ThemeItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    _callback();
}
} // namespace Scene
