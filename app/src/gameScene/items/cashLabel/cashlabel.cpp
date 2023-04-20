#include "cashlabel.h"
#include "items/players/iplayer.h"

#include <QPainter>

namespace Scene
{
CashLabel::CashLabel(IPlayer *player) : _player{ player }
{
    updateContent();
}

QRectF CashLabel::boundingRect() const
{
    return QRectF(0, 0, 100, 50);
}

void CashLabel::updateContent()
{
    _cash = _player->cash();
    _bet = _player->bet();
    update();
}

void CashLabel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const int penWidth{ 1 };
    const int cornerRadius{ 5 };
    QRect rect{ boundingRect().toRect() };
    QRect borderRect{ QRect{ rect.x() + penWidth, rect.y() + penWidth, rect.width() - penWidth * 2,
                             rect.height() - penWidth * 2 } };

    QPen pen(Qt::white);
    QFont font("serif", 16, 60);

    std::string cashLabel{ "Cash: $" + std::to_string(_cash) };
    std::string betLabel{ "Bet: $" + std::to_string(_bet) };

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::black);
    painter->drawRoundedRect(borderRect, cornerRadius, cornerRadius);
    painter->setFont(font);
    painter->setPen(pen);
    painter->drawText(borderRect, Qt::AlignTop | Qt::AlignHCenter,
                      QString::fromStdString(cashLabel));
    painter->drawText(borderRect, Qt::AlignBottom | Qt::AlignHCenter,
                      QString::fromStdString(betLabel));
}
} // namespace Scene
