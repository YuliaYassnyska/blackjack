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
    const int stepOffset{ 20 };
    const unsigned long startPointOffset{ (_cards.size() - 1) * stepOffset / 2 };

    QSizeF cardsSize{ _cards.front()->boundingRect().width(),
                      _cards.front()->boundingRect().height() };
    QPointF cardStart{ QPointF{ (boundingRect().width() - cardsSize.width()) / 2 - startPointOffset,
                                (boundingRect().height() - cardsSize.height()) / 2 } };

    int zValue{ 0 };
    for (auto *card : _cards)
    {
        card->setParentItem(this);
        card->setPos(cardStart.x() + cardOffset, cardStart.y());
        card->setZValue(zValue++);
        cardOffset += stepOffset;
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
