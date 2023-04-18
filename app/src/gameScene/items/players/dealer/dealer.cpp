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
    const int penWidth{ 1 };
    const int cornerRadius{ 5 };
    QRect rect{ boundingRect().toRect() };
    QRect borderRect{ QRect{ rect.x() + penWidth, rect.y() + penWidth, rect.width() - penWidth * 2,
                             rect.height() - penWidth * 2 } };

    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawRoundedRect(borderRect, cornerRadius, cornerRadius);
}
} // namespace Scene
