#include "player.h"
#include "items/labels/pointLabel/pointlabel.h"
#include "model/items/players/iplayer.h"

#include <QGraphicsScene>
#include <QPainter>

namespace Scene
{
Player::Player(Model::IPlayer *modelPlayer)
    : _modelPlayer{ modelPlayer }, _pointLabel{ new PointLabel(0) }
{
}

QRectF Player::boundingRect() const
{
    return QRectF(0, 0, 500, 200);
}

void Player::updateCardsPos()
{
    int cardOffset{ 0 };
    const int stepOffset{ 30 };

    int zValue{ 0 };
    for (auto *card : _cards)
    {
        card->setParentItem(this);
        card->setPos(_cardStart.x() + cardOffset, _cardStart.y());
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
}

void Player::init()
{
    QPointF playerPos{ scene()->sceneRect().center().x() - 250,
                       scene()->sceneRect().center().y() + 100 };
    setPos(playerPos);
}

void Player::setupPointLabel()
{
    scene()->addItem(_pointLabel);
    _pointLabel->setParentItem(this);
    QPointF labelPos{ (boundingRect().width() - _pointLabel->boundingRect().width()) / 2,
                      boundingRect().top() - 20 };
    _pointLabel->setPos(labelPos);
}

void Player::updatePointLabel()
{
    _pointLabel->updateText(_modelPlayer->score());
}

QPointF Player::cardStart()
{
    const int stepOffset{ 30 };
    const unsigned long startPointOffset{ (_cards.size() - 1) * stepOffset / 2 };

    QSizeF cardsSize{ _cards.front()->boundingRect().width(),
                      _cards.front()->boundingRect().height() };
    _cardStart = QPointF{ (boundingRect().width() - cardsSize.width()) / 2 - startPointOffset,
                          (boundingRect().height() - cardsSize.height()) / 2 };

    return mapToScene(_cardStart);
}
} // namespace Scene
