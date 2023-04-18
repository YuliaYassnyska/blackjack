#include "dealer.h"
#include "model/items/players/iplayer.h"

#include <QGraphicsScene>
#include <QPainter>

namespace Scene
{
Dealer::Dealer(Model::IPlayer *modelDealer) : _modelDealer{ modelDealer }
{
}

QRectF Dealer::boundingRect() const
{
    return QRectF(0, 0, 500, 200);
}

void Dealer::updateCardsPos()
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

void Dealer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}
} // namespace Scene
