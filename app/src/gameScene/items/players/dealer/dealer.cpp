#include "dealer.h"
#include "items/labels/pointLabel/pointlabel.h"
#include "model/items/players/iplayer.h"

#include <QGraphicsScene>
#include <QPainter>

namespace Scene
{
Dealer::Dealer(Model::IPlayer *modelDealer)
    : _modelDealer{ modelDealer }, _pointLabel{ new PointLabel(0) }
{
}

QRectF Dealer::boundingRect() const
{
    return QRectF(0, 0, 500, 200);
}

void Dealer::updateCards()
{
    int cardOffset{ 0 };
    const int stepOffset{ 30 };

    int zValue{ 0 };
    for (auto *card : _cards)
    {
        if (card != _cards.front())
            dynamic_cast<ICard *>(card)->open();

        card->setParentItem(this);
        card->setPos(_cardStart.x() + cardOffset, _cardStart.y());
        card->setZValue(zValue++);
        cardOffset += stepOffset;
    }
}

void Dealer::addCard(QGraphicsItem *card)
{
    _cards.push_back(card);
}

unsigned Dealer::modelId() const
{
    return _modelDealer->id();
}

void Dealer::init()
{
    QPointF dealerPos{ scene()->sceneRect().center().x() - 250,
                       scene()->sceneRect().center().y() - 300 };
    setPos(dealerPos);
}

void Dealer::setupPointLabel()
{
    scene()->addItem(_pointLabel);
    _pointLabel->setParentItem(this);
    QPointF labelPos{ (boundingRect().width() - _pointLabel->boundingRect().width()) / 2,
                      boundingRect().bottom() };
    _pointLabel->setPos(labelPos);
}

void Dealer::updatePointLabel()
{
    _pointLabel->updateText(_modelDealer->score());
}

Result Dealer::result() const
{
    return _modelDealer->isLoser() ? Result::LOSER : Result::WINNER;
}

QPointF Dealer::cardStart()
{
    const int stepOffset{ 30 };
    const unsigned long startPointOffset{ (_cards.size() - 1) * stepOffset / 2 };

    QSizeF cardsSize{ _cards.front()->boundingRect().width(),
                      _cards.front()->boundingRect().height() };
    _cardStart = QPointF{ (boundingRect().width() - cardsSize.width()) / 2 - startPointOffset,
                          (boundingRect().height() - cardsSize.height()) / 2 };

    return mapToScene(_cardStart);
}

void Dealer::clearCards()
{
    _cards.clear();
}

void Dealer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}
} // namespace Scene
