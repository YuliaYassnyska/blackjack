#include "player.h"
#include "model/items/players/iplayer.h"

#include <QGraphicsScene>
#include <QPainter>

namespace Scene
{
Player::Player(Model::IPlayer *modelPlayer) : _modelPlayer{ modelPlayer }
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

unsigned Player::modelId() const
{
    return _modelPlayer->id();
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

void Player::init()
{
    QPointF playerPos{ scene()->sceneRect().center().x() - 250,
                       scene()->sceneRect().center().y() + 100 };
    setPos(playerPos);
}
} // namespace Scene
