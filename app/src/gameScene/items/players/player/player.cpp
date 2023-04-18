#include "player.h"

#include <QPainter>

namespace Scene
{
Player::Player()
{
}

QRectF Player::boundingRect() const
{
    return QRectF(0, 0, 500, 200);
}

void Player::updateCardsPos()
{
    int cardOffset{ 0 };
    QSizeF cardsSize{ _cards.front()->boundingRect().width() + cardOffset,
                      _cards.front()->boundingRect().height() };
    QPointF cardStart{ boundingRect().width() - cardsSize.width() / 2,
                       boundingRect().height() - cardsSize.height() / 2 };

    for (auto *card : _cards)
    {
        cardOffset += 5;
    }
}

void Player::addCard(QGraphicsItem *card)
{
    _cards.push_back(card);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
