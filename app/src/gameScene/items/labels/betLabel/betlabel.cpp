#include "betlabel.h"

#include <QPainter>

namespace Scene
{
BetLabel::BetLabel(int value) : _value{ value }
{
}

void BetLabel::updateText(int value)
{
    _value = value;
}

QRectF BetLabel::boundingRect() const
{
    return QRectF(0, 0, 60, 20);
}

void BetLabel::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *widget)
{
    const int penWidth{ 1 };
    const int cornerRadius{ 5 };
    QRect rect{ boundingRect().toRect() };
    QRect borderRect{ QRect{ rect.x() + penWidth, rect.y() + penWidth, rect.width() - penWidth * 2,
                             rect.height() - penWidth * 2 } };

    QPen pen(Qt::white);
    QFont font("serif", 14, 60);

    std::string text{ "$" + std::to_string(_value) };

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::white);
    painter->setBrush(Qt::black);
    painter->drawRoundedRect(borderRect, cornerRadius, cornerRadius);
    painter->setFont(font);
    painter->setPen(pen);
    painter->drawText(borderRect, Qt::AlignCenter, QString::fromStdString(text));
}
} // namespace Scene
