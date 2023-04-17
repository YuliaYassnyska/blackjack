#include "pointlabel.h"

#include <QPainter>

namespace Scene
{
PointLabel::PointLabel(int value) : _value{ value }
{
}

void PointLabel::updateText(int value)
{
    _value = value;
}

QRectF PointLabel::boundingRect() const
{
    return QRectF(0, 0, 40, 20);
}

void PointLabel::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *widget)
{
    const int penWidth{ 1 };
    const int cornerRadius{ 5 };
    QRect rect{ boundingRect().toRect() };
    QRect borderRect{ QRect{ rect.x() + penWidth, rect.y() + penWidth, rect.width() - penWidth * 2,
                             rect.height() - penWidth * 2 } };

    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawRoundedRect(borderRect, cornerRadius, cornerRadius);
    QPen pen(Qt::white);
    QFont font("serif", 14, 60);
    painter->setFont(font);
    painter->setPen(pen);
    painter->drawText(borderRect, Qt::AlignCenter, QString(_value));
}
} // namespace Scene
