#include "dealer.h"
#include "items/labels/pointLabel/pointlabel.h"
#include "model/items/players/iplayer.h"

#include <QGraphicsScene>
#include <QPainter>

namespace Scene
{
Dealer::Dealer(Model::IPlayer *modelDealer)
    : Player{ modelDealer }, _modelDealer{ modelDealer }, _pointLabel{ new PointLabel(0) }
{
}

void Dealer::updateCards()
{
    int cardOffset{ 0 };
    const int stepOffset{ 30 };

    int zValue{ 0 };
    for (auto *card : cards())
    {
        if (card != cards().front())
            dynamic_cast<ICard *>(card)->open();

        card->setParentItem(this);
        card->setPos(_cardPoint.x() + cardOffset, _cardPoint.y());
        card->setZValue(zValue++);
        cardOffset += stepOffset;
    }
}

void Dealer::setupPointLabel()
{
    scene()->addItem(_pointLabel);
    _pointLabel->setParentItem(this);
    QPointF labelPos{ (boundingRect().width() - _pointLabel->boundingRect().width()) / 2,
                      boundingRect().bottom() };
    _pointLabel->setPos(labelPos);
}

void Dealer::init()
{
    QPointF dealerPos{ scene()->sceneRect().center().x() - 250,
                       scene()->sceneRect().center().y() - 300 };
    setPos(dealerPos);
}
int Dealer::showClosedCard()
{
    ICard *card{ dynamic_cast<ICard *>(cards().front()) };
    card->open();

    return card->modelId();
}

int Dealer::currentScore()
{
    return _modelDealer->score();
}
} // namespace Scene
