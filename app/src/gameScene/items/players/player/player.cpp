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

void Player::updateCards()
{
    int cardOffset{ 0 };
    const int stepOffset{ 30 };

    int zValue{ 0 };
    for (auto *card : _cards)
    {
        dynamic_cast<ICard *>(card)->open();
        card->setParentItem(this);
        card->setPos(_cardPoint.x() + cardOffset, _cardPoint.y());
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

Result Player::result() const
{
    return _modelPlayer->isLoser() ? Result::LOSER : Result::WINNER;
}

QPointF Player::cardStart()
{
    const int stepOffset{ 30 };
    const double startPointOffset{ (_cards.size() - 1) * stepOffset / 2.0 };

    QSizeF cardsSize{ _cards.front()->boundingRect().width(),
                      _cards.front()->boundingRect().height() };
    _cardPoint = QPointF{ (boundingRect().width() - cardsSize.width()) / 2 - startPointOffset,
                          (boundingRect().height() - cardsSize.height()) / 2 };

    return mapToScene(_cardPoint);
}

void Player::clearCards()
{
    for (auto card : _cards)
        card->setParentItem(nullptr);
    _cards.clear();
}

int Player::cardsSize() const
{
    return _cards.size();
}

int Player::cash() const
{
    return _modelPlayer->cash();
}

int Player::bet() const
{
    return _modelPlayer->bet();
}

std::vector<QGraphicsItem *> Player::cards() const
{
    return _cards;
}

void Player::resetCash()
{
    _modelPlayer->resetCash();
}
} // namespace Scene
